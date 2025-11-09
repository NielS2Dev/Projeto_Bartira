#include <stdio.h>
#include <stdlib.h> // Para system() e rand()
#include <string.h> // Para sprintf
#include <time.h>
// #include <windows.h> <-- REMOVIDO
// #include <conio.h> <-- REMOVIDO
#include <unistd.h> // Para usleep() (necessário se o Sleep não for definido em outro lugar)

// *** NOTA DE COMPATIBILIDADE ***
// Para garantir a portabilidade, você deve incluir um arquivo de cabeçalho
// com as definições de compatibilidade, se não estiverem no main.c:
//
// #define Sleep(ms) usleep((ms) * 1000)
// #define getch getch_linux
// #define _getch getch_linux
//
// Para este arquivo, presumo que a definição de Sleep já está acessível.

#include "combate.h"
#include "playgame.h"
#include "cores.h"
#include "desenhos.h"
#include "pocao.h"
#include "log.h"
#include "monstro.h"

habilidade bancoDeSkills[4][3] = {
    {
        {"Esmagamento", 350, 450},
        {"Investida", 300, 500},
        {"Ruptura", 400, 600}
    },
    {
        {"Raio Arcana", 300, 350},
        {"Chama Eterna", 350, 550},
        {"Meteoro", 500, 700}
    },
    {
        {"Tiro Duplo", 320, 380},
        {"Flecha Perfurante", 320, 480},
        {"Tiro de Precisao", 450, 650}
    },
    {
        {"Toque Vazio", 380, 300},
        {"Pena Eletrica", 380, 420},
        {"Explosao Sagrada", 380, 580}
    }
};

void atribuirClasse(struct usuario *jogador, int idClasse) {
    int i;
    for (i = 0; i < 3; i++) {
        jogador->skills[i] = bancoDeSkills[idClasse][i];
    }
}

void lutar(struct usuario *heroi, int idMonstro) {

    monstros monstroAtual = listaDeMonstros[idMonstro];
    int vidaMonstroAtual = monstroAtual.vidaMonstros;

    printf("==================================================\n");
    printf("COMECOU A BATALHA CONTRA: %s\n", monstroAtual.nomeDosMonstros);
    printf("==================================================\n");

    printf("--------------------------------------------------\n");

    while (heroi->vidaAtual > 0 && vidaMonstroAtual > 0) {
        system("clear"); // ALTERADO: CLS -> clear

        switch (idMonstro) {
            case 0: // Assumindo que Cão Assassino é o ID 0
                desenharCaoAssassino();
                break;
            case 1: // Assumindo que Orc é o ID 1
                desenharOrc();
                break;
            case 2: // Assumindo que Esqueleto é o ID 2
                desenharEsqueleto();
                break;
            case 3: // Assumindo que Dragão Jovem é o ID 3
                desenharDragaoJovem();
                break;
            case 4: // Assumindo que Draconato é o ID 4
                desenharDraconato();
                break;
            default:
                printf("[Monstro ID %d não encontrado!]\n", idMonstro);
                break;
        }

        mudarCor(10);
        printf("VIDA DO HERÓI (%s): %d/%d\n", heroi->nick, heroi->vidaAtual, heroi->vidaMaxima);
        mudarCor(12);
        printf("VIDA DO MONSTRO (%s): %d/%d\n", monstroAtual.nomeDosMonstros, vidaMonstroAtual, monstroAtual.vidaMonstros);
        mudarCor(7);
        printf("--------------------------------------------------\n");

        printf("Escolha sua ação:\n");
        int i;
        for (i = 0; i < 3; i++) {
            printf("[%d] %s (Dano: %d - %d)\n",
                            i + 1,
                            heroi->skills[i].nome,
                            heroi->skills[i].danoMinimo,
                            heroi->skills[i].danoMaximo);
        }

        printf("[4] POÇÃO (Aumenta Vida, Ataque ou Defesa)\n");

        printf("[5] SAIR (Apenas para teste, remova depois)\n");
        printf("--------------------------------------------------\n");

        mudarCor(14);
        printf("Opcao: ");
        int escolha;
        scanf("%d", &escolha);
        limparBuffer();
        mudarCor(7);

        if (escolha >= 1 && escolha <= 3) {
            habilidade skill = heroi->skills[escolha - 1];
            int danoBruto = rand() % (skill.danoMaximo - skill.danoMinimo + 1) + skill.danoMinimo;
            int danoCausado = danoBruto - monstroAtual.defesaMonstros;
            if (danoCausado < 1) danoCausado = 1;

            mudarCor(11);
            printf("\n%s usou %s e causou %d de dano em %s!\n",
                            heroi->nick, skill.nome, danoCausado, monstroAtual.nomeDosMonstros);
            mudarCor(7);

            vidaMonstroAtual -= danoCausado;
            Sleep(200); // Sleep -> usleep(200 * 1000) (via macro)

            if (vidaMonstroAtual > 0) {
                int danoRecebido = monstroAtual.ataqueMonstros;

                danoRecebido -= heroi->defesa;
                if (danoRecebido < 1) danoRecebido = 1;

                mudarCor(4); // Cor Vermelha
                printf("%s atacou e você recebeu %d de dano!\n",
                monstroAtual.nomeDosMonstros, danoRecebido);
                mudarCor(7);

                heroi->vidaAtual -= danoRecebido;
                Sleep(200); // Sleep -> usleep(200 * 1000) (via macro)
            }

        } else if (escolha == 4) {
            menuPorcoes(heroi);
            continue;
        } else if (escolha == 5) {
            printf("Saindo do combate de teste.\n");
            break;
        } else {
            mudarCor(4);
            printf("Opção inválida. Tente novamente.\n");
            mudarCor(7);
            Sleep(100); // Sleep -> usleep(100 * 1000) (via macro)
        }
    }

    system("clear"); // ALTERADO: CLS -> clear
    printf("==================================================\n");
    char logMensagem[150];

    if (heroi->vidaAtual <= 0) {
        mudarCor(4);
        printf("VOCÊ FOI DERROTADO!\n");

        sprintf(logMensagem, "MORREU para o %s.", monstroAtual.nomeDosMonstros);
        salvarLogBatalha(heroi->nick, logMensagem);

        gameOver();
        desenvolvedores();
    } else if (vidaMonstroAtual <= 0) {
        mudarCor(10);
        venceu();
        printf("VITÓRIA! O %s foi derrotado!\n", monstroAtual.nomeDosMonstros);

        sprintf(logMensagem, "DERROTOU o %s. Vida restante: %d/%d.",
                        monstroAtual.nomeDosMonstros, heroi->vidaAtual, heroi->vidaMaxima);
        salvarLogBatalha(heroi->nick, logMensagem);

        Sleep(2000); // Sleep -> usleep(2000 * 1000) (via macro)
    }
    mudarCor(7);
    printf("=====================================================\n");
}
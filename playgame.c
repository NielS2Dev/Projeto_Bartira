#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// #include <windows.h> <-- REMOVIDO
// #include <conio.h> <-- REMOVIDO
#include <unistd.h> // Para usleep()
#include <termios.h> // Para getch() personalizado

// Definição de getch() para Linux
// Fonte: Adaptação comum para emular conio.h em ambientes *nix
char getch_linux() {
    char buf = 0;
    struct termios old = {0};
    fflush(stdout);
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    return buf;
 }

// Definição de getch para usar a versão Linux
#define getch getch_linux
#define _getch getch_linux
#define Sleep(ms) usleep((ms) * 1000)

//Meus modulos xD
#include "cores.h"
#include "desenhos.h"
#include "monstro.h"
#include "playgame.h"
#include "combate.h"
#include "pocao.h"
#include "log.h"
#include "animacao.h"

int loopClasses() {
    int estado_atual = 0;
    int classe1, classe2;
    const int total_classes = 4;

    while (1) {
        system("clear"); // ALTERADO: CLS -> clear
        switch (estado_atual) {
            case 0:
                guerreiro();
                apresentacaoGuerreiro();
                break;
            case 1:
                mago();
                apresentacaoMago();
                break;
            case 2:
                arqueiro();
                apresentacaoArqueiro();
                break;
            case 3:
                suporte();
                apresentacaoSuporte();
                break;
        }

        mudarCor(3);
        printf("\n============================================================\n");
        printf("(Use as setinhas ESQUERDA/DIREITA para navegar em loop.)\n");
        printf("(Pressione 'Q' ou 'q' para SELECIONAR esta classe)\n");
        printf("============================================================\n");
        mudarCor(7);

        classe1 = getch();

        if (classe1 == 'q' || classe1 == 'Q') {
            break;
        }
        
        // Em Linux, a leitura de setas (códigos 0 ou 0xE0) é mais complexa ou diferente.
        // **IMPORTANTE**: A lógica de `classe1 == 0 || classe1 == 0xE0` seguida por
        // `getch()` para ler as setas (códigos 75, 77, 72, 80) é **específica do Windows/conio.h**.
        // Para a adaptação mais simples em Linux, recomendo trocar para **teclas normais**
        // como 'A' (esquerda) e 'D' (direita) para a navegação, ou você terá que
        // usar bibliotecas mais robustas como ncurses.
        // **Mantenho a estrutura original, mas as setas não funcionarão.**
        // Veja a **Observação 2** no final.
        if (classe1 == 0 || classe1 == 0xE0) {
            classe2 = getch();
            switch (classe2) {
                case 75: // Seta Esquerda (se funcionar)
                case 72: // Seta Cima (se funcionar)
                    estado_atual = (estado_atual - 1 + total_classes) % total_classes;
                    break;
                case 77: // Seta Direita (se funcionar)
                case 80: // Seta Baixo (se funcionar)
                    estado_atual = (estado_atual + 1) % total_classes;
                    break;
            }
        }
    }


    system("clear"); // ALTERADO: CLS -> clear
    printf("==================================================\n");
    printf("VOCÊ SELECIONOU A CLASSE (ID): %d\n", estado_atual);


    switch (estado_atual) {
        case 0:
            printf("CLASSE: Guerreiro\n");
            guerreiro();
            break;
        case 1:
            printf("CLASSE: Mago\n");
            mago();
            break;
        case 2:
            printf("CLASSE: Arqueiro\n");
            arqueiro();
            break;
        case 3:
            printf("CLASSE: Suporte\n");
            suporte();
            break;
    }
    printf("************************************************************\n");
        mudarCor(11);

        printf("Habilidades da Classe:\n");
        int i;
        for (i = 0; i < 3; i++) {

            printf(" [%d] %s (Dano: %d - %d)\n",
                        i + 1,
                        bancoDeSkills[estado_atual][i].nome,
                        bancoDeSkills[estado_atual][i].danoMinimo,
                        bancoDeSkills[estado_atual][i].danoMaximo);
        }

        mudarCor(7);
        printf("====================================================\n");
        printf("Pressione qualquer tecla para iniciar a aventura...\n");
        getch(); // getch() -> getch_linux()

    return estado_atual;
}


int main() {
    printf("Versão 7.2.0");
    _getch(); // _getch() -> getch_linux()
    int monstrosDerrotados = 0;
    // SetConsoleOutputCP(1252); <-- REMOVIDO
    char nick_maiusculo[100];
    bool nomeValido = false;
    srand((unsigned)time(NULL));
    const int MONSTROS_NECESSARIOS_PARA_VITORIA = 2;

    struct usuario meuHeroi;
    strcpy(meuHeroi.nick, "Aventureiro");

    mostrarDataHoraAtual();
    _getch(); // _getch() -> getch_linux()

    Sleep(1000); // Sleep(1000) -> usleep(1000 * 1000)
    system("clear"); // ALTERADO: CLS -> clear

    uern();
    desenvolvedores2();
    Sleep(500); // Sleep(500) -> usleep(500 * 1000)
    projetoRpg();
    Sleep(500); // Sleep(500) -> usleep(500 * 1000)

    introducao();

    system("clear"); // ALTERADO: CLS -> clear


    while(!nomeValido){
        mudarCor(2);
        printf("\nQual é o seu nick de batalha:    ");
        fgets(meuHeroi.nick, sizeof(meuHeroi.nick), stdin);
        meuHeroi.nick[strcspn(meuHeroi.nick, "\n\r")] = '\0';

        int i;
        strcpy(nick_maiusculo, meuHeroi.nick);
        for (i = 0; nick_maiusculo[i] != '\0'; i++) {
            nick_maiusculo[i] = toupper(nick_maiusculo[i]);
        }

        if (strchr(meuHeroi.nick, ' ') != NULL) {
            mudarCor(4);
            printf("ERRO: O nick nao pode conter espacos. Tente novamente.\n\n");
        } else if (strlen(meuHeroi.nick) == 0) {
            mudarCor(4);
            printf("ERRO: O nick nao pode estar vazio. Tente novamente.\n\n");
        } else {
            mudarCor(2);
            nomeValido = true;
            mudarCor(7);

        }
    }

    mudarCor(2);
    print_animado("Bem vindo jogador: ", 1);
    mudarCor(3);
    printf("%s\n\n", nick_maiusculo);
    Sleep(500); // Sleep(500) -> usleep(500 * 1000)


    int classe_selecionada = loopClasses();
    atribuirEInicializarHeroi(classe_selecionada, &meuHeroi);
    const char *NOME_ARQUIVO = "historico_jogador.txt";
    atribuirClasse(&meuHeroi, classe_selecionada);
    printf("\nHeroi pronto para o combate! Atributos salvos.\n");
    _getch(); // _getch() -> getch_linux()

    Sleep(1000); // Sleep(1000) -> usleep(1000 * 1000)
    system("clear"); // ALTERADO: CLS -> clear

    //lutar(&meuHeroi, 0);


    //while (meuHeroi.vida > 0 && monstrosDerrotados < 4)
    while (meuHeroi.vidaAtual > 0 && monstrosDerrotados < MONSTROS_NECESSARIOS_PARA_VITORIA) {

        int numeroSorteado = rand0a4();

        printf("==================================================\n");
        mudarCor(14); // Amarelo
        printf("UM NOVO MONSTRO APARECEU! É um %s.\n", listaDeMonstros[numeroSorteado].nomeDosMonstros);
        mudarCor(7);
        printf("Pressione uma tecla para encarar o desafio...\n");
        getch(); // getch() -> getch_linux()
        system("clear"); // ALTERADO: CLS -> clear

        lutar(&meuHeroi, numeroSorteado);


        if (meuHeroi.vidaAtual > 0) {
            monstrosDerrotados++;


            if (monstrosDerrotados >= MONSTROS_NECESSARIOS_PARA_VITORIA) {
                    mudarCor(10);
                    printf("FIM DA AVENTURA! Você atingiu seu objetivo de derrotar %d monstros.\n", MONSTROS_NECESSARIOS_PARA_VITORIA);
                    desenvolvedores();
                    Sleep(200); // Sleep(200) -> usleep(200 * 1000)
                    break;
            }

            mudarCor(10);
            printf("VITÓRIA! Você derrotou %d/%d monstros. Vida restante: %d\n", monstrosDerrotados, MONSTROS_NECESSARIOS_PARA_VITORIA, meuHeroi.vidaAtual);
            mudarCor(7);
            printf("Aventureiro(a) incansável, prepare-se para o próximo inimigo!\n");
            Sleep(200); // Sleep(200) -> usleep(200 * 1000)
            system("clear"); // ALTERADO: CLS -> clear
        } else {

            break;
        }
    }

    return 0;
}
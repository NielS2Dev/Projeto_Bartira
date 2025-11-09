#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "pocao.h"
#include "playgame.h" 
#include "cores.h"    
#include "desenhos.h" 
#include "log.h"      

#define LIMITE_USO_PORCAO 2


porcao listaPorcoes[] = {
    {"Poção do Elan Vital", 600, 0, 0},
    {"Poção de Força Extrema", 0, 400, 0},
    {"Elixir de Defesa Sólida", 0, 0, 200},
    {"Poção Completa", 300, 200, 100}
};


const int NUM_PORCOES = sizeof(listaPorcoes) / sizeof(listaPorcoes[0]);


void aplicarPorcao(struct usuario *heroi, int idPorcao) {
    porcao p = listaPorcoes[idPorcao];
    
    if (p.aumentoVida > 0) {
        int vidaAnterior = heroi->vidaAtual;
        heroi->vidaAtual += p.aumentoVida;
        if (heroi->vidaAtual > heroi->vidaMaxima) {
            heroi->vidaAtual = heroi->vidaMaxima;
        }
        printf("\n[ITEM] %s restaurou %d de VIDA! (Vida: %d/%d)\n", 
               p.nome, heroi->vidaAtual - vidaAnterior, heroi->vidaAtual, heroi->vidaMaxima);
    }
    
    if (p.aumentoAtaque > 0) {
        heroi->ataque += p.aumentoAtaque;
        printf("[ITEM] %s aumentou seu ATAQUE em %d! (Ataque total: %d)\n", 
               p.nome, p.aumentoAtaque, heroi->ataque);
    }
    
    if (p.aumentoDefesa > 0) {
        heroi->defesa += p.aumentoDefesa;
        printf("[ITEM] %s aumentou sua DEFESA em %d! (Defesa total: %d)\n", 
               p.nome, p.aumentoDefesa, heroi->defesa);
    }
    
    Sleep(1000);
}

void menuPorcoes(struct usuario *heroi) {
    int escolha_porcao;
    
    system("CLS");
    mudarCor(2); // Amarelo
    printf("==================================================\n");
    printf("              MENU DE POÇÕES                      \n");
    printf("==================================================\n");
    DesenhoPorcao();

    printf("\nUSOS DE POÇÕES: %d de %d restantes\n", heroi->usosPocao, LIMITE_USO_PORCAO - heroi->usosPocao);
    printf("ATRIBUTOS ATUAIS: Vida: %d/%d | Atq: %d | Def: %d\n", 
           heroi->vidaAtual, heroi->vidaMaxima, heroi->ataque, heroi->defesa);
    printf("--------------------------------------------------\n");


    mudarCor(9);
    int i;
    for (i = 0; i < NUM_PORCOES; i++) {
        porcao p = listaPorcoes[i];
        printf("[%d] %s: ", i + 1, p.nome);
        if (p.aumentoVida > 0) printf("Cura +%d Vida ", p.aumentoVida);
        if (p.aumentoAtaque > 0) printf("Ataque +%d ", p.aumentoAtaque);
        if (p.aumentoDefesa > 0) printf("Defesa +%d ", p.aumentoDefesa);
        printf("\n");
    }
    
    printf("[0] VOLTAR PARA A BATALHA\n");
    printf("--------------------------------------------------\n");
    mudarCor(7);
    
    printf("Escolha uma poção (1 a %d) ou [0] para voltar: ", NUM_PORCOES);
    
    if (scanf("%d", &escolha_porcao) != 1) {
        limparBuffer();
        mudarCor(4); printf("Escolha inválida. Voltando...\n"); mudarCor(7);
        Sleep(500);
        return;
    }
    limparBuffer();

    if (escolha_porcao == 0) {
        return; 
    }

    if (escolha_porcao >= 1 && escolha_porcao <= NUM_PORCOES) {
        

        if (heroi->usosPocao >= LIMITE_USO_PORCAO) {
            mudarCor(4);
            printf("\n[ATENÇÃO] Você já usou o número máximo de %d poções!\n", LIMITE_USO_PORCAO);
            mudarCor(7);
            Sleep(1500);
            return; 
        }


        aplicarPorcao(heroi, escolha_porcao - 1); 
        
    
        heroi->usosPocao++; 
        

        salvarLogPorcao(heroi->nick, listaPorcoes[escolha_porcao - 1].nome, heroi->usosPocao);

        return;
        
    } else {
        mudarCor(4); printf("Opção inválida. Tente novamente.\n"); mudarCor(7);
        Sleep(500);
    }
}

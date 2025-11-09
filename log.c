// log.c - Versão Portável
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// #include <windows.h> // REMOVIDO para portabilidade no Linux
#include "log.h"
#include "playgame.h"

void atribuirEInicializarHeroi(int id_classe, struct usuario *heroi) {
    

	switch (id_classe) {
        case 0: // Guerreiro
            heroi->ataque = 400;
            heroi->defesa = 150;
			heroi->vidaAtual = 1500; 
            heroi->vidaMaxima = 1500; 
            break;
        case 1: // Mago
            heroi->ataque = 600;
            heroi->defesa = 250;
            heroi->vidaAtual = 600; // ATUALIZADO
            heroi->vidaMaxima = 600; // NOVO
            break;
        case 2: // Arqueiro
            heroi->ataque = 600;
            heroi->defesa = 50;
            heroi->vidaAtual = 900; 
            heroi->vidaMaxima = 900; 
            break;
        case 3: // Suporte
            heroi->ataque = 350;
            heroi->defesa = 500; 
            heroi->vidaAtual = 550; // ATUALIZADO
            heroi->vidaMaxima = 550; // NOVO
            break;
    }
    
    heroi->usosPocao = 0;
    salvarDadosUsuario(heroi);
}

void salvarDadosUsuario(const struct usuario *jogador) {
    
    const char *NOME_ARQUIVO = "HistoricoJogadores.txt"; 
    FILE *arquivo = fopen(NOME_ARQUIVO, "a");

    if (arquivo == NULL) {
        printf("ERRO: Nao foi possivel abrir o arquivo '%s'.\n", NOME_ARQUIVO);
        return;
    }

    
    fprintf(arquivo, "--- NOVO JOGADOR CRIADO ---\n");
    fprintf(arquivo, "NICK: %s\n", jogador->nick);
    fprintf(arquivo, "ATAQUE: %d\n", jogador->ataque);
    fprintf(arquivo, "DEFESA: %d\n", jogador->defesa);
    fprintf(arquivo, "VIDA: %d\n", jogador->vidaMaxima);
    fprintf(arquivo, "---------------------------\n\n");
    
    fclose(arquivo); 
    
    printf("Dados do jogador '%s' salvos em %s.\n", jogador->nick, NOME_ARQUIVO);
}



void salvarLogBatalha(const char *nick, const char *mensagem) {
    const char *NOME_ARQUIVO = "HistoricoJogadores.txt";
    FILE *arquivo = fopen(NOME_ARQUIVO, "a");

    if (arquivo == NULL) {
        printf("ERRO DE LOG: Nao foi possivel abrir o arquivo '%s' para log de batalha.\n", NOME_ARQUIVO);
        return;
    }


    time_t timer;
    char buffer[26];
    struct tm* tm_info;
    time(&timer);
    tm_info = localtime(&timer);

    strftime(buffer, 26, "[%Y-%m-%d %H:%M:%S]", tm_info);


    fprintf(arquivo, "%s [%s]: %s\n", buffer, nick, mensagem);


    fclose(arquivo);
}


void salvarLogPorcao(const char *nick, const char *nomePorcao, int usoAtual) {
    const char *NOME_ARQUIVO = "HistoricoJogadores.txt";
    FILE *arquivo = fopen(NOME_ARQUIVO, "a");

    if (arquivo == NULL) {
        printf("ERRO DE LOG: Nao foi possivel abrir o arquivo '%s' para log de porcao.\n", NOME_ARQUIVO);
        return;
    }

    time_t timer;
    char buffer[26];
    struct tm* tm_info;
    time(&timer);
    tm_info = localtime(&timer);
    strftime(buffer, 26, "[%Y-%m-%d %H:%M:%S]", tm_info);

  
    fprintf(arquivo, "%s [%s]: USOU %s (Uso: %d/2).\n", buffer, nick, nomePorcao, usoAtual);

    fclose(arquivo);
}
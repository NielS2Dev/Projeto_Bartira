#ifndef LOG_H
#define LOG_H

#include "playgame.h" 


void salvarDadosUsuario(const struct usuario *jogador);
void salvarLogBatalha(const char *nick, const char *mensagem);
void salvarLogPorcao(const char *nick, const char *nomePorcao, int usoAtual);
void atribuirEInicializarHeroi(int id_classe, struct usuario *heroi);

#endif
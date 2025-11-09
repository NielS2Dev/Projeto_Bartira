#ifndef PLAYGAME_H
#define PLAYGAME_H

#include "combate.h"

struct usuario {
	char nick[50];
	int ataque;
	int defesa;
	int vidaAtual;
	int vidaMaxima;
	
	int usosPocao;
	habilidade skills[3];
};	

int loopClasses();

#endif
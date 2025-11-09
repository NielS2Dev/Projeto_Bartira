#ifndef POCAO_H
#define POCAO_H

#include "playgame.h"

typedef struct {
    char nome[50];
    int aumentoVida;
    int aumentoAtaque;
    int aumentoDefesa;
} porcao;

extern porcao listaPorcoes[];
extern const int NUM_PORCOES;


void aplicarPorcao(struct usuario *heroi, int idPorcao);
void menuPorcoes(struct usuario *heroi);

#endif

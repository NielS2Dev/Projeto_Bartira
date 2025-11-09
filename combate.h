#ifndef COMBATE_H
#define COMBATE_H

#include "monstro.h" 

struct usuario;

typedef struct {
    char nome[30];      
    int danoMinimo;     
    int danoMaximo;     
} habilidade;


extern habilidade bancoDeSkills[4][3];


void atribuirClasse(struct usuario *jogador, int idClasse);
void lutar(struct usuario *heroi, int idMonstro);

#endif
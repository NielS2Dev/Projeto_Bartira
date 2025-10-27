#ifndef pocoes_h
#define pocoes_h

#include <stdio.h>
#include <stdlib.h>

typedef enum{
    CURA,
    FORÇA, //bonus de ataque
    DANO, // dano direto ao monstro (aremessavel)
    DEFESA //bonus de defesa
} tipopocao;

typedef struct{
    tipopocao tipo;
    int valor;
} pocao;

#endif
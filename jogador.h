#ifndef JOGADOR_H
#define JOGADOR_H

typedef enum{
    MAGO,
    GUERREIRO
} ClasseJogador;

struct usuario {
    char nick[50];
    int AtaqueFisico;
    int AtaqueMagico;
    int DefesaMagica;
    int DefesaFisica;
    int vida;
    int vidaMaxima;
    ClasseJogador classe;
};

#endif
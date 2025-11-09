#ifndef MONSTROS_H
#define MONSTROS_H

typedef struct {
    char nomeDosMonstros[50];
    int ataqueMonstros;
    int defesaMonstros;
    int vidaMonstros;
} monstros;

extern monstros listaDeMonstros[5];

void mostrarDadosDoMonstro(int idMonstro);

#endif
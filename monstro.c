#include <stdio.h>
#include "monstro.h"


monstros listaDeMonstros[5] = {
    {"Cão Assasino", 300, 50, 2000},
    {"Orc", 250, 150, 1200},
    {"Esqueleto", 150, 100, 600},    
    {"Dragão Jovem", 500, 300, 1500},   
    {"Draconatos", 300, 20, 900}
};

void mostrarDadosDoMonstro(int idMonstro) {
    if (idMonstro < 0 || idMonstro >= 5) {
        printf("ERRO: ID de monstro inválido.\n");
        return;
    }

    monstros monstro = listaDeMonstros[idMonstro];

    printf("\n==================================\n");
    printf("        DADOS DO MONSTRO\n");
    printf("==================================\n");
    printf("Nome:   %s\n", monstro.nomeDosMonstros);
    printf("Ataque: %d\n", monstro.ataqueMonstros);
    printf("Defesa: %d\n", monstro.defesaMonstros);
    printf("Vida:   %d\n", monstro.vidaMonstros);
    printf("==================================\n");
}
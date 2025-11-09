#include <stdio.h>
// #include <windows.h> <-- REMOVIDO

void mudarCor(int cor) {
    // Usando sequências de escape ANSI para mudar a cor no terminal Linux

    // Se a cor for 7 (padrão/branco), reseta para o padrão do terminal
    if (cor == 7) {
        printf("\033[0m"); // Reseta todos os atributos
        return;
    }

    switch (cor) {
        // Cores Escuras / Padrão (30-37)
        case 1: // Azul Escuro
            printf("\033[34m");
            break;
        case 2: // Verde Escuro
            printf("\033[32m");
            break;
        case 3: // Ciano Escuro
            printf("\033[36m");
            break;
        case 4: // Vermelho Escuro
            printf("\033[31m");
            break;
        // As cores restantes são mapeadas para variações Brilhantes (90-97)
        case 10: // Verde Claro (Brilhante)
            printf("\033[92m");
            break;
        case 11: // Ciano Claro (Brilhante)
            printf("\033[96m");
            break;
        case 12: // Vermelho Claro (Brilhante)
            printf("\033[91m");
            break;
        case 14: // Amarelo (Brilhante)
            printf("\033[93m");
            break;
        case 0: // Preto
        case 15: // Branco Brilhante (Usado como 7/padrão)
        default:
            // Por segurança, reseta a cor se a opção não for mapeada ou for padrão
            printf("\033[0m");
            break;
    }
    // Garante que a cor seja aplicada imediatamente
    fflush(stdout);
}
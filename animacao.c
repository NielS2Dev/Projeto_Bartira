#include <stdio.h>
#include <time.h>
// #include <windows.h> <-- REMOVIDO
#include <unistd.h> // Para usleep()
#include <stdlib.h> // Para system()
#include <string.h> // Para strlen()

// Definição de Sleep(ms) para usar usleep() (microsegundos)
#define Sleep(ms) usleep((ms) * 1000)

// Função para mover o cursor usando sequências de escape ANSI (Linux)
// ANSI escape code: \033[<LINHA>;<COLUNA>H ou \033[<LINHA>;<COLUNA>f
// Nota: Os terminais ANSI geralmente usam coordenadas 1-baseadas (1,1 é o topo/esquerda).
// O código original do Windows usa 0-baseadas. Mantenho o 0-baseado aqui, 
// adicionando +1 na impressão para o terminal.
void animacao(int x, int y) {
    // Sequência ANSI para mover o cursor para a linha (y+1) e coluna (x+1)
    // O '\r' garante que a linha volte para o início antes de mover o cursor.
    printf("\033[%d;%dH", y + 1, x + 1);
    fflush(stdout);
}

void mostrarDataHoraAtual() {
    time_t timer;
    char buffer[26];
    struct tm* tm_info;
    time(&timer);
    tm_info = localtime(&timer);
    strftime(buffer, 26, "[%Y-%m-%d %H:%M:%S]", tm_info);

    printf("Data e Hora Atual: %s\n", buffer);
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int rand0a4(void) {
    return rand() % 5;
}

void print_animado(const char *texto, int delay_ms){
    int i;
    for (i = 0; texto[i] != '\0'; i++){
        printf("%c", texto[i]);
        fflush(stdout);
        Sleep(delay_ms);
    }
}

void print_animado_multilinha(const char *linhas[], int num_linhas, int delay_ms) {
    int max_len = 0;
    int i = 0, pos = 0, linha = 0;

    // Calcula o comprimento máximo das linhas
    for (i = 0; i < num_linhas; i++) {
        int len = (int)strlen(linhas[i]);
        if (len > max_len) max_len = len;
    }

    // Limpa a tela usando o comando Linux
    system("clear"); // ALTERADO: cls -> clear

    // Loop de animação
    for (pos = 0; pos < max_len; pos++) {
        for (linha = 0; linha < num_linhas; linha++) {
            if (pos < (int)strlen(linhas[linha])) {
                animacao(pos, linha); // Usa a função de cursor ANSI
                putchar(linhas[linha][pos]);
            }
        }
        fflush(stdout);
        Sleep(delay_ms);
    }

    // Posiciona o cursor para a próxima linha de saída normal (após a animação)
    animacao(0, num_linhas + 1);
    printf("\n"); // Adiciona uma nova linha para garantir separação
}
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h> // Para usleep() (substituto do Sleep) e STDIN_FILENO
#include <termios.h> // Para _getch()
#include <locale.h>  // Para lidar com acentuação corretamente

#define ALTURA_ASCII 4
#define LARGURA_MAX_ASCII 15

// ===== FUNÇÕES ADAPTADAS PARA LINUX =====

// Limpa a tela do terminal
void limparTela() {
    printf("\033[2J\033[H");
    fflush(stdout);
}

// Move o cursor para a posição (x, y)
void animacao(int x, int y) {
    // No padrão ANSI, as coordenadas são (linha, coluna) e começam em 1.
    // Adicionamos +1 para manter a lógica original do seu código que espera (0,0).
    printf("\033[%d;%dH", y + 1, x + 1);
}

// Muda a cor do texto usando códigos ANSI
void mudarCor(int cor) {
    /* Tabela de conversão de cores Windows para ANSI */
    const char* cores_ansi[] = {
        "\033[0;30m", // 0: Preto
        "\033[0;34m", // 1: Azul
        "\033[0;32m", // 2: Verde
        "\033[0;36m", // 3: Ciano
        "\033[0;31m", // 4: Vermelho
        "\033[0;35m", // 5: Magenta
        "\033[0;33m", // 6: Amarelo/Marrom
        "\033[0m",    // 7: Padrão (reseta a cor)
        "\033[1;30m", // 8: Cinza escuro
        "\033[1;34m", // 9: Azul claro
        "\033[1;32m", // 10: Verde claro
        "\033[1;36m", // 11: Ciano claro
        "\033[1;31m", // 12: Vermelho claro
        "\033[1;35m", // 13: Rosa/Magenta claro
        "\033[1;33m", // 14: Amarelo
        "\033[1;37m"  // 15: Branco
    };
    if (cor >= 0 && cor <= 15) {
        printf("%s", cores_ansi[cor]);
    } else {
        printf("\033[0m"); // Reseta para o padrão
    }
}

// Função para pausar a execução (substitui Sleep)
void Sleep(int milliseconds) {
    usleep(milliseconds * 1000);
}

// Implementação da função _getch() para Linux
int _getch() {
    struct termios oldattr, newattr;
    int ch;
    tcgetattr(STDIN_FILENO, &oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
    return ch;
}

// ===== SEU CÓDIGO (COM PEQUENOS AJUSTES) =====

void print_animado(const char *texto, int delay_ms) {
    int i;
    for (i = 0; texto[i] != '\0'; i++) {
        printf("%c", texto[i]);
        fflush(stdout);
        Sleep(delay_ms);
    }
}

void print_animado_multilinha(const char *linhas[], int num_linhas, int delay_ms) {
    int max_len = 0;
    int i = 0, pos = 0, linha = 0;

    for (i = 0; i < num_linhas; i++) {
        int len = (int)strlen(linhas[i]);
        if (len > max_len) max_len = len;
    }

    limparTela();
    for (pos = 0; pos < max_len; pos++) {
        for (linha = 0; linha < num_linhas; linha++) {
            if (pos < (int)strlen(linhas[linha])) {
                animacao(pos, linha);
                putchar(linhas[linha][pos]);
            }
        }
        fflush(stdout);
        Sleep(delay_ms);
    }
    animacao(0, num_linhas + 1);
}

void uern() {
    const char *arte[] = {
        " __    __  _______ .______      .__   __. ",
        "|  |  |  | |   ____||   _  \\     |  \\ |  | ",
        "|  |  |  | |  |__   |  |_)  |    |   \\|  | ",
        "|  |  |  | |   __|  |      /     |  . `  | ",
        "|  `--'  | |  |____ |  |\\  \\----.|  |\\   | ",
        " \\______/  |_______|| _| `._____||__| \\__| ",
    };
    int num_linhas = sizeof(arte) / sizeof(arte[0]);
    mudarCor(3);
    print_animado_multilinha(arte, num_linhas, 10); // Aumentei um pouco o delay para melhor visualização
    mudarCor(7);
    printf("\n");
}

void projetoRpg() {
    const char *arte[] = {
        "  ____               _      _          ____  ____   ____ ",
        " |  _ \\ _ __ ___ (_) ___| |_ ___   |  _ \\|  _ \\ / ___|",
        " | |_) | '__/ _ \\| |/ _ \\ __/ _ \\  | |_) | |_) | |  _ ",
        " |  __/| | | (_) | |  __/ || (_) | |  _ <|  __/| |_| |",
        " |_|   |_|  \\___// |\\___|\\__\\___/  |_| \\_\\_|    \\____|",
        "               |__/                                  "
    };
    int num_linhas = sizeof(arte) / sizeof(arte[0]);
    mudarCor(12);
    print_animado_multilinha(arte, num_linhas, 10);
    mudarCor(7);
    printf("\n");
}

void introducao() {
    // Textos corrigidos para UTF-8
    const char *introRPG[] = {
        "==============================================================",
        "                  Bem-vindo ao bravo mundo de RPG!            ",
        "==============================================================",
        "",
        "Após longas jornadas e perigos desconhecidos, você finalmente",
        "chega ao ponto crucial da sua aventura. Agora, a hora chegou:",
        "É o momento de decidir seu destino, seu caminho, sua identidade!",
        "",
        "Herói ou heroína, guerreiro(a) ou sábio(a), o mundo espera pelo",
        "nome que carregará na glória das batalhas e nas lendas que surgirão.",
        ""
    };
    int num_linhas = sizeof(introRPG) / sizeof(introRPG[0]);
    mudarCor(14);
    int i;
    for (i = 0; i < num_linhas; i++) {
        print_animado(introRPG[i], 1);
        printf("\n");
        Sleep(80);
    }
    mudarCor(7);
    printf("\n");
}

void apresentacaoMago() {
    const char *introRPG[] = {
        "01- CLASSE: MAGO",
        "VIDA = 50",
        "ATAQUE MÁGICO = 350",
        "DEFESA = 100"
    };
    int num_linhas = sizeof(introRPG) / sizeof(introRPG[0]);
    mudarCor(10); // Verde claro
    int i;
    for (i = 0; i < num_linhas; i++) {
        print_animado(introRPG[i], 2);
        printf("\n");
        Sleep(80);
    }
    mudarCor(7);
    printf("\n");
}

void mago() {
    const char *desenho[] = {
        "              _,._      ",
        "  .||,      /_ _\\\\     ",
        " \\.`',/      |'L'| |    ",
        " = ,. =      | -,| L    ",
        " / || \\    ,-'\\\"/,'`.  ",
        "   ||     ,'   `.,. `. ",
        "  ,|____,' , ,;' \\| | ",
        " (3|\\    _/|/'   _| | ",
        "  ||/,-''  | >-'' _,\\\\",
        "  ||'      ==\\ ,-'  ,' ",
        "  ||       |  V \\ ,|  ",
        "  ||       |   |` |  ",
        "  ||       |   |   \\  ",
        "  ||       |   \\    \\ ",
        "  ||       |   |    \\",
        "  ||       |    \\_,-'",
        "  ||       |___,,--\")_\\",
        "  ||         |_|   ccc/",
        "  ||         ccc/      ",
        "  ||               hjm"
    };
    int num_linhas = sizeof(desenho) / sizeof(desenho[0]);
    mudarCor(6);
    print_animado_multilinha(desenho, num_linhas, 10);
    mudarCor(7);
}

struct usuario {
    char nick[50];
    int ataque;
    int defesa;
    int vida;
};

struct monstros {
    char nomesDosmonstros[50];
    int ataqueMonstros;
    int defesaMonstros;
    int vidaMonstros;
};

int main() {
    // Configura o programa para usar a localização do sistema (para acentos)
    setlocale(LC_ALL, "");

    char nick_maiusculo[100];
    struct usuario jogador;
    struct monstros tiposMonstros[6];
    bool nomeValido = false;

    printf("Versão 1.0.1 (Adaptado para Linux)\n");
    Sleep(1000);
    limparTela();
    
    uern();
    Sleep(500);
    projetoRpg();
    Sleep(500);
    
    introducao();
    
    while (!nomeValido) {
        mudarCor(9);
        printf("Qual é o seu nick de batalha: ");
        mudarCor(7); // Reseta a cor para o input do usuário
        fgets(jogador.nick, sizeof(jogador.nick), stdin);
        jogador.nick[strcspn(jogador.nick, "\n\r")] = '\0';

        if (strchr(jogador.nick, ' ') != NULL) {
            mudarCor(4);
            printf("ERRO: O nick não pode conter espaços. Tente novamente.\n\n");
        } else if (strlen(jogador.nick) == 0) {
            mudarCor(4);
            printf("ERRO: O nick não pode estar vazio. Tente novamente.\n\n");
        } else {
            nomeValido = true;
        }
    }

    // Converte para maiúsculo
    for (int i = 0; jogador.nick[i] != '\0'; i++) {
        nick_maiusculo[i] = toupper(jogador.nick[i]);
        nick_maiusculo[i+1] = '\0';
    }

    limparTela();

    mudarCor(6);
    print_animado("Bem-vindo, jogador: ", 1);
    printf("%s\n", nick_maiusculo);
    Sleep(1000);

    mudarCor(10);
    print_animado("\nPressione qualquer tecla para ir para a seleção de agente...", 1);
    _getch();
    limparTela();
    
    mago();
    apresentacaoMago();

    printf("\nFim da demonstração. Pressione qualquer tecla para sair.\n");
	printf("oi");
    _getch();
	limparTela(); 
    
    mudarCor(7); // Garante que o terminal volte ao normal
    return 0;
}
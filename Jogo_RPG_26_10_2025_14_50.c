#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
typedef struct {
    char nome[30];      // OK
    int danoMinimo;     // Este campo está faltando ou escrito errado na sua definicao atual.
    int danoMaximo;     // Este campo está faltando ou escrito errado na sua definicao atual.
} habilidade;


habilidade bancoDeSkills[4][3] = {
    // [0] GUERREIRO
    {
        {"Esmagamento", 350, 450},   // Dano de 250 a 450
        {"Investida", 300, 500},     // Dano de 300 a 500
        {"Ruptura", 400, 600}        // Dano de 400 a 600
    },
    // [1] MAGO
    {
        {"Raio Arcana", 300, 350},
        {"Chama Eterna", 350, 550},
        {"Meteoro", 500, 700}
    },
    // [2] ARQUEIRO
    {
        {"Tiro Duplo", 320, 380},
        {"Flecha Perfurante", 320, 480},
        {"Tiro de Precisao", 450, 650}
    },
    // [3] SUPORTE (Agora com habilidades ofensivas, como você pediu)
    {
        {"Toque Vazio", 380, 300},
        {"Pena Eletrica", 380, 420},
        {"Explosao Sagrada", 380, 580}
    }
};

int rand0a4(void) {
    return rand() % 5; // 0..4
}

void animacao(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y; 
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void mudarCor(int cor){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cor);

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
    
    for (i = 0; i < num_linhas; i++) {
        int len = (int)strlen(linhas[i]);
        if (len > max_len) max_len = len;
    }

    system("cls");
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



void guerreiro() {
	mudarCor(6);
    printf("A           {}\n");
    printf(" / \\, | ,        .--.\n");
    printf("|    =|= >      /.--.\\\n");
    printf(" \\ /` | `       |====|\n");
    printf("  `   |         |`::`|  \n");
    printf("      |     .-;`\\..../`;_.-^-._\n");
    printf("     /\\\\/  /  |...::..|`   :   `|\n");
    printf("     |:'\\ |   /'''::''|   .:.   |\n");
    printf("      \\ /\\;-,/\\   :: |..:UERN:..|\n");
    printf("      |\\ <` >  >._::_.| ':::::' |\n");
    printf("      | `\"\"`  /   ^^  |   ':'   |\n");
    printf("      |       |       \\    :    /\n");
    printf("      |       |        \\   :   / \n");
    printf("      |       |___/\\___|`-.:.-`\n");
    printf("      |        \\_ || _/    `\n");
    printf("      |        <_ >< _>\n");
    printf("      |        |  ||  |\n");
    printf("      |        |  ||  |\n");
    printf("      |       _\\.:||:./_\n");
    printf("      | RN  /____/\\____\\\n");
    mudarCor(7);
}

void mago() {
	mudarCor(6);
    printf("              _,._      \n");
    printf("  .||,       /_ _\\\\     \n");
    printf(" \\.`',/      |'L'| |    \n");
    printf(" = ,. =      | -,| L    \n");
    printf(" / || \\    ,-'\\\"/,'`.   \n");
    printf("   ||     ,'   `,,. `.  \n");
    printf("   ,|____,' , ,;' \\| |  \n");
    printf("  (3|\\    _/|/'   _| |  \n");
    printf("   ||/,-''  | >-'' _,\\\\ \n");
    printf("   ||'      ==\\ ,-'  ,' \n");
    printf("   ||       |  V \\ ,|   \n");
    printf("   ||       |    |` |   \n");
    printf("   ||       |    |   \\  \n");
    printf("   ||       |    \\    \\ \n");
    printf("   ||       |     |    \\\n");
    printf("   ||       |      \\_,-'\n");
    printf("   ||       |___,,--\")_\\\\\n");
    printf("   ||         |_|   ccc/\n");
    printf("   ||        ccc/       \n");
    printf("   ||             \n");
    mudarCor(2);
;
}

void arqueiro() {
	mudarCor(6);
    printf("            /`.                       \n");
    printf("           /   :.                        _\n");
    printf("          /     \\\\                      | |\n");
    printf("       ,;/,      ::              >>>>---: |> \n");
    printf("   ___:c/.(      ||                     | |\n");
    printf(" ,'  _|:)>>>--,-'B)>                    | |\n");
    printf("(  '---'\\--'` _,'||                     | |\n");
    printf(" `--.    \\ ,-'   ;;                     | |\n");
    printf("     |    \\|    //                  ,>-.| |\n");
    printf("     |     \\   ;'                  ^    |_|\n");
    printf("     |_____|'\\,'                          |\n");
    printf("     :     :                             |\n");
    printf("     |  ,  |                             |\n");
    printf("     | : \\ :                             |\n");
    printf("     | | : :                             |\n");
    printf("     | | | |                            /|\\\n");
    printf("     | | |_`.  jah/SSt                 / | \\\n");
    printf("     '--`                             /  |  \\\n");
    printf("                                         '\n");
    mudarCor(2);
}

void suporte() {
	mudarCor(6);
    printf("             _,._\n");
    printf("           ,'   ,`-.\n");
    printf("|.        /     |\\  `.\n");
    printf("\\ \\      (  ,-,-` ). `-._ __\n");
    printf(" \\ \\      \\|\\,'     `\\  /'  `\\\n");
    printf("  \\ \\      ` |, ,  /  \\ \\     \\\n");
    printf("   \\ \\         `,_/`, /\\,`-.__/`.\n");
    printf("    \\ \\            | ` /    /    `-._\n");
    printf("     \\\\\\           `-/'    /         `-.\n");
    printf("      \\\\`/ _______,-/_   /'             \\\n");
    printf("     ---'`|       |`  ),' `---.  ,       |\n");
    printf("      \\..-`--..___|_,/          /       /\n");
    printf("                 |    |`,-,...,/      ,'     \n");
    printf("                 \\    | |_|   /     ,' __  r-'',\n");
    printf("                  |___|/  |, /  __ /-''  `'`)  |  \n");
    printf("               _,-'   ||__\\ /,-' /     _,.--|  (\n");
    printf("            .-'       )   `(_   / _,.-'  ,-' _,/\n");
    printf("             `-------'       `--''       `'''\n");
    mudarCor(2);
}




void apresentacaoGuerreiro() {
	mudarCor(2);
    printf("=====================================\n");
    printf("|           FICHA DE RPG            |\n");
    printf("=====================================\n");
    printf("| 00 - CLASSE: GUERREIRO            |\n");
    printf("| ATAQUE FÍSICO: 400                |\n");
    printf("| DEFESA: 150                       |\n");
    printf("| VIDA: 1500                        |\n");
    printf("=====================================\n");
    mudarCor(7);
}

void apresentacaoMago() {
	mudarCor(2);
    printf("=====================================\n");
    printf("|           FICHA DE RPG            |\n");
    printf("=====================================\n");
    printf("| 01 - CLASSE: MAGO                 |\n");
    printf("| ATAQUE MÁGICO: 600                |\n");
    printf("| DEFESA: 250                       |\n");
    printf("| VIDA: 600                         |\n");
    printf("=====================================\n");
    mudarCor(7);
}

void apresentacaoArqueiro() {
	mudarCor(2);
    printf("=====================================\n");
    printf("|           FICHA DE RPG            |\n");
    printf("=====================================\n");
    printf("| 02 - CLASSE: ARQUEIRO             |\n");
    printf("| ATAQUE MÁGICO: 600                |\n");
    printf("| DEFESA: 50                       |\n");
    printf("| VIDA: 900                         |\n");
    printf("=====================================\n");
    mudarCor(7);
}

void apresentacaoSuporte() {
	mudarCor(2);
    printf("=====================================\n");
    printf("|           FICHA DE RPG            |\n");
    printf("=====================================\n");
    printf("| 03 - CLASSE: SUPORTE              |\n");
    printf("| ATAQUE MÁGICO: 350                |\n");
    printf("| DEFESA: 500                       |\n");
    printf("| VIDA: 550                         |\n");
    printf("=====================================\n");
    mudarCor(7);
}



int loopClasses() {
    int estado_atual = 0;
    int classe1, classe2;
    const int total_classes = 4; 

    while (1) {
        system("CLS"); 
        switch (estado_atual) {
            case 0:
                guerreiro();
                apresentacaoGuerreiro();
                break;
            case 1:
                mago();
                apresentacaoMago();
                break;
            case 2:
                arqueiro(); 
                apresentacaoArqueiro();
                break;
            case 3:
                suporte();
                apresentacaoSuporte();
                break;
        }

        mudarCor(3);
        printf("\n============================================================\n");
        printf("(Use as setinhas ESQUERDA/DIREITA para navegar em loop.)\n");
        printf("(Pressione 'Q' ou 'q' para SELECIONAR esta classe)\n");
        printf("============================================================\n");
        mudarCor(7);

        classe1 = getch();

        if (classe1 == 'q' || classe1 == 'Q') {
            break; 
        }

        if (classe1 == 0 || classe1 == 0xE0) {
            classe2 = getch();
            switch (classe2) {
                case 75:
                case 72: 
                    estado_atual = (estado_atual - 1 + total_classes) % total_classes;
                    break;
                case 77: 
                case 80: 
                    estado_atual = (estado_atual + 1) % total_classes;
                    break;
            }
        }
    }


    system("CLS");
    printf("==================================================\n");
    printf("VOCÊ SELECIONOU A CLASSE (ID): %d\n", estado_atual);
    

    switch (estado_atual) {
        case 0: 
			printf("CLASSE: Guerreiro\n");
			guerreiro();
			break;
        case 1: 
			printf("CLASSE: Mago\n");
			mago(); 
			break;
        case 2: 
			printf("CLASSE: Arqueiro\n");
			arqueiro(); 
			break;
        case 3: 
			printf("CLASSE: Suporte\n"); 
			suporte();
			break;
    }
	printf("************************************************************\n");
	    mudarCor(11); // Cor para destacar as habilidades
	    
	    // >>>>> INSERÇÃO DO NOVO CÓDIGO AQUI: Loop para imprimir as 3 Habilidades <<<<<
	    printf("Habilidades da Classe:\n");
	    int i;
	    for (i = 0; i < 3; i++) {
	        // Acessa o array global bancoDeSkills usando o ID da classe (estado_atual)
	        printf(" [%d] %s (Dano: %d - %d)\n", 
	               i + 1,
	               bancoDeSkills[estado_atual][i].nome,
	               bancoDeSkills[estado_atual][i].danoMinimo,
	               bancoDeSkills[estado_atual][i].danoMaximo);
	    }
	    // >>>>> FIM DA INSERÇÃO <<<<<
	
	    mudarCor(7);
	    printf("====================================================\n");
	    printf("Pressione qualquer tecla para iniciar a aventura...\n");
	    getch(); // Adiciona uma pausa para o usuário ler a ficha completa
	    
	return estado_atual;
}


void uern() {
const char* arte[] = {
    " _   _ _____ ____  _   _       ____  _   _  ",
    "| | | | ____|  _ \\| \\ | |     |  _ \\| \\ | | ",
    "| | | |  _| | |_) |  \\| |_____| |_) |  \\| | ",
    "| |_| | |___|  _ <| |\\  |_____|  _ <| |\\  | ",
    " \\___/|_____|_| \\_\\_| \\_|     |_| \\_\\_| \\_| "
};
    int num_linhas = sizeof(arte) / sizeof(arte[0]);
    
    mudarCor(3);
    print_animado_multilinha(arte, num_linhas, 30);
    mudarCor(7);
    printf("\n"); 
}


void projetoRpg() {
    const char *arte[] = {
        "  ____            _      _          ____  ____   ____ ",
        " |  _ \\ _ __ ___ (_) ___| |_ ___   |  _ \\|  _ \\ / ___|",
        " | |_) | '__/ _ \\| |/ _ \\ __/ _ \\  | |_) | |_) | |  _ ",
        " |  __/| | | (_) | |  __/ || (_) | |  _ <|  __/| |_| |",
        " |_|   |_|  \\___// |\\___|\\__\\___/  |_| \\_\\_|    \\____|",
        "               |__/                                    "
    };

    int num_linhas = sizeof(arte) / sizeof(arte[0]);

    mudarCor(12);
    print_animado_multilinha(arte, num_linhas, 30);
    mudarCor(7);
    printf("\n");
}

void introducao(){
	const char *introRPG[] = {
	    "==============================================================",
	    "                 Bem-vindo ao bravo mundo de RPG!            ",
	    "==============================================================",
	    "",
	    "Após longas jornadas e perigos desconhecidos, você finalmente",
	    "chega ao ponto crucial da sua aventura. Agora, a hora chegou:",
	    "é o momento de decidir seu destino, seu caminho, sua identidade!",
	    "",
	    "Herói ou heroína, guerreiro(a) ou sábio(a), o mundo espera pelo",
	    "nome que carregará na glória das batalhas e nas lendas que surgirão.",
	    ""
	};
    
    int num_linhas = sizeof(introRPG) / sizeof(introRPG[0]);
    
    mudarCor(14);
	int i;
	
	for(i = 0; i < num_linhas; i++){
		print_animado(introRPG[i], 1);
		printf("\n");
		Sleep(80);
	}
	
	mudarCor(7);
	printf("\n");

}

void contagem(){
	int contador = 1;
	
	for (contador = 5; contador >= 1; contador--){
		mudarCor(contador + 1);
		print_animado("Mudando para a tela de seleção de agente em: ", 1);
		printf("%d", contador);
		print_animado(" segundos\n", contador);
		Sleep(500);
	}
}

void contagem_dois(){
	int contador = 1;
	
	for (contador = 5; contador >= 1; contador--){
		mudarCor(contador + 2);
		print_animado("Mudando para a tela de seleção de agente em: ", 1);
		printf("%d", contador);
		print_animado(" segundos\n", contador);
		Sleep(500);
	}
	system("CLS");
}


typedef struct {
	char nomeDosMonstros[50];
	int ataqueMonstros;
	int defesaMonstros;
	int vidaMonstros;
} monstros;


monstros listaDeMonstros[5] = {
    // [0] Cãe
    {"Cão Assasino", 300, 50, 2000},
    
    // [1] Orc <--- O Orc está no índice 1
    {"Orc", 250, 150, 1200},
    
    // [2] Esqueleto
    {"Esqueleto", 150, 100, 600},
    
    // [3] Dragão Jovem
    {"Dragão Jovem", 500, 300, 1500},
    
    // [4] Draconatos
    {"Draconatos", 300, 20, 900}
};


void mostrarDadosDoCao() {
    
    // Pegamos a struct Monstro na posição [0] do array
    monstros orc = listaDeMonstros[0]; 
    
    printf("\n==================================\n");
    printf("         DADOS DO MONSTRO\n");
    printf("==================================\n");
    printf("Nome:   %s\n", orc.nomeDosMonstros);
    printf("Ataque: %d\n", orc.ataqueMonstros);
    printf("Defesa: %d\n", orc.defesaMonstros);
    printf("Vida:   %d\n", orc.vidaMonstros);
    printf("==================================\n");
}

void mostrarDadosDoOrc() {
    
    // Pegamos a struct Monstro na posição [1] do array
    monstros orc = listaDeMonstros[1]; 
    
    printf("\n==================================\n");
    printf("         DADOS DO MONSTRO\n");
    printf("==================================\n");
    printf("Nome:   %s\n", orc.nomeDosMonstros);
    printf("Ataque: %d\n", orc.ataqueMonstros);
    printf("Defesa: %d\n", orc.defesaMonstros);
    printf("Vida:   %d\n", orc.vidaMonstros);
    printf("==================================\n");
}

void mostrarDadosDoEsqueleto() {
    
    // Pegamos a struct Monstro na posição [2] do array
    monstros orc = listaDeMonstros[2]; 
    
    printf("\n==================================\n");
    printf("         DADOS DO MONSTRO\n");
    printf("==================================\n");
    printf("Nome:   %s\n", orc.nomeDosMonstros);
    printf("Ataque: %d\n", orc.ataqueMonstros);
    printf("Defesa: %d\n", orc.defesaMonstros);
    printf("Vida:   %d\n", orc.vidaMonstros);
    printf("==================================\n");
}

void mostrarDadosDoDragao() {
    
    // Pegamos a struct Monstro na posição [3] do array
    monstros orc = listaDeMonstros[3]; 
    
    printf("\n==================================\n");
    printf("         DADOS DO MONSTRO\n");
    printf("==================================\n");
    printf("Nome:   %s\n", orc.nomeDosMonstros);
    printf("Ataque: %d\n", orc.ataqueMonstros);
    printf("Defesa: %d\n", orc.defesaMonstros);
    printf("Vida:   %d\n", orc.vidaMonstros);
    printf("==================================\n");
}

void mostrarDadosDoDraconetos() {
    
    // Pegamos a struct Monstro na posição [4] do array
    monstros orc = listaDeMonstros[4]; 
    
    printf("\n==================================\n");
    printf("         DADOS DO MONSTRO\n");
    printf("==================================\n");
    printf("Nome:   %s\n", orc.nomeDosMonstros);
    printf("Ataque: %d\n", orc.ataqueMonstros);
    printf("Defesa: %d\n", orc.defesaMonstros);
    printf("Vida:   %d\n", orc.vidaMonstros);
    printf("==================================\n");
}



struct usuario {
	char nick[50];
	int ataque;
	int defesa;
	int vidaAtual;
	int vidaMaxima;
	
	int usosPocao;
	habilidade skills[3];
};	


// PROTÓTIPO PARA salvarLogBatalha
void salvarLogBatalha(const char *nick, const char *mensagem); 

// PROTÓTIPO PARA menuPorcoes
void menuPorcoes(struct usuario *heroi); 

// PROTÓTIPO PARA salvarLogPorcao
void salvarLogPorcao(const char *nick, const char *nomePorcao, int usoAtual);





void atribuirClasse(struct usuario *jogador, int idClasse) {
    // ... (Configuração dos atributos base do herói (vida, ataque, defesa) ...
    int i;
    // --- CONFIGURAÇÃO DAS 3 HABILIDADES ---
    for (i = 0; i < 3; i++) {
        // Copia a struct habilidade completa, incluindo danoMinimo e danoMaximo
        jogador->skills[i] = bancoDeSkills[idClasse][i]; 
        
        // Se a sua versão C não permitir copiar a struct inteira, 
        // use memcpy ou copie campo por campo (como abaixo):
        // 
        // strcpy(jogador->skills[i].nome, bancoDeSkills[idClasse][i].nome);
        // jogador->skills[i].danoMinimo = bancoDeSkills[idClasse][i].danoMinimo;
        // jogador->skills[i].danoMaximo = bancoDeSkills[idClasse][i].danoMaximo;
    }

    /*
	printf("\nClasse configurada! Habilidade 1: %s (Dano %d-%d)\n", 
           jogador->skills[0].nome, 
           jogador->skills[0].danoMinimo,
           jogador->skills[0].danoMaximo);
    */
}

void salvarDadosUsuario(const struct usuario *jogador) {
    
    // Defina o nome do arquivo. Usamos "a" (append) para não apagar logs anteriores.
    const char *NOME_ARQUIVO = "log_do_jogo.txt"; 
    FILE *arquivo = fopen(NOME_ARQUIVO, "a");

    if (arquivo == NULL) {
        printf("ERRO: Nao foi possivel abrir o arquivo '%s'.\n", NOME_ARQUIVO);
        return;
    }
    
    // -----------------------------------------------------------------
    // ESCRITA ORGANIZADA DOS DADOS
    // Usamos fprintf para escrever no arquivo, formatando a saída.
    // -----------------------------------------------------------------
    
    fprintf(arquivo, "--- NOVO JOGADOR CRIADO ---\n");
    fprintf(arquivo, "NICK: %s\n", jogador->nick);
    fprintf(arquivo, "ATAQUE: %d\n", jogador->ataque);
    fprintf(arquivo, "DEFESA: %d\n", jogador->defesa);
    fprintf(arquivo, "VIDA: %d\n", jogador->vidaMaxima);
    fprintf(arquivo, "---------------------------\n\n");
    
    // O fechamento é essencial!
    fclose(arquivo); 
    
    printf("Dados do jogador '%s' salvos em %s.\n", jogador->nick, NOME_ARQUIVO);
}

void atribuirEInicializarHeroi(int id_classe, struct usuario *heroi) {
    
    // ATENÇÃO: O nick precisa já estar preenchido na struct *heroi*
    // heroi->nick = "NomeDoJogador"; // Já deve ter sido definido

	switch (id_classe) {
        case 0: // Guerreiro
            heroi->ataque = 400;
            heroi->defesa = 150;
			heroi->vidaAtual = 1500; // Defina a vida inicial
            heroi->vidaMaxima = 1500; // Defina a vida máxima
            break;
        case 1: // Mago
            heroi->ataque = 600;
            heroi->defesa = 250;
            heroi->vidaAtual = 600; // ATUALIZADO
            heroi->vidaMaxima = 600; // NOVO
            break;
        case 2: // Arqueiro
            heroi->ataque = 600;
            heroi->defesa = 50;
            heroi->vidaAtual = 900; // ATUALIZADO
            heroi->vidaMaxima = 900; // NOVO
            break;
        case 3: // Suporte
            heroi->ataque = 350;
            heroi->defesa = 500; // CORRIGIDO: Era 100 na vida, usei 500 da apresentação
            heroi->vidaAtual = 550; // ATUALIZADO
            heroi->vidaMaxima = 550; // NOVO
            break;
    }
    
    heroi->usosPocao = 0;
    // 3. CHAMAR A FUNÇÃO DE SALVAMENTO DEPOIS DE ATRIBUIR OS DADOS
    salvarDadosUsuario(heroi);
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void venceu(){
	const char *arte[] = {
	    "      __  __                 _                   ",
	    "    |  \\/  | ___  _ __  ___| |_ _ __ ___        ",
	    "    | |\\/| |/ _ \\| '_ \\/ __| __| '__/ _ \\       ",
	    "    | |  | | (_) | | | \\__ \\ |_| | | (_) |      ",
	    " ___|_|  |_|\\___/|_| |_|___/\\__|_|  \\___/       ",
	    "|  _ \\  ___ _ __ _ __ ___ | |_ __ _  __| | ___  ",
	    "| | | |/ _ \\ '__| '__/ _ \\| __/ _` |/ _` |/ _ \\ ",
	    "| |_| |  __/ |  | | | (_) | || (_| | (_| | (_) |",
	    "|____/ \\___|_|  |_|  \\___/ \\__\\__,_|\\__,_|\\___/ "
	};
    int num_linhas = sizeof(arte) / sizeof(arte[0]);
    
    mudarCor(3);
    print_animado_multilinha(arte, num_linhas, 30);
    mudarCor(7);
    printf("\n");  
}

void gameOver(){
	const char *arte[] = {
	    "  _______      ___      .___  ___.  _______   ",
	    " /  _____|    /   \\     |   \\/   | |   ____|  ",
	    "|  |  __     /  ^  \\    |  \\  /  | |  |__     ",
	    "|  | |_ |   /  /\\_/  \\   |  |\\/|  | |   __|    ",
	    "|  |__| |  /  _____  \\  |  |  |  | |  |____   ",
	    " \\______| /__/     \\__\\ |__|  |__| |_______|  ",
	    "                                              ",
	    "  ______   ____    ____  _______ .______      ",
	    " /  __  \\  \\   \\  /   / |   ____||   _  \\     ",
	    "|  |  |  |  \\   \\/   /  |  |__   |  |_)  |    ",
	    "|  |  |  |   \\      /   |   __|  |      /     ",
	    "|  `--'  |    \\    /    |  |____ |  |\\  \\----.",
	    " \\______/      \\__/     |_______|| _| `._____|",
	    "                                              "
	};
    int num_linhas = sizeof(arte) / sizeof(arte[0]);
    
    mudarCor(2);
    print_animado_multilinha(arte, num_linhas, 30);
    mudarCor(7);
    printf("\n"); 
}

void desenvolvedores(){
		const char *introRPG[] = {
	    "==============================================================",
	    "                 Jogo desenvolvido pelos alunos(as):          ",
	    "                 Antoniel da Silva Alves                      ",
	    "                 Pedro Henrique Da Silva Dias                 ",
	    "==============================================================",
	    "",
	    "Sob: Orientação da Professora Bartira Paraguaçu Falcão Dantas Rocha",
	    "Site do nosso projeto: https://niels2dev.github.io/AntonielUern/",
	    "Repositorio Git: https://github.com/NielS2Dev/Projeto_Bartira.git",
	    "Repositorio Git: https://github.com/PedroHenrique/Projeto_Bartira.git",
	    ""
	};
    
    int num_linhas = sizeof(introRPG) / sizeof(introRPG[0]);
    
    mudarCor(14);
	int i;
	
	for(i = 0; i < num_linhas; i++){
		print_animado(introRPG[i], 1);
		printf("\n");
		Sleep(80);
	}
	
	mudarCor(7);
	printf("\n");

}

void desenvolvedores2(){
		const char *introRPG[] = {
	    "==============================================================",
	    "                 Jogo desenvolvido pelos alunos(as):          ",
	    "                 Antoniel da Silva Alves                      ",
	    "                 Pedro Henrique Da Silva Dias                 ",
	    "==============================================================",
	    ""
	};
    
    int num_linhas = sizeof(introRPG) / sizeof(introRPG[0]);
    
    mudarCor(9);
	int i;
	
	for(i = 0; i < num_linhas; i++){
		print_animado(introRPG[i], 1);
		printf("\n");
		Sleep(80);
	}
	
	mudarCor(7);
	printf("\n");

}

void lutar(struct usuario *heroi, int idMonstro) {
    // 1. Clonar os dados base do monstro para a luta (para poder mudar a vida)
    monstros monstroAtual = listaDeMonstros[idMonstro]; 
    int vidaMonstroAtual = monstroAtual.vidaMonstros; // Rastreia a vida atual

    printf("==================================================\n");
    printf("COMECOU A BATALHA CONTRA: %s\n", monstroAtual.nomeDosMonstros);
    printf("==================================================\n");
    
    // Loop principal da luta (continua enquanto ambos estiverem vivos)
    while (heroi->vidaAtual > 0 && vidaMonstroAtual > 0) { // ATUALIZADO: Usando vidaAtual
        system("CLS");
        
        mudarCor(10); // Cor Verde para informações de vida
        // ATUALIZADO: Exibindo vidaAtual/vidaMaxima
        printf("VIDA DO HERÓI (%s): %d/%d\n", heroi->nick, heroi->vidaAtual, heroi->vidaMaxima); 
        mudarCor(12); // Cor Vermelha para o monstro
        printf("VIDA DO MONSTRO (%s): %d/%d\n", monstroAtual.nomeDosMonstros, vidaMonstroAtual, monstroAtual.vidaMonstros);
        mudarCor(7);
        printf("--------------------------------------------------\n");

        printf("Escolha sua ação:\n"); // Mudei para "ação"
        int i;
        for (i = 0; i < 3; i++) {
            // Exibe a opção: [1] Nome_da_Habilidade (Dano Min-Max)
            printf("[%d] %s (Dano: %d - %d)\n", 
                       i + 1, 
                       heroi->skills[i].nome, 
                       heroi->skills[i].danoMinimo, 
                       heroi->skills[i].danoMaximo);
        }
        // NOVO: Opção de Poção
        printf("[4] POÇÃO (Aumenta Vida, Ataque ou Defesa)\n"); 
        
        printf("[5] SAIR (Apenas para teste, remova depois)\n"); // ATUALIZADO: Opção de sair é agora 5
        printf("--------------------------------------------------\n");
        
        mudarCor(14); // Cor Amarela para a entrada
        printf("Opcao: ");
        int escolha;
        scanf("%d", &escolha);
        limparBuffer(); // Limpa o buffer após o scanf
        mudarCor(7);

        if (escolha >= 1 && escolha <= 3) {
            // HABILIDADE ESCOLHIDA (Turno de Ataque)
            habilidade skill = heroi->skills[escolha - 1];

            // 2. CALCULAR O DANO ALEATÓRIO
            int danoBruto = rand() % (skill.danoMaximo - skill.danoMinimo + 1) + skill.danoMinimo;
            
            // Dano com Redução de Defesa
            int danoCausado = danoBruto - monstroAtual.defesaMonstros;
            if (danoCausado < 1) danoCausado = 1;

            mudarCor(11); // Cor Azul Claro
            printf("\n%s usou %s e causou %d de dano em %s!\n", 
                       heroi->nick, skill.nome, danoCausado, monstroAtual.nomeDosMonstros);
            mudarCor(7);
            
            // 3. APLICA O DANO
            vidaMonstroAtual -= danoCausado;
            Sleep(200); // Pausa para o jogador ver o resultado
            
            // 4. TURNO DO MONSTRO (se ainda estiver vivo)
            if (vidaMonstroAtual > 0) {
                // Cálculo de dano simplificado do monstro 
                int danoRecebido = monstroAtual.ataqueMonstros; 

                // Redução de Dano (dano mínimo de 1)
                danoRecebido -= heroi->defesa; 
                if (danoRecebido < 1) danoRecebido = 1;

                mudarCor(4); // Cor Vermelha
                printf("%s atacou e você recebeu %d de dano!\n", 
                           monstroAtual.nomeDosMonstros, danoRecebido);
                mudarCor(7);
                
                // Aplica o dano no herói
                heroi->vidaAtual -= danoRecebido; // ATUALIZADO: Usando vidaAtual
                Sleep(200);
            }
        } else if (escolha == 4) {
            // NOVO: MENU DE POÇÕES
            menuPorcoes(heroi);
            continue; // Volta ao início do loop para manter o turno do jogador
        } else if (escolha == 5) {
            printf("Saindo do combate de teste.\n");
            break;
        } else {
            mudarCor(4);
            printf("Opção inválida. Tente novamente.\n");
            mudarCor(7);
            Sleep(100);
        }
    }
    
    // FIM DA LUTA
    system("CLS");
    printf("==================================================\n");
    char logMensagem[150];
    
    if (heroi->vidaAtual <= 0) { // ATUALIZADO: Usando vidaAtual
        // --- LOG DE DERROTA ---
        mudarCor(4);
        printf("VOCÊ FOI DERROTADO!\n");
        
        // Monta a mensagem: Heroi foi morto por Monstro
        sprintf(logMensagem, "MORREU para o %s.", monstroAtual.nomeDosMonstros);
        salvarLogBatalha(heroi->nick, logMensagem);
        
        gameOver();
        desenvolvedores();
    } else if (vidaMonstroAtual <= 0) {
        // --- LOG DE VITÓRIA ---
        mudarCor(10);
        venceu();
        printf("VITÓRIA! O %s foi derrotado!\n", monstroAtual.nomeDosMonstros);
        
        // Monta a mensagem: Heroi matou Monstro. Vida restante: [Vida]
        // ATUALIZADO: Usando vidaAtual/vidaMaxima para o log
        sprintf(logMensagem, "DERROTOU o %s. Vida restante: %d/%d.", 
                    monstroAtual.nomeDosMonstros, heroi->vidaAtual, heroi->vidaMaxima); 
        salvarLogBatalha(heroi->nick, logMensagem);
        
        Sleep(2000);
    }
    mudarCor(7);
    printf("=====================================================\n");
}

void salvarLogBatalha(const char *nick, const char *mensagem) {
    // Definimos o mesmo nome de arquivo que você já usa para o herói
    const char *NOME_ARQUIVO = "log_do_jogo.txt";
    FILE *arquivo = fopen(NOME_ARQUIVO, "a");

    if (arquivo == NULL) {
        printf("ERRO DE LOG: Nao foi possivel abrir o arquivo '%s' para log de batalha.\n", NOME_ARQUIVO);
        return;
    }

    // 1. Obtém a hora atual para o registro
    time_t timer;
    char buffer[26];
    struct tm* tm_info;
    time(&timer);
    tm_info = localtime(&timer);
    // Formata a data/hora: [YYYY-MM-DD HH:MM:SS]
    strftime(buffer, 26, "[%Y-%m-%d %H:%M:%S]", tm_info);

    // 2. Escreve a linha formatada no arquivo
    // Formato: [DATA HORA] [NICK] MENSAGEM
    fprintf(arquivo, "%s [%s]: %s\n", buffer, nick, mensagem);

    // 3. Fecha o arquivo
    fclose(arquivo);
}

typedef struct {
    char nome[50];
    int aumentoVida;
    int aumentoAtaque;
    int aumentoDefesa;
} porcao;

porcao listaPorcoes[] = {
    // Porção 1: Grande Poção de Vida
    {"Poção do Elan Vital", 600, 0, 0},
    // Porção 2: Poção de Força
    {"Poção de Força Extrema", 0, 400, 0},
    // Porção 3: Elixir de Defesa
    {"Elixir de Defesa Sólida", 0, 0, 200},
    // Poção 4: Poção Mista (Exemplo extra)
    {"Poção Completa", 300, 200, 100}
};

const int NUM_PORCOES = sizeof(listaPorcoes) / sizeof(listaPorcoes[0]);

void aplicarPorcao(struct usuario *heroi, int idPorcao) {
    porcao p = listaPorcoes[idPorcao];
    
    // Aplica a Cura (limitada à vida máxima)
    if (p.aumentoVida > 0) {
        int vidaAnterior = heroi->vidaAtual;
        heroi->vidaAtual += p.aumentoVida;
        if (heroi->vidaAtual > heroi->vidaMaxima) {
            heroi->vidaAtual = heroi->vidaMaxima;
        }
        printf("\n[ITEM] %s restaurou %d de VIDA! (Vida: %d/%d)\n", 
               p.nome, heroi->vidaAtual - vidaAnterior, heroi->vidaAtual, heroi->vidaMaxima);
    }
    
    // Aplica Aumento de Ataque
    if (p.aumentoAtaque > 0) {
        heroi->ataque += p.aumentoAtaque;
        printf("[ITEM] %s aumentou seu ATAQUE em %d! (Ataque total: %d)\n", 
               p.nome, p.aumentoAtaque, heroi->ataque);
    }
    
    // Aplica Aumento de Defesa
    if (p.aumentoDefesa > 0) {
        heroi->defesa += p.aumentoDefesa;
        printf("[ITEM] %s aumentou sua DEFESA em %d! (Defesa total: %d)\n", 
               p.nome, p.aumentoDefesa, heroi->defesa);
    }
    
    Sleep(1000);
}

// O limite total de poções
#define LIMITE_USO_PORCAO 2

void DesenhoPorcao(){
	    const char *arte[] = {
        "              _________",
        "             {_________}",
        "              )=======(",
        "             /         \\",
        "            | _________ |",
        "            ||   _     ||",
        "            ||  |_)    ||",
        "            ||  | \\/   ||",
        "      __    ||    /\\   ||",
        " __  (_|)   |'---------'|",
        "(_|)     jgs`-.........-'"
    };

    // Imprime a arte
    mudarCor(8);
    int i;
    for (i = 0; i < 10; i++) {
        printf("%s\n", arte[i]);
    }
	mudarCor(7);
}


void menuPorcoes(struct usuario *heroi) {
    int escolha_porcao;
    
    system("CLS");
    mudarCor(2); // Amarelo
    printf("==================================================\n");
    printf("              MENU DE POÇÕES                      \n");
    printf("==================================================\n");
    DesenhoPorcao();
    // NOVO: Exibe o contador de uso
    printf("\nUSOS DE POÇÕES: %d de %d restantes\n", heroi->usosPocao, LIMITE_USO_PORCAO - heroi->usosPocao);
    printf("ATRIBUTOS ATUAIS: Vida: %d/%d | Atq: %d | Def: %d\n", 
           heroi->vidaAtual, heroi->vidaMaxima, heroi->ataque, heroi->defesa);
    printf("--------------------------------------------------\n");

    // Mostra a lista de poções
    mudarCor(9);
    int i;
    for (i = 0; i < NUM_PORCOES; i++) {
        porcao p = listaPorcoes[i];
        printf("[%d] %s: ", i + 1, p.nome);
        if (p.aumentoVida > 0) printf("Cura +%d Vida ", p.aumentoVida);
        if (p.aumentoAtaque > 0) printf("Ataque +%d ", p.aumentoAtaque);
        if (p.aumentoDefesa > 0) printf("Defesa +%d ", p.aumentoDefesa);
        printf("\n");
    }
    
    printf("[0] VOLTAR PARA A BATALHA\n");
    printf("--------------------------------------------------\n");
    mudarCor(7);
    
    printf("Escolha uma poção (1 a %d) ou [0] para voltar: ", NUM_PORCOES);
    
    if (scanf("%d", &escolha_porcao) != 1) {
        limparBuffer();
        mudarCor(4); printf("Escolha inválida. Voltando...\n"); mudarCor(7);
        Sleep(500);
        return; // Volta para a luta
    }
    limparBuffer();

    if (escolha_porcao == 0) {
        return; // Volta para a batalha
    }

    if (escolha_porcao >= 1 && escolha_porcao <= NUM_PORCOES) {
        
        // 1. VERIFICA O LIMITE
        if (heroi->usosPocao >= LIMITE_USO_PORCAO) {
            mudarCor(4);
            printf("\n[ATENÇÃO] Você já usou o número máximo de %d poções!\n", LIMITE_USO_PORCAO);
            mudarCor(7);
            Sleep(1500);
            return; // Impede o uso e volta
        }

        // 2. APLICA A POÇÃO
        aplicarPorcao(heroi, escolha_porcao - 1); // idPorcao é o índice (0 a N-1)
        
        // 3. ATUALIZA O CONTADOR
        heroi->usosPocao++; 
        
        // 4. LOG DE USO
        salvarLogPorcao(heroi->nick, listaPorcoes[escolha_porcao - 1].nome, heroi->usosPocao);

        // O turno do jogador não termina aqui, ele volta para o início do loop da batalha 
        // para escolher a próxima ação (ataque ou poção, que agora estará bloqueada se for a 3ª vez).
        return;
        
    } else {
        mudarCor(4); printf("Opção inválida. Tente novamente.\n"); mudarCor(7);
        Sleep(500);
    }
}


void salvarLogPorcao(const char *nick, const char *nomePorcao, int usoAtual) {
    const char *NOME_ARQUIVO = "log_do_jogo.txt";
    FILE *arquivo = fopen(NOME_ARQUIVO, "a");

    if (arquivo == NULL) {
        printf("ERRO DE LOG: Nao foi possivel abrir o arquivo '%s' para log de porcao.\n", NOME_ARQUIVO);
        return;
    }

    time_t timer;
    char buffer[26];
    struct tm* tm_info;
    time(&timer);
    tm_info = localtime(&timer);
    strftime(buffer, 26, "[%Y-%m-%d %H:%M:%S]", tm_info);

    // MENSAGEM DO LOG: [DATA HORA] [NICK] USOU PorcaoNome (Uso: X/2)
    fprintf(arquivo, "%s [%s]: USOU %s (Uso: %d/2).\n", buffer, nick, nomePorcao, usoAtual);

    fclose(arquivo);
}



int main() {
	_getch();
	
	int monstrosDerrotados = 0;
	SetConsoleOutputCP(1252);
	char nick_maiusculo[100];
	bool nomeValido = false;
	srand((unsigned)time(NULL));
	const int MONSTROS_NECESSARIOS_PARA_VITORIA = 2;
	
	struct usuario meuHeroi;
	strcpy(meuHeroi.nick, "Aventureiro");
	
	printf("Versão 2.6.5");
	Sleep(1000);
	system("CLS");
	
	uern();
	desenvolvedores2();
	Sleep(500);
	projetoRpg();
	Sleep(500);
	
	introducao();

	system("CLS");

	
	while(!nomeValido){
		mudarCor(2);
		printf("\nQual é o seu nick de batalha:	");
		fgets(meuHeroi.nick, sizeof(meuHeroi.nick), stdin);
		meuHeroi.nick[strcspn(meuHeroi.nick, "\n\r")] = '\0';
		
		int i;
		strcpy(nick_maiusculo, meuHeroi.nick);
		for (i = 0; nick_maiusculo[i] != '\0'; i++) {
        	nick_maiusculo[i] = toupper(nick_maiusculo[i]);
    	}
		
		if (strchr(meuHeroi.nick, ' ') != NULL) {
			mudarCor(4);
            printf("ERRO: O nick nao pode conter espacos. Tente novamente.\n\n");   
        } else if (strlen(meuHeroi.nick) == 0) {
        	mudarCor(4);
            printf("ERRO: O nick nao pode estar vazio. Tente novamente.\n\n");
        } else {
        	mudarCor(2);
            nomeValido = true;
            mudarCor(7);
        
        }
	}
	
	mudarCor(2);
	print_animado("Bem vindo jogador: ", 1);
	mudarCor(3);
	printf("%s\n\n", nick_maiusculo);
	Sleep(500);

	
   
    int classe_selecionada = loopClasses();
    atribuirEInicializarHeroi(classe_selecionada, &meuHeroi);
	const char *NOME_ARQUIVO = "historico_jogador.txt";
	atribuirClasse(&meuHeroi, classe_selecionada);
	printf("\nHeroi pronto para o combate! Atributos salvos.\n");
	_getch();
	
	Sleep(1000);
	system("CLS");
	
	//lutar(&meuHeroi, 0);
	

	//while (meuHeroi.vida > 0 && monstrosDerrotados < 4)
	while (meuHeroi.vidaAtual > 0 && monstrosDerrotados < MONSTROS_NECESSARIOS_PARA_VITORIA) { 
        
        int numeroSorteado = rand0a4(); // Sorteia o monstro (0 a 4)
    
        printf("==================================================\n");
        mudarCor(14); // Amarelo
        printf("UM NOVO MONSTRO APARECEU! É um %s.\n", listaDeMonstros[numeroSorteado].nomeDosMonstros);
        mudarCor(7);
        printf("Pressione uma tecla para encarar o desafio...\n");
        getch(); // Espera o jogador apertar para começar
        system("CLS");
    
        lutar(&meuHeroi, numeroSorteado);
        
        
        // ----------------------------------------------------
        // LÓGICA PÓS-LUTA
        // ----------------------------------------------------
    
        // Se a função 'lutar' retornar e o herói ainda estiver vivo
        if (meuHeroi.vidaAtual > 0) {
            monstrosDerrotados++; // Aumenta a contagem de derrotados
            
            // VERIFICA SE O JOGO DEVE PARAR POR CAUSA DA VITÓRIA TOTAL
            if (monstrosDerrotados >= MONSTROS_NECESSARIOS_PARA_VITORIA) {
                 mudarCor(10); // Verde
                 printf("FIM DA AVENTURA! Você atingiu seu objetivo de derrotar %d monstros.\n", MONSTROS_NECESSARIOS_PARA_VITORIA);
                 desenvolvedores();
                 Sleep(200);
                 break; // Sai do loop para ir para a tela de vitória final
            }
            
            mudarCor(10); // Verde
            printf("VITÓRIA! Você derrotou %d/%d monstros. Vida restante: %d\n", monstrosDerrotados, MONSTROS_NECESSARIOS_PARA_VITORIA, meuHeroi.vidaAtual);
            mudarCor(7);
            printf("Aventureiro(a) incansável, prepare-se para o próximo inimigo!\n");
            Sleep(200);
            system("CLS");
        } else {
            // Se a vida for <= 0, o loop será quebrado na próxima iteração
            break;  
        }
    }
		
	//contagem_dois();
	
	
	//_getch();
	
	
	/*
	mostrarDadosDoCao();
	mostrarDadosDoOrc();
	mostrarDadosDoEsqueleto();
	mostrarDadosDoDragao();
	mostrarDadosDoDraconetos();
	*/
	
	

    return 0;
}





	

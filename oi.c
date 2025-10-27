#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>


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
    printf("| VIDA: 1500                        |\n");
    printf("| ATAQUE F�SICO: 400                |\n");
    printf("| DEFESA: 150                       |\n");
    printf("=====================================\n");
    mudarCor(7);
}

void apresentacaoMago() {
	mudarCor(2);
    printf("=====================================\n");
    printf("|           FICHA DE RPG            |\n");
    printf("=====================================\n");
    printf("| 01 - CLASSE: MAGO                 |\n");
    printf("| VIDA: 600                         |\n");
    printf("| ATAQUE M�GICO: 600                |\n");
    printf("| DEFESA: 250                       |\n");
    printf("=====================================\n");
    mudarCor(7);
}

void apresentacaoArqueiro() {
	mudarCor(2);
    printf("=====================================\n");
    printf("|           FICHA DE RPG            |\n");
    printf("=====================================\n");
    printf("| 02 - CLASSE: ARQUEIRO             |\n");
    printf("| VIDA: 900                         |\n");
    printf("| ATAQUE M�GICO: 600                |\n");
    printf("| DEFESA: 50                       |\n");
    printf("=====================================\n");
    mudarCor(7);
}

void apresentacaoSuporte() {
	mudarCor(2);
    printf("=====================================\n");
    printf("|           FICHA DE RPG            |\n");
    printf("=====================================\n");
    printf("| 03 - CLASSE: SUPORTE              |\n");
    printf("| VIDA: 550                         |\n");
    printf("| ATAQUE M�GICO: 350                |\n");
    printf("| DEFESA: 500                       |\n");
    printf("=====================================\n");
    mudarCor(7);
}



void loopClasses() {
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
    printf("VOC� SELECIONOU A CLASSE (ID): %d\n", estado_atual);
    

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
}



void uern() {
	const char *arte[] = {
	    " __    __   _______ .______      .__    __. ", 
	    "|  |  |  | |   ____||   _  \\     |  \\ |  | ",
	    "|  |  |  | |  |__   |  |_)  |    |   \\|  | ",
	    "|  |  |  | |   __|  |      /     |  . `  | ",
	    "|  `--'  | |  |____ |  |\\  \\----.|  |\\   | ", 
	    " \\______/  |_______|| _| `._____||__| \\__| ",
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
	    "Ap�s longas jornadas e perigos desconhecidos, voc� finalmente",
	    "chega ao ponto crucial da sua aventura. Agora, a hora chegou:",
	    "� o momento de decidir seu destino, seu caminho, sua identidade!",
	    "",
	    "Her�i ou hero�na, guerreiro(a) ou s�bio(a), o mundo espera pelo",
	    "nome que carregar� na gl�ria das batalhas e nas lendas que surgir�o.",
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
		print_animado("Mudando para a tela de sele��o de agente em: ", 1);
		printf("%d", contador);
		print_animado(" segundos\n", contador);
		Sleep(500);
	}
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
	SetConsoleOutputCP(1252);
	
	struct usuario jogador;
	struct monstros tiposMonstros[6];
	char nick_maiusculo[100];
	bool nomeValido = false;
	
	printf("Vers�o 1.2.5");
	Sleep(1000);
	system("CLS");
	
	
	uern();
	Sleep(500);
	projetoRpg();
	Sleep(500);
	introducao();
	
	while(!nomeValido){
		mudarCor(2);
		printf("Qual � o seu nick de batalha:	");
		fgets(jogador.nick, sizeof(jogador.nick), stdin);
		jogador.nick[strcspn(jogador.nick, "\n\r")] = '\0';
		
		int i;
		strcpy(nick_maiusculo, jogador.nick);
		for (i = 0; nick_maiusculo[i] != '\0'; i++) {
        	nick_maiusculo[i] = toupper(nick_maiusculo[i]);
    	}
		
		if (strchr(jogador.nick, ' ') != NULL) {
			mudarCor(4);
            printf("ERRO: O nick nao pode conter espacos. Tente novamente.\n\n");   
        } else if (strlen(jogador.nick) == 0) {
        	mudarCor(4);
            printf("ERRO: O nick nao pode estar vazio. Tente novamente.\n\n");
        } else {
        	mudarCor(2);
            nomeValido = true;
            mudarCor(7);
        }
	}
	
	system("CLS");
	
	mudarCor(2);
	print_animado("Bem vindo jogador: ", 1);
	mudarCor(3);
	printf("%s\n\n", nick_maiusculo);
	Sleep(500);
	
	
	contagem();
	
	mudarCor(2);
	
	print_animado("\nPressione qualquer tecla para ir para a sele��o de agente:", 1);
	_getch();
	
	
    loopClasses();

    printf("\nPrograma finalizado. Pressione qualquer tecla para fechar.\n");
    getch();
    return 0;
}







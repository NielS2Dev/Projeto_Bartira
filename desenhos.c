#include <stdio.h>
#include "cores.h"
#include "animacao.h"

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


    mudarCor(8);
    int i;
    for (i = 0; i < 10; i++) {
        printf("%s\n", arte[i]);
    }
	mudarCor(7);
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

// SÓ UMA ANOTAÇÃO QUALQUER PARA RESOVLER UM PROBLEMINHA DO MEU COMPUTADOR.







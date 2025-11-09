#include <stdio.h>
#include <stdlib.h> // Adicionado para system()
#include "cores.h"
#include "animacao.h"
// É necessário que 'Sleep' seja definido aqui ou em 'animacao.h'
// Exemplo: #define Sleep(ms) usleep((ms) * 1000) e #include <unistd.h>

void guerreiro() {
	mudarCor(6);
    printf("A           {}\n");
    printf(" / \\, | ,        .--.\n");
    printf("|    =|= >      /.--.\\\n");
    printf(" \\ /` | `       |====|\n");
    printf("  `   |         |`::`|  \n");
    printf("      |     .-;`\\..../`;_.-^-._\n");
    printf("     /\\\\/  /  |...::..|`   :   `|\n");
    printf("     |:'\\ |   /'''::''|   .:.   |\n");
    printf("      \\ /\\;-,/\\   :: |..:UERN:..|\n");
    printf("      |\\ <` >  >._::_.| ':::::' |\n");
    printf("      | `\"\"`  /   ^^  |   ':'   |\n");
    printf("      |       |       \\    :    /\n");
    printf("      |       |        \\   :   / \n");
    printf("      |       |___/\\___|`-.:.-`\n");
    printf("      |        \\_ || _/    `\n");
    printf("      |        <_ >< _>\n");
    printf("      |        |  ||  |\n");
    printf("      |        |  ||  |\n");
    printf("      |       _\\.:||:./_\n");
    printf("      | RN  /____/\\____\\\n");
    mudarCor(7);
}

void mago() {
	mudarCor(6);
    printf("              _,._      \n");
    printf("  .||,       /_ _\\\\     \n");
    printf(" \\.`',/      |'L'| |    \n");
    printf(" = ,. =      | -,| L    \n");
    printf(" / || \\    ,-'\\\"/,'`.   \n");
    printf("   ||     ,'   `,,. `.  \n");
    printf("   ,|____,' , ,;' \\| |  \n");
    printf("  (3|\\    _/|/'   _| |  \n");
    printf("   ||/,-''  | >-'' _,\\\\ \n");
    printf("   ||'      ==\\ ,-'  ,' \n");
    printf("   ||       |  V \\ ,|   \n");
    printf("   ||       |    |` |   \n");
    printf("   ||       |    |   \\  \n");
    printf("   ||       |    \\    \\ \n");
    printf("   ||       |     |    \\\n");
    printf("   ||       |      \\_,-'\n");
    printf("   ||       |___,,--\")_\\\\\n");
    printf("   ||         |_|   ccc/\n");
    printf("   ||        ccc/       \n");
    printf("   ||             \n");
    mudarCor(2);
}

void arqueiro() {
	mudarCor(6);
    printf("            /`.                       \n");
    printf("           /   :.                        _\n");
    printf("          /     \\\\                      | |\n");
    printf("       ,;/,      ::              >>>>---: |> \n");
    printf("   ___:c/.(      ||                     | |\n");
    printf(" ,'  _|:)>>>--,-'B)>                    | |\n");
    printf("(  '---'\\--'` _,'||                     | |\n");
    printf(" `--.    \\ ,-'   ;;                     | |\n");
    printf("     |    \\|    //                  ,>-.| |\n");
    printf("     |     \\   ;'                  ^    |_|\n");
    printf("     |_____|'\\,'                          |\n");
    printf("     :     :                             |\n");
    printf("     |  ,  |                             |\n");
    printf("     | : \\ :                             |\n");
    printf("     | | : :                             |\n");
    printf("     | | | |                            /|\\\n");
    printf("     | | |_`.  jah/SSt                 / | \\\n");
    printf("     '--`                             /  |  \\\n");
    printf("                                         '\n");
    mudarCor(2);
}

void suporte() {
	mudarCor(6);
    printf("             _,._\n");
    printf("           ,'   ,`-.\n");
    printf("|.        /     |\\  `.\n");
    printf("\\ \\      (  ,-,-` ). `-._ __\n");
    printf(" \\ \\      \\|\\,'     `\\  /'  `\\\n");
    printf("  \\ \\      ` |, ,  /  \\ \\     \\\n");
    printf("   \\ \\         `,_/`, /\\,`-.__/`.\n");
    printf("    \\ \\            | ` /    /    `-._\n");
    printf("     \\\\\\           `-/'    /         `-.\n");
    printf("      \\\\`/ _______,-/_   /'             \\\n");
    printf("     ---'`|       |`  ),' `---.  ,       |\n");
    printf("      \\..-`--..___|_,/          /       /\n");
    printf("                 |    |`,-,...,/      ,'     \n");
    printf("                 \\    | |_|   /     ,' __  r-'',\n");
    printf("                  |___|/  |, /  __ /-''  `'`)  |  \n");
    printf("               _,-'   ||__\\ /,-' /     _,.--|  (\n");
    printf("            .-'       )   `(_   / _,.-'  ,-' _,/\n");
    printf("             `-------'       `--''       `'''\n");
    mudarCor(2);
}


void apresentacaoGuerreiro() {
	mudarCor(2);
    printf("=====================================\n");
    printf("|           FICHA DE RPG            |\n");
    printf("=====================================\n");
    printf("| 00 - CLASSE: GUERREIRO            |\n");
    printf("| ATAQUE FÍSICO: 400                |\n");
    printf("| DEFESA: 150                       |\n");
    printf("| VIDA: 1500                        |\n");
    printf("=====================================\n");
    mudarCor(7);
}

void apresentacaoMago() {
	mudarCor(2);
    printf("=====================================\n");
    printf("|           FICHA DE RPG            |\n");
    printf("=====================================\n");
    printf("| 01 - CLASSE: MAGO                 |\n");
    printf("| ATAQUE MÁGICO: 600                |\n");
    printf("| DEFESA: 250                       |\n");
    printf("| VIDA: 600                         |\n");
    printf("=====================================\n");
    mudarCor(7);
}

void apresentacaoArqueiro() {
	mudarCor(2);
    printf("=====================================\n");
    printf("|           FICHA DE RPG            |\n");
    printf("=====================================\n");
    printf("| 02 - CLASSE: ARQUEIRO             |\n");
    printf("| ATAQUE MÁGICO: 600                |\n");
    printf("| DEFESA: 50                       |\n");
    printf("| VIDA: 900                         |\n");
    printf("=====================================\n");
    mudarCor(7);
}

void apresentacaoSuporte() {
	mudarCor(2);
    printf("=====================================\n");
    printf("|           FICHA DE RPG            |\n");
    printf("=====================================\n");
    printf("| 03 - CLASSE: SUPORTE              |\n");
    printf("| ATAQUE MÁGICO: 350                |\n");
    printf("| DEFESA: 500                       |\n");
    printf("| VIDA: 550                         |\n");
    printf("=====================================\n");
    mudarCor(7);
}

void DesenhoPorcao(){
	    const char *arte[] = {
        "              _________",
        "             {_________}",
        "              )=======(",
        "             /         \\",
        "            | _________ |",
        "            ||   _     ||",
        "            ||  |_)    ||",
        "            ||  | \\/   ||",
        "      __    ||    /\\   ||",
        " __  (_|)   |'---------'|",
        "(_|)     jgs`-.........-'"
    };


    mudarCor(8);
    int i;
    for (i = 0; i < 11; i++) { // Alterado para 11, pois há 11 linhas no array
        printf("%s\n", arte[i]);
    }
	mudarCor(7);
}

void uern() {
const char* arte[] = {
    " _   _ _____ ____  _   _       ____  _   _  ",
    "| | | | ____|  _ \\| \\ | |     |  _ \\| \\ | | ",
    "| | | |  _| | |_) |  \\| |_____| |_) |  \\| | ",
    "| |_| | |___|  _ <| |\\  |_____|  _ <| |\\  | ",
    " \\___/|_____|_| \\_\\_| \\_|     |_| \\_\\_| \\_| "
};
    int num_linhas = sizeof(arte) / sizeof(arte[0]);
    
    mudarCor(3);
    print_animado_multilinha(arte, num_linhas, 30);
    mudarCor(7);
    printf("\n"); 
}


void projetoRpg() {
    const char *arte[] = {
        "  ____            _      _          ____  ____   ____ ",
        " |  _ \\ _ __ ___ (_) ___| |_ ___   |  _ \\|  _ \\ / ___|",
        " | |_) | '__/ _ \\| |/ _ \\ __/ _ \\  | |_) | |_) | |  _ ",
        " |  __/| | | (_) | |  __/ || (_) | |  _ <|  __/| |_| |",
        " |_|   |_|  \\___// |\\___|\\__\\___/  |_| \\_\\_|    \\____|",
        "               |__/                                    "
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
	    "                 Bem-vindo ao bravo mundo de RPG!            ",
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
	system("clear"); // ALTERADO: CLS -> clear
}

void venceu(){
	const char *arte[] = {
	    "      __  __                 _                   ",
	    "    |  \\/  | ___  _ __  ___| |_ _ __ ___        ",
	    "    | |\\/| |/ _ \\| '_ \\/ __| __| '__/ _ \\       ",
	    "    | |  | | (_) | | | \\__ \\ |_| | | (_) |      ",
	    " ___|_|  |_|\\___/|_| |_|___/\\__|_|  \\___/       ",
	    "|  _ \\  ___ _ __ _ __ ___ | |_ __ _  __| | ___  ",
	    "| | | |/ _ \\ '__| '__/ _ \\| __/ _` |/ _` |/ _ \\ ",
	    "| |_| |  __/ |  | | | (_) | || (_| | (_| | (_) |",
	    "|____/ \\___|_|  |_|  \\___/ \\__\\__,_|\\__,_|\\___/ "
	};
    int num_linhas = sizeof(arte) / sizeof(arte[0]);
    
    mudarCor(3);
    print_animado_multilinha(arte, num_linhas, 30);
    mudarCor(7);
    printf("\n");  
}

void gameOver(){
	const char *arte[] = {
	    "  _______      ___      .___  ___.  _______   ",
	    " /  _____|    /   \\     |   \\/   | |   ____|  ",
	    "|  |  __     /  ^  \\    |  \\  /  | |  |__     ",
	    "|  | |_ |   /  /\\_/  \\   |  |\\/|  | |   __|    ",
	    "|  |__| |  /  _____  \\  |  |  |  | |  |____   ",
	    " \\______| /__/     \\__\\ |__|  |__| |_______|  ",
	    "                                              ",
	    "  ______   ____    ____  _______ .______      ",
	    " /  __  \\  \\   \\  /   / |   ____||   _  \\     ",
	    "|  |  |  |  \\   \\/   /  |  |__   |  |_)  |    ",
	    "|  |  |  |   \\      /   |   __|  |      /     ",
	    "|  `--'  |    \\    /    |  |____ |  |\\  \\----.",
	    " \\______/      \\__/     |_______|| _| `._____|",
	    "                                              "
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
	    "                 Jogo desenvolvido pelos alunos(as):          ",
	    "                 Antoniel da Silva Alves                      ",
	    "                 Pedro Henrique Da Silva Dias                 ",
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
	    "                 Jogo desenvolvido pelos alunos(as):          ",
	    "                 Antoniel da Silva Alves                      ",
	    "                 Pedro Henrique Da Silva Dias                 ",
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

void desenharCaoAssassino() {
	    // Cole as linhas do desenho do Cão Assassino aqui, cada uma em um printf
	    printf("        __.                                                  \n");
	    printf("      .-\".'                  .--.            _..._          \n");
	    printf("    .' .'                   .'    \\      .-\"\"  __ \"\"-.      \n");
	    printf("    /  /                   .'      : --..:__.-\"\"  \"\"-:. \\\n");
	    printf("  :  :                   /        ;.d$$    sbp_.-\"\"-:_:\n");
	    printf("  ;  :                   : ._      :P .-.  ,\"TP          \n");
	    printf("  :   \\                   \\  T--...-; : d$b  :d$b          \n");
	    printf("    \\   `.                  \\  `..'    ; $ $  ;$ $          \n");
	    printf("     `.   \"-.                ).        : T$P  :T$P          \n");
	    printf("       \\..---^..            /            `-'    `._`._      \n");
	    printf("      .'         \"-.      .-\"                  T$$$b    \n");
	    printf("    /             \"-._.-\"              ._    '^' ;    \n");
	    printf("    :                                    \\.`.        /    \n");
	    printf("    ;                                  -.  \\`.\"-._.-'-'    \n");
	    printf("  :                                   .'\\   \\ \\ \\ \\        \n");
	    printf("  ; ;                                 /:  \\   \\ \\ . ;      \n");
	    printf(" :  :                                , ;  `. `.;  :      \n");
	    printf(" ;  \\       ;           ;    \"-._:  ;      \n");
	    printf(" :    `.      :           :          \\/        \n");
	    printf(" ;    /\"-.    ;           :                 \n");
	    printf(" :    /   \"-. :         : ;                 \n");
	    printf(" :   .'     T-;         ; ;         \n");
	    printf(" ;  :         ; ;       /  :         \n");
	    printf(" ;  ;         : :     .'    ;        \n");
	    printf(":  :          ;:   _..-\"\\    :        \n");
	    printf(":    \\          : ; /    \\    ;      \n");
	    printf(";  . '.         '-; /      ;    :        \n");
	    printf("; \\ ; :           : :    CÃO   ;    . `. \n"); // Ajustei para CÃO, mas pode deixar como quiser
	    printf("'.._L.:-'           : :      : \\ ; :  \n");
	    printf("                       : '-..    '.._L.:-'  \n");
	    printf("                       ;   , `.             \n");
	    printf("                       :   \\ ; :             \n");
	    printf("                       '..__L.:-'\n");
	    printf("--------------------------------------------------\n"); // Separador
}

void desenharOrc() {
    // Cole as linhas do desenho do Orc aqui
    printf("          ) )( (                        ( ) )( (\n");
    printf("        ( ( ( )  ) )                    ( (  ( ) )(\n");
    printf("      ) )    ,,\\\\\\                    ///,,      ) (\n");
    printf("    (  ((  (\\\\\\\\//                        \\\\\\\\////)    )\n");
    printf("     ) )  (-(__//                          \\\\__)-)    (\n");
    printf("    (((  ((-(__||                          ||__)-))    ) )\n");
    printf("  ) )  ((-(-(_||          ```\\__          ||_)-)-))    ((\n");
    printf("  ((  ((-(-(/(/\\\\      ''; 9.- `        //\\\\)\\)-)-))    )\n");
    printf("   )  (-(-(/(/(/\\\\    '';;;;-\\~        //\\\\)\\)\\)-)-)    (  )\n");
    printf("(  (  ((-(-(/(/(/\\======,:;:;:;:,======/\\\\)\\)\\)-)-))    )\n");
    printf("   )  '(((-(/(/(/(//////:%%%%%%%:\\\\\\\\\\)\\)\\)\\)-)))`  ( (\n");
    printf("  ((  '((-(/(/(/('uuuu:WWWWWWWWW:uuuu`)\\)\\)\\)-))`    )\n");
    printf("    ))  '((-(/(/(/('|||:wwwwwwwww:|||')\\)\\)\\)-))`    ((\n");
    printf("(    ((    '((((/(/('uuu:WWWWWWWWW:uuu`)\\)\\))))`      ))\n");
    printf("      ))    '':::UUUUUU:wwwwwwwww:UUUUUU:::``      ((  )\n");
    printf("        ((      '''''\\uuuuuuuu/``````          ))\n");
    printf("          ))          `JJJJJJJJJ`            ((\n");
    printf("            ((          LLLLLLLLLLL          ))\n");
    printf("              ))        ///|||||||\\\\\\        ((\n");
    printf("                ))      (/(/(/(^)\\)\\)\\)        ((\n");
    printf("                 ((                            ))\n");
    printf("                  ((                          ((\n");
    printf("                    ( )( ))( ( ( ) )( ) ((\n");
    printf("--------------------------------------------------\n"); // Separador
}

void desenharEsqueleto() {
    // Cole as linhas do desenho do Esqueleto aqui
    printf("_.--\"\"-._\n");
    printf("  .                         .\"         \".\n");
    printf(" / \\    ,^.         /(     Y             |      )\\\n");
    printf("/   `---. |--'\\    (  \\__..'--   -   -- -'\"\"-.-'  )\n");
    printf("|        :|    `>   '.     l_..-------.._l      .'\n");
    printf("|      __l;__ .'      \"-.__.||_.-'v'-._||`\"----\"\n");
    printf(" \\  .-' | |  `              l._       _.'\n");
    printf("  \\/    | |                   l`^^'^^'j\n");
    printf("        | |                _   \\_____/     _\n");
    printf("        j |               l `--__)-'(__.--' |\n");
    printf("        | |               | /`---``-----'\"1 |  ,-----.\n");
    printf("        | |               )/  `--' '---'   \\'-'  ___  `-.\n");
    printf("        | |              //  `-'  '`----'  /  ,-'   I`.  \\\n");
    printf("      _ L |_            //  `-.-.'`-----' /  /  |   |  `. \\\n");
    printf("     '._' / \\         _/(   `/   )- ---' ;  /__.J   L.__.\\ :\n");
    printf("      `._;/7(-.......'  /        ) (     |  |            | |\n");
    printf("      `._;l _'--------_/        )-'/     :  |___.    _._./ ;\n");
    printf("        | |                 .__ )-'\\  __  \\  \\  I   1   / /\n");
    printf("        `-'                /   `-\\-(-'   \\ \\  `.|   | ,' /\n");
	    printf("                           \\__  `-'    __/  `-. `---'',-'\n");
	    printf("                              )-._.-- (        `-----'\n");
	    printf("                             )(  l\\ o ('..-.\n");
	    printf("                       _..--' _'-' '--'.-. |\n");
	    printf("                __,,-'' _,,-''            \\ \\\n");
	    printf("               f'. _,,-'                   \\ \\\n");
	    printf("              ()--  |                       \\ \\\n");
	    printf("                \\.  |                       /  \\\n");
	    printf("                  \\ \\                      |._  |\n");
	    printf("                   \\ \\                     |  ()|\n");
	    printf("                    \\ \\                     \\  / \n");
	    printf("                     ) `-.                   | |\n");
	    printf("                    // .__)                  | |\n");
	    printf("                 _.//7'                      | |\n");
	    printf("               '---'                         j_| `\n");
	    printf("                                            (| |\n");
	    printf("                                             |  \\\n");
	    printf("                                             |lllj\n");
	    printf("                                             |||||  -nabis\n");
	    printf("--------------------------------------------------\n");
}

void desenharDragaoJovem() {
    // Cole as linhas do desenho do Dragão Jovem aqui
    printf("                               ,      /~/'  ,--,\n");
    printf("                              _/`, ,/'/'  /'/~\n");
    printf("                            .'___|/ /____/'/'    __/|\n");
    printf("                            /~  __        `\\ /~~, /'\n");
    printf("                      _,-,__/'  ,        \\  /'/~/ /'\n");
    printf("                    .~      `    \\_/  / ,    \"~_/'  ,-'~~~~~---,_\n");
    printf("                    `,          `~    `~~~|  /'    ~~\\__    `~\\_\n");
    printf("          |~~~/    `~---,__      _,    /'  | /~~\\  _/' ~~\\    `~,\n");
    printf("          |/\\`\\          /'    _,-~/    /'  .' __ `/'      `~\\    \\\n");
    printf("    |~~~/    `\\`\\      `-\\/\\/~  /'    .'    |    `| \\/    |    `\\_  |\n");
	    printf("    |/\\`\\      `,`\\          /'      |_  ,' /~\\ /' |' |  `\\      \\~\\|\n");
	    printf("      `\\`\\    _/~~_/~'          /'      /' ~~/    /    `\\ `\\,  | \\    |\n");
	    printf("~/      `\\`\\/~ _/~            ~/~~~~\\/'    `\\__/' \\/\\  `\\_/\\ `\\~~\\ |\n");
	    printf("\\`\\    _/~'    \\            /~~'                `~~~\\`~~~'    `~~'  `'__\n");
	    printf(" `\\`\\/~ _/~\\    `\\          /' _/                  `\\      _,-'~~ |\n");
	    printf("    `\\_/~    `\\    `\\      _|--'                    |    `\\    |'\n");
	    printf("              `\\    `\\  /'          _/'            |      /' /\\|'\n");
	    printf("                /\\/~~\\-/'        _,-'              |    /' /'  `\n");
	    printf("                |_`\\~~~/`\\      /~                  \\/~~' /'\n");
	    printf("                  |`\\~ \\ `\\    `\\                      `| /'\n");
	    printf("--------------------------------------------------\n"); // Separador
}

void desenharDraconato() {
    // Cole as linhas do desenho do Draconato (seu 5º monstro, a 'arma') aqui
    printf("                  \\ __\n");
    printf("--==/////////////[})))==*\n");
    printf("                  / \\ '\n");
    printf("                     `\\`\\      //|                      ,|\n");
    printf("                       \\ `\\  //,/'                  -~ |\n");
    printf("  )              _-~~~\\  |/ / |'|                _-~  / ,\n");
	    printf(" ((              /' )    | \\ / /'/            _-~    _/_-~|\n");
	    printf(" (((              ; /`    ' )/ /''          _ -~    _-~ ,/'\n");
	    printf(" ) ))            `~~\\    `\\\\/'/|'        __--~~__--\\ _-~ _/, \n");
	    printf("((( ))            / ~~    \\ /~      __--~~  --~~  __/~ _-~ /\n");
	    printf(" ((\\~\\            |    )    | '      /          __--~~ \\-~~ _-~\n");
	    printf("    `\\(\\    __--(    _/    |'\\      /        --~~    __--~' _-~ ~|\n");
	    printf("      ( ((~~    __-~      \\~\\    /      ___---~~ ~~\\~~__--~ \n");
	    printf("       ~~\\~~~~~~    `\\-~      \\~\\ /        __--~~~'~~/\n");
	    printf("                      ;\\ __.-~ ~-/      ~~~~~__\\__---~~ _..--._\n");
	    printf("                      ;;;;;;;;' /      ---~~~/_.-----.-~ _.._ ~\\      \n");
	    printf("                      ;;;;;;;'  /      ----~~/          `\\,~    `\\ \\          \n");
	    printf("                      ;;;;'    (      ---~~/          `:::|      `\\\\.      \n");
	    printf("                      |' _      `----~~~~'        /      `:|      ())))),      \n");
	    printf("            ______/\\/~    |                    /        /          (((((())  \n");
	    printf("          /~;;.____/;;'  /          ___.---(    `;;;/              )))'`))\n");
	    printf("          / //  _;______;'------~~~~~    |;;/\\    /                ((    ( \n");
	    printf("        //  \\ \\                      /  |  \\;;,\\                `    \n");
	    printf("        (<_    \\ \\                  /',/-----' _> \n");
	    printf("        \\_|      \\\\_              //~;~~~~~~~~~ \n");
	    printf("                   \\_|            (,~~  -Tua Xiong\n");
	    printf("                                                    \\~\\\n");
	    printf("--------------------------------------------------\n"); // Separador
}
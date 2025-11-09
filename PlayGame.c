#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

//Meus modulos xD
#include "cores.h"
#include "desenhos.h"
#include "monstro.h"
#include "playgame.h"
#include "combate.h"
#include "pocao.h"
#include "log.h"
#include "animacao.h"

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
	    mudarCor(11); 
	    
	    printf("Habilidades da Classe:\n");
	    int i;
	    for (i = 0; i < 3; i++) {

	        printf(" [%d] %s (Dano: %d - %d)\n", 
	               i + 1,
	               bancoDeSkills[estado_atual][i].nome,
	               bancoDeSkills[estado_atual][i].danoMinimo,
	               bancoDeSkills[estado_atual][i].danoMaximo);
	    }
	
	    mudarCor(7);
	    printf("====================================================\n");
	    printf("Pressione qualquer tecla para iniciar a aventura...\n");
	    getch(); 
	    
	return estado_atual;
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
        
        int numeroSorteado = rand0a4(); 
    
        printf("==================================================\n");
        mudarCor(14); // Amarelo
        printf("UM NOVO MONSTRO APARECEU! É um %s.\n", listaDeMonstros[numeroSorteado].nomeDosMonstros);
        mudarCor(7);
        printf("Pressione uma tecla para encarar o desafio...\n");
        getch(); 
        system("CLS");
    
        lutar(&meuHeroi, numeroSorteado);
        

        if (meuHeroi.vidaAtual > 0) {
            monstrosDerrotados++; 
            
          
            if (monstrosDerrotados >= MONSTROS_NECESSARIOS_PARA_VITORIA) {
                 mudarCor(10); 
                 printf("FIM DA AVENTURA! Você atingiu seu objetivo de derrotar %d monstros.\n", MONSTROS_NECESSARIOS_PARA_VITORIA);
                 desenvolvedores();
                 Sleep(200);
                 break;
            }
            
            mudarCor(10);
            printf("VITÓRIA! Você derrotou %d/%d monstros. Vida restante: %d\n", monstrosDerrotados, MONSTROS_NECESSARIOS_PARA_VITORIA, meuHeroi.vidaAtual);
            mudarCor(7);
            printf("Aventureiro(a) incansável, prepare-se para o próximo inimigo!\n");
            Sleep(200);
            system("CLS");
        } else {
           
            break;  
        }
    }
	
    return 0;
}





	

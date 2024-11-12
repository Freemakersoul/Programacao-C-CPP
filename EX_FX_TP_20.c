// Tiago Proenca - 2024-10-22

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 
	Definicao e incializacao de variveis 'globais' de trabalho
*/
char lnSep = '_';
int contador = 0;

// Tema leituras [Input]

void mudaLinha (void); //Prototipo
void meuCarimbo(void); //Prototipo

//	Funcao que muda de linha quando necessario
	void mudaLinha(void) {
		printf("\n");
	}
	
// int escreveLinha(int numVezes)
	void escreveLinha()
	{
		contador = 1;
		
		while(contador <= 50)
		{
			printf("%c", lnSep);
			contador++;
		}
		
	}
	
// Delineador
	void delineador(){
		escreveLinha();
		mudaLinha();
		escreveLinha();
		mudaLinha();	
	}
 
 // Função que mostra (algumas) informações gerais
	void meuCarimbo(void)
	{
		
	delineador();
	
		time_t tempo_atual = time(NULL);
		struct tm *tempo_local = localtime(&tempo_atual);
		char data_hora[64];
		strftime(data_hora, sizeof(data_hora), "%d-%m-%Y %H:%M:%S", tempo_local);
		printf("\n[Tiago Proenca] - [ %s ]", data_hora);
		printf("\n");
		
	delineador();
	
		printf("\nUFCD-0809 - Programacao em C/C++ - Fundamentos");
		
	mudaLinha();
	delineador();
	}
 
void main()
{
	meuCarimbo();

	char cidade[100]; // array que vai receber as informações do ficheiro de texto.
	
	FILE *fichInput;
 
    fichInput = fopen("EX_FX_TP_10.TXT","r");
    
	if (fichInput == NULL) { // verifica se o ficheiro existe!
		
		printf("O ficheiro não existe ou não está 'nesta' pasta...\n");
		
	} else {  
        
		while ( fgets(cidade, 100, fichInput) != NULL ) {  // ciclo 'while' sem '{}'...      
			printf("%s", cidade);
		}
		fclose(fichInput);
	  }  
	  
	delineador();  
}

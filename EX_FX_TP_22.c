// Tiago Proenca 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

    int i;

	char lerNomeFicheiro[100];

	char* cidade[4] = {"Porto", "Aveiro", "Coimbra", "Vila Pouca de Aguiar"};
	float temp[4] = {12.5, 11.8, 12.2, 14};

	FILE *fichOutput;

	printf("Nome do ficheiro que deseja abrir - ");

	scanf("%s", lerNomeFicheiro);	
 
    fichOutput = fopen(lerNomeFicheiro,"a");

    delineador();  

	for (i = 0; i < 4; i ++) { 
		
		fprintf(fichOutput, "%s - %f\n", cidade[i], temp[i]);
		fprintf(stdout, "%s - %f\r\n", cidade[i], temp[i]);
		
	} 
	
	fclose(fichOutput); 
	  
	delineador();  
}

// Tiago Proenca
// 2024-10-22

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
	
    printf("\n");
	
	/* 	Lista de variáveis:
		i - variável contadora de ciclo
		k - variável que guarda o tamanho de cada linha de texto
		temp - array que guarda os valores da temperatura nas cidades
	*/
	
	
	
	int i, k, m;
	
	// char cidade[4][10] = {"Porto", "Aveiro", "Coimbra", "Lisboa"};
	
	char* cidade[4] = {"Porto", "Aveiro", "Coimbra", "Vila Pouca de Aguiar"};
	
    float temp[4] = {12.5, 11.8, 12.2, 14};
    
	FILE *fichOutput;
 
 // Este comando vai criar um ficheiro de texto
    fichOutput = fopen("EX_FX_TP_10.TXT", "w");

	for ( i = 0; i < 4; i++ ){
    
		// escreve para o ficheiro
		k = fprintf(fichOutput,	"%s: %f\n", cidade[i], temp[i]); 	
		//printf("Tamanho (em bytes) da linha: %d\n", k);

		// escreve para o ecrã
		m = fprintf(stdout, "%s: %f\n", cidade[i], temp[i]);		
		//printf("Tamanho (em bytes) da linha: %d\n", m);
		
    }
	
    fclose(fichOutput);
	
	printf("\n");    
	
	delineador();
}

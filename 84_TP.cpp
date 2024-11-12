#include <iostream>

using namespace std;

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


    void desenhaRetangulo(int ladoMenor, int ladoMaior) {
        for (int i = 0; i < ladoMenor; ++i) {
            for (int j = 0; j < ladoMaior; ++j) {
                printf("*");
            }
            printf("\n");
        }
    }

int main() {
    int ladoMenor, ladoMaior;

    for (int i = 0; i < 10; ++i) {
        printf("Digite o lado menor do retângulo #%d: ", i + 1);
        scanf("%d", &ladoMenor);
        printf("Digite o lado maior do retângulo #%d: ", i + 1);
        scanf("%d", &ladoMaior);

        desenhaRetangulo(ladoMenor, ladoMaior);
        mudaLinha();  // Linha em branco entre retângulos
    }

    return 0;
}
#include <iostream>
#include <fstream> // Para manipulação de arquivos
#include <string>
#include <vector>

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

// Função principal do programa
int main() {
       // Variáveis para armazenar as somas
    int somaPositivos = 0;
    int somaNegativos = 0;
    int numero;

	ifstream arquivoEntrada("Inteiros.txt");
	ofstream arquivoSaida("1107_01.txt");

    if (!arquivoEntrada.is_open()) {
        cout << "Erro ao abrir o arquivo." << endl;
        return 1;
    }

    // Lendo os números do arquivo e somando os positivos e negativos
    while (arquivoEntrada >> numero) {
        if (numero > 0) {
            somaPositivos += numero;
        } else if (numero < 0) {
            somaNegativos += numero;
        }
    }

	arquivoSaida << "Soma dos números positivos: " << somaPositivos << endl;
    arquivoSaida << "Soma dos números negativos: " << somaNegativos << endl;
    // Fechando o arquivo de entrada
    arquivoEntrada.close();
    // Fechando o arquivo de saída
    arquivoSaida.close();

    return 0;
}


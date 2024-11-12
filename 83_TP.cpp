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

    int main() {
        std::ifstream inputFile("InteirosPositivos.txt");
        std::vector<std::vector<int>> numbers;  // Array bidimensional para os números
        int number;
        int rowCount = 0;

        // 1. Ler números do ficheiro e construí-los como um array bidimensional
        if (inputFile.is_open()) {
            while (inputFile >> number) {
                if (numbers.size() <= rowCount) {
                    numbers.push_back(std::vector<int>());
                }
                numbers[rowCount].push_back(number);
                if (inputFile.peek() == '\n') {
                    rowCount++;
                }
            }
            inputFile.close();
        } else {
            std::cerr << "Erro ao abrir o ficheiro InteirosPositivos.txt" << std::endl;
            return 1;
        }

        // 2. Guardar números pares e ímpares em ficheiros diferentes
        std::ofstream outputFilePar("1107_21.txt");
        std::ofstream outputFileImpar("1107_22.txt");

        if (outputFilePar.is_open() && outputFileImpar.is_open()) {
            for (const auto& row : numbers) {
                for (int num : row) {
                    if (num % 2 == 0) {
                        outputFilePar << num << std::endl;
                    } else {
                        outputFileImpar << num << std::endl;
                    }
                }
            }
            outputFilePar.close();
            outputFileImpar.close();
        } else {
            std::cerr << "Erro ao criar os ficheiros de saída" << std::endl;
            return 1;
        }

        meuCarimbo();
        return 0;
    }
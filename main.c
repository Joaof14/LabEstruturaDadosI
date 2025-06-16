#include <stdio.h>


int main() {

	int vetor[10] = {1,3,5,7,9,11,13,15,17,19};
	
	int elemento = 5;
	

	//Busca sequencial
	for (int i = 0; i < 10; i++){
		if (vetor[i] == elemento) {
			printf("Busca sequencial\n%d\n", i);
			break;
		}
	}

	//Busca binária
	int inicio = 0;
	int fim = 9;
	int meio;
	while (inicio < fim){
		meio = (inicio + fim)/2;
		if(vetor[meio] == elemento) {
			printf("Busca Binária\nValor %d encontrado na posicão %d.\n", elemento, meio);
			break;
		}
		else if ( vetor[meio] > elemento){
			fim = meio + 1;
		}
		else {
			inicio = meio + 1;
		}

	}
	
	return -1;

}



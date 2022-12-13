#include "ordvetor.h"

//Essa função serve para criar o vetor ordenado com tamanho definido por n e função de comparação
VETORORD* VETORD_create(int n, COMP* compara){
    VETORORD* vetor = malloc(sizeof(VETORORD));
    vetor -> comparador = compara;
    vetor -> N = n; //E o tamanho do vetor
    vetor -> P = 0; //E o numero de elementos no vetor
    vetor -> elems = malloc(n * sizeof(void*));

    return vetor;
}

//Essa função serve para adicionar um elemento ao vetor ordenado, mas so adiciona se houver espaço, alem de ordenar o vetor de acordo com a função de comparação
void VETORD_add(VETORORD* vetor, void* novoelem){
    if (vetor -> N > vetor -> P) {
        
		int pos = vetor->P;

		for (int i = 0; i < vetor -> P; i++) {
			if (vetor -> comparador(vetor -> elems[i], novoelem) == -1) {
				pos = i;
				break;
			}
		}

		for (int i = vetor -> P; i > pos; i--) {
			vetor -> elems[i] = vetor -> elems[i - 1];
		}

		vetor -> elems[pos] = novoelem;
		vetor -> P++;
	}
}

//Essa Função serve para remover o menor elemento do vetor ordenado e reorganizar o vetor de acordo com a função de comparação
void* VETORD_remove(VETORORD* vetor) {
	void* men = vetor -> elems[0];

	for (int i = 0; i < vetor -> P - 1; i++) {
		vetor -> elems[i] = vetor -> elems[i + 1];
	}
	
	vetor -> P--;

	return men;
}


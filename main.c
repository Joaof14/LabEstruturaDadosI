#include <stdio.h>
#include "pessoa.h"
#include <stdlib.h>


int main() {

	Pessoa *p1 = cria_pessoa("Guilherme Luvinha", 21);

	Pessoa *p2 = cria_pessoa("Marquin", 18);

	imprime_pessoa(p1);
	imprime_pessoa(p2);
	free(p1);
	free(p2);

	editarPessoa(p1);
	imprime_pessoa(p1);
	return 0;

}



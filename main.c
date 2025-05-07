#include <stdio.h>

enum Posicao {GOLEIRO, ZAGUEIRO, MEIOCAMPO, ATACANTE};

struct Jogador {
	char nome[20];
	float salario;
	int gols;
	enum Posicao posicao;
};

struct Time {
	char nome[30];
	struct Jogador capitao;
};

int main() {
	struct Jogador j1 = {"Cristiano", 80000, 45, ATACANTE};

	if (j1.posicao == ATACANTE) {
		printf("%s é atacante\n", j1.nome);
	}


	return 0;
}
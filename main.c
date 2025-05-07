#include <stdio.h>

struct Jogador {
	char nome[20];
	float salario;
	int gols;
};

struct Time {
	char nome[30];
	struct Jogador capitao;
};

int main() {
	struct Jogador jogadores[3] = {
		{"Ronaldo", 50000, 30},
		{"Messi", 75000, 40},
		{"Neymar", 6000, 25}
	};

	
	for (int i = 0; i < 3; i++) {
		printf("Nome: %s, Salário: %.2f, Gols: %d\n", jogadores[i].nome, jogadores[i].salario, jogadores[i].gols);
	}

	return 0;
}
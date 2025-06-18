#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoa.h"

struct pessoa {
    char nome[50];
    int idade;
};

Pessoa* cria_pessoa(char nome[50], int idade) {
    Pessoa *p = (Pessoa*)malloc(sizeof(Pessoa));
    p->idade = idade;
    strcpy(p->nome, nome);
    return p;
}

void imprime_pessoa(Pessoa *p) {
    printf("Nome: %s\n", p->nome);
    printf("idade: %d\n",p->idade);
}

void editarPessoa(Pessoa *p){
    int op = 0;
    printf("Digite o campo que você quer editar: \n1-nome\n2-Idade\n");
    scanf("%d", &op);
    
    switch (op)
    {
    case 1:
        printf("Digite o novo nome: ");
        scanf("%s", p->nome);
        break;

    case 2:
        printf("Digite a nova idade: ");
        scanf("%d", &p->idade);
        break;

    default:
        break;
    }
    return;
}
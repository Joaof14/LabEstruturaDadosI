#ifndef PESSOA_H
#define PESSOA_H

typedef struct pessoa Pessoa;

Pessoa* cria_pessoa(char nome[50], int idade);

void imprime_pessoa(Pessoa *p);

void editarPessoa(Pessoa *p);

#endif
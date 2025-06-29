#ifndef VETOR_h
#define VETOR_H

void preencherVetor(int * vetor, int tamanho);


void copiarVetor(int *origem, int * destino, int tamanho);


void imprimirVetor(int * vetor, int tamanho);

// Funções auxiliares para strings
void preencherStrings(char **strings, int tamanho, int max_len);
void copiarStrings(char **origem, char **destino, int tamanho);
void liberarStrings(char **strings, int tamanho);



#endif
#include <stdio.h>
#include <stdlib.h>

typedef struct NoDuplo{
    int dado;
    struct NoDuplo* anterior;
    struct NoDuplo* proximo;
} NoDuplo;


NoDuplo* criar_no_duplo(int valor) {
    NoDuplo* novo = (NoDuplo*)malloc(sizeof(NoDuplo));

    if(novo) {
        novo->dado = valor;
        novo->anterior = NULL;
        novo->proximo = NULL;
    }
    return novo;
}


void inserir_fim_duplo(NoDuplo** cabeca, int valor) {
    NoDuplo* novo = criar_no_duplo(valor);
    if(!*cabeca){
        *cabeca = novo;
        return;
    }
    NoDuplo* atual = *cabeca;
    while(atual->proximo){
        atual = atual->proximo;
    }
    atual->proximo = novo;
    novo->anterior = atual;

}


void remover_no_duplo(NoDuplo** cabeca, int chave)
{
    if (!*cabeca) return;

    NoDuplo*atual = *cabeca;
    while(atual)
    {
        if(atual->dado == chave){
            atual->anterior->proximo = atual->proximo;
        }
        else{
            *cabeca = atual->proximo;
        }
        if(atual->proximo){
            atual->proximo->anterior = atual->anterior;
        }
        else{
            free(atual);
            return;
        }
        
        atual = atual->proximo;
    }

    
}
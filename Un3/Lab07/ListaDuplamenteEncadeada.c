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

void inserir_inicio_no_duplo(NoDuplo** cabeca, int valor) {
    NoDuplo* novo = criar_no_duplo(valor);
    if(!*cabeca){
        *cabeca = novo;
        return;
    }
    NoDuplo* atual = *cabeca;
    novo->proximo = atual;
    atual->anterior = novo;
    *cabeca = novo;
}


void inserir_fim_no_duplo(NoDuplo** cabeca, int valor) {
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

//Para ajeitar
void remover_no_duplo(NoDuplo** cabeca, int chave)
{
    if(!* cabeca) {
        printf("Lista vazia");
        return;}

    NoDuplo*atual = *cabeca;
    while(atual)
    {
        if(atual->dado == chave){
            //Remover nó do início
            if(atual == *cabeca){
                *cabeca = atual->proximo;
                if(*cabeca){
                    (*cabeca)->anterior = NULL;
                }
                else{
                    atual->anterior->proximo = atual->proximo;
                    if(atual->proximo){
                        atual->proximo->anterior = atual->anterior;
                    }
                }
                NoDuplo* proximo = atual->proximo;
                free(atual);
                atual = proximo;
            } 
            else {
                atual = atual->proximo;
            }
        
        }
    }
}




void buscar(NoDuplo**cabeca, int chave){
    if(!* cabeca) {
        printf("Lista vazia");
        return;}

    NoDuplo* temp = * cabeca;

    while(temp && temp->dado != chave) {
        temp = temp->proximo;
    }

    if(!temp) {
        printf("Valor %d não está presente na lista\n", chave);    
        return;
    } //nao achou e retorna;

    printf("Valor %d está presente na lista\n", chave);

}


void exibir_lista(NoDuplo** cabeca){
    if(!* cabeca) {
        printf("Lista vazia");
        return;}
    NoDuplo* atual = *cabeca;
    while(atual) {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
    printf("\nNULL-Fim da lista\n");
}


int main(){
    NoDuplo * listaDuplamenteEncadeada = NULL;
    inserir_inicio_no_duplo(&listaDuplamenteEncadeada, 30);
    inserir_inicio_no_duplo(&listaDuplamenteEncadeada, 20);
    inserir_fim_no_duplo(&listaDuplamenteEncadeada, 40);

    printf("Lista Original: ");

    exibir_lista(&listaDuplamenteEncadeada);

    buscar(&listaDuplamenteEncadeada, 10);
    buscar(&listaDuplamenteEncadeada, 40);



}
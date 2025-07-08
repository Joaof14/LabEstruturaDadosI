#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dado;
    struct No* proximo;
} No;


No* criar_no(int valor){
    No* novo = malloc(sizeof(No));
    if (novo){
        novo-> dado = valor;
        novo -> proximo = NULL;
   }

 return novo; 
}


void inserir_no_inicio(No** cabeca, int valor){
    No* novo = criar_no(valor);
    if (novo) {
        novo -> proximo = * cabeca;
        *cabeca = novo;
    }
}

void inserir_no_fim (No** cabeca, int valor){
    No* novo = criar_no(valor);
    if (!*cabeca) {
        * cabeca = novo;
        return;
    }


    No* atual = *cabeca;
    while(atual->proximo){
        atual = atual->proximo;
    }
    atual->proximo = novo;
}

void remover_no(No ** cabeca, int chave){
    if(!* cabeca) return;

    No* temp = * cabeca;
    No* anterior = NULL;

    if (temp->dado == chave){
        *cabeca = temp->proximo;
        free(temp);
        return;
    }

    while(temp && temp->dado != chave) {
        anterior = temp;
        temp = temp->proximo;
    }

    if(!temp) return; //nao achou e retorna;

    anterior->proximo = temp->proximo;
    free(temp);
}


void exibir_lista(No ** cabeca){
    No* atual = cabeca;
    while(atual) {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
    printf("NULL");
}

int main(){
    No * lista = NULL;
    inserir_no_inicio(&lista, 30);
    inserir_no_inicio(&lista, 20);
    inserir_no_fim(&lista, 40);

    printf("Lista Original: ");

    exibir_lista(&lista);



}
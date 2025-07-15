#include <stdio.h>
#include <stdlib.h>

typedef struct No {
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


    if (!novo) return;

    

    if(!*cabeca){
        novo->proximo = novo; //Lista vazia, logo elemento aponta pra si
        *cabeca = novo;
    }
    else{
        No * atual = * cabeca;
        while(atual->proximo != * cabeca)
        {
            atual = atual->proximo;
        }
        novo->proximo = *cabeca;
        atual->proximo = novo;
        *cabeca = novo;


    }
}

void inserir_no_fim (No** cabeca, int valor){
    No* novo = criar_no(valor);
    if (!novo) return;

    if (!*cabeca) {
        novo->proximo = novo;
        * cabeca = novo;
    }
    else{
        No* atual = *cabeca;
        while(atual->proximo != * cabeca){
            atual = atual->proximo;
        }
        atual->proximo = novo;
        novo->proximo = *cabeca;
    }

   
}

void remover_no(No ** cabeca, int chave){
    if(!* cabeca) {
        printf("Lista vazia");
        return;}

    No* temp = * cabeca;
    No* anterior = NULL;

    //Encontrar nó
    do {
        if (temp->dado == chave) break;
        anterior = temp;
        temp = temp->proximo;
    }
    while (temp != * cabeca);

    if(!temp) return; //nao achou e retorna;


    //se for o Único nó na lista
    if(temp->proximo == temp){
        free(temp);
        *cabeca = NULL;
        return;
    }

    //Remover Primeiro nó
    if(temp == * cabeca){
        No *ultimo = * cabeca;
        while(ultimo->proximo != * cabeca){
            ultimo = ultimo->proximo;
        }
        *cabeca = temp->proximo;
        ultimo->proximo = *cabeca;
        free(temp);
    }
    else{ //Remover nó intermediario/final
        anterior->proximo = temp->proximo;
        free(temp);
    }
    

   
    
}

void buscar(No**cabeca, int chave){
    if(!* cabeca) {
        printf("Lista vazia");
        return;}

    No* atual = * cabeca;

    do {
        if(atual->dado == chave){
            printf("Valor %d está presente na lista\n", chave); 
            return;
        }
        atual = atual->proximo;
    } while(atual != * cabeca);

    

    printf("Valor %d não está presente na lista\n", chave);

   
}



void exibir_lista(No** cabeca){
    No* atual = *cabeca;

    if(!* cabeca) {
        printf("Lista vazia");
        return;}
    do {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
    while(atual != *cabeca);
    printf("\nRetorno ao início\n");
}



int main(){
    No * listaCircular = NULL;
    inserir_no_inicio(&listaCircular, 30);
    inserir_no_inicio(&listaCircular, 20);
    inserir_no_fim(&listaCircular, 40);

    printf("Lista Original: ");

    exibir_lista(&listaCircular);

    buscar(&listaCircular, 10);
    buscar(&listaCircular, 40);



}
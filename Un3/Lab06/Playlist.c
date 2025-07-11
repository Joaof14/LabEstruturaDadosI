/*5º Imagine que você está desenvolvendo um aplicativo de música e precisa
implementar uma playlist dinâmica. Utilize a estrutura duplamente encadeada
juntamente com a estrutura circular.
● Cada música é representada por um objeto com título, artista e duração.
● A playlist deve permitir adicionar músicas, remover músicas e exibir a
lista atual.
● Criar função que permita o usuário reorganizar sua playlist*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Duracao{
    unsigned int minutos;
    unsigned int segundos;

} Duracao;

typedef struct Musica
{
    char titulo[100];
    char artista[100];
    Duracao * duracao;
} Musica;

typedef struct No{
    Musica * musica;
    struct No * proximo;
    struct No * anterior;
} No;



Musica* criaMusica(){
    Musica* novo = malloc(sizeof(Musica));
    if(novo){
    

        printf("Digite o nome da música: \n");
        scanf(" %99[^\n]", novo->titulo);

        printf("\nDigite o artista: \n");
        scanf("%99[^\n]", novo->artista);


        unsigned int minutos = 70;
        do{
            printf("\nDigite a duração em minutos: \n");
        scanf("%u", &minutos);}
        while(minutos >= 60 || minutos< 0);
        novo->duracao->minutos= minutos;


        unsigned int segundos = 70;
        do{
            printf("\nDigite a duração em segundos: \n");
        scanf("%u", &segundos);}
        while(segundos >= 60 || segundos< 0);
        novo->duracao->segundos = segundos;
        
        
        return novo;
    }
}

No* criar_no(){
    No* novo = malloc(sizeof(No));
    if (novo){
        novo->musica= criaMusica();
        if(!novo->musica){
            free(novo);
            return NULL;
        }
        novo -> proximo = NULL;
        novo -> anterior = NULL;
   }
   return novo;

}

void AdicionarMusica(No **cabeca){
    No * novo = criar_no();
    if(!*cabeca) {
        *cabeca = novo;
    }
    else{
        No * atual = *cabeca;

        while(atual->proximo)
        {atual = atual->proximo;}
        atual->proximo = novo;
    }
}

void RemoverMusica(No **cabeca, Musica * musica){
    if(!*cabeca) {
        printf("Lista vazia");
        return;
        }
        No *atual = *cabeca, *anterior = NULL;
        while (atual && atual->musica != musica) {
            anterior = atual;
            atual = atual->proximo;
        }
        if (!atual) {
            printf("Música não encontrada\n");
            return;
        }
        //Deleta a musica e liga anterior ao proximo do deletado
        if (anterior) {
            anterior->proximo = atual->proximo;
            atual->proximo->anterior = atual->anterior;
        } else { // nao tem anterior, logo a cabeça é o proximo pois é a cabeca q foi deletada
        *cabeca = atual->proximo;
        atual->proximo->anterior = NULL;
        }
        free(atual->musica->duracao);
        free(atual->musica);
        free(atual);

}

void ExibirPlaylist(No **cabeca){
    if(!* cabeca) {
        printf("Lista vazia");
        return;}
    No* atual = *cabeca;
    while(atual) {
        printf("%s\n%s\n%u:%u", atual->musica->titulo, atual->musica->artista, atual->musica->duracao->minutos, atual->musica->duracao->segundos);
        atual = atual->proximo;
    }
    printf("\nNULL-Fim da lista\n");
}




void ReordenarPlaylist(No **cabeca, Musica * musica1, Musica * musica2, int posicaoDeReferencia){
    if(!* cabeca) {
        printf("Lista vazia\n");
        return;}
    if(musica1 == musica2){
        printf("Voce deve reordenar musicas diferentes!\n");
    }
    

        No * No1 = NULL;
        No * No2 = NULL;
        No * atual = * cabeca;
    while(atual && No1 != NULL && No2 != NULL){
        if (atual->musica == musica1){
            No * No1 = atual;
        }
        if (atual->musica == musica2){
            No * No2 = atual;
        }
    }

    //posicao de referencia == 0 : musica1 antes de musica2
    if (posicaoDeReferencia == 0){

            //Ligar proximos e anterior de No1
            if(No1->anterior){//Verifica se No1 náo é a cabeca
                No1->anterior->proximo = No1->proximo;//Se é o ultimo tem anterior, logo esse anterior recebe Null
            }
            else{
                *cabeca = No1->proximo;
            }
            if (No1->proximo){//verifica se nao é o ultimo
                No1->proximo->anterior = No1->anterior;
            }
            

            //Ligar No1 com o anterior do No2
            if (No2->anterior){//verifica se No2 tem anterior ou é cabeca
                No2->anterior->proximo = No1;
                
            }
            else{
                *cabeca = No1;
            }
            //Ligar No1 com o No2
            No1->anterior = No2->anterior;
            No2->anterior = No1;
            No1->proximo = No2;

    }
    //posicao de referencia != 0 : musica1 depois de musica2
    else{

       //Ligar proximos e anterior de No1
            if(No1->anterior){//Verifica se No1 náo é a cabeca
                No1->anterior->proximo = No1->proximo;//Se é o ultimo tem anterior, logo esse anterior recebe Null
            }
            else{
                *cabeca = No1->proximo;
            }
            if (No1->proximo){//verifica se nao é o ultimo
                No1->proximo->anterior = No1->anterior;
            }
            

            //Ligar No1 com o proximo do No2
            if (No2->proximo){//verifica se No2 tem próximo ou é ultimo
                No2->proximo->anterior = No1;
            }
            //Ligar No1 com o No2
            No1->proximo = No2->proximo; 
            No1->anterior = No2;
            No2->proximo = No1;

}



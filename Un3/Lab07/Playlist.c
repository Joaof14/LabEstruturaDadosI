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


//Lista duplamente encadeada

Musica* criaMusica(){
    Musica* novo = malloc(sizeof(Musica));
    if(novo){
        novo->duracao = malloc(sizeof(Duracao));
        if (!novo->duracao) {
            free(novo);
            return NULL;
        }
    

        printf("Digite o nome da música: \n");
        scanf(" %99[^\n]", novo->titulo);
        getchar();

        printf("\nDigite o artista: \n");
        scanf("%99[^\n]", novo->artista);
        getchar();


        unsigned int minutos = 70;
        do{
            printf("\nDigite a duração em minutos: \n");
        scanf("%u", &minutos);}
        while(minutos >= 60 || minutos< 0);
        novo->duracao->minutos= minutos;
        getchar();

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
        novo->proximo = novo;
        novo->anterior = novo;
    }
    else{
        No * ultimo = (*cabeca)->anterior;
        novo->anterior = ultimo;
        ultimo->proximo = novo;
        novo->proximo = *cabeca;
        (*cabeca)->anterior = novo;
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
         if (atual->proximo == atual) {
                // única música
                *cabeca = NULL;
            } else {
                atual->anterior->proximo = atual->proximo;
                atual->proximo->anterior = atual->anterior;
                if (atual == *cabeca)
                    *cabeca = atual->proximo;
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
    do{
        printf("%s-%s\n%u:%u\n\n", atual->musica->titulo, atual->musica->artista, atual->musica->duracao->minutos, atual->musica->duracao->segundos);
        atual = atual->proximo;
    } while(atual!= * cabeca);
    printf("Fim da lista\n");
}


/* No *atual = playlist;
                Musica *m1 = NULL, *m2 = NULL;
                do {
                    if (strcmp(atual->musica->titulo, nome1) == 0)
                        m1 = atual->musica;
                    if (strcmp(atual->musica->titulo, nome2) == 0)
                        m2 = atual->musica;
                    atual = atual->proximo;
                } while (atual != playlist && (!m1 || !m2));

                if (!m1 || !m2) {
                    printf("Uma ou ambas as músicas não foram encontradas.\n");
                }*/

void ReordenarPlaylist(No **cabeca, const char* nome1, const char* nome2, int posicaoDeReferencia){
    if(!* cabeca) {
        printf("Lista vazia\n");
        return;}
    
        Musica *m1 = NULL, *m2 = NULL;
        No * No1 = NULL, *No2 = NULL, * atual = * cabeca;
        do{
            if (strcmp(atual->musica->titulo, nome1) == 0){
                No * No1 = atual;
        }
            if (strcmp(atual->musica->titulo, nome2) == 0){
                No * No2 = atual;
            }
            atual = atual->proximo;
        }
    while(atual && No1 != NULL && No2 != NULL);

    if(!No1 && !No2){
        printf("Uma ou ambas as músicas não foram encontradas na playlist.\n");
        return;
    }
    if(No1 == No2){
        printf("Você deve escolher musicas diferentes\n");
    }

    //Tira no1 da lista
    No1->anterior->proximo = No1->proximo;
    No1->proximo->anterior = No1->anterior;

    //posicao de referencia == 0 : musica1 antes de musica2
    if (posicaoDeReferencia == 0){
        No1->proximo = No2;
        No2->anterior->proximo = No1;
        No1->anterior = No2->anterior;
        No2->anterior = No1;

        if(No2 == *cabeca){
            *cabeca = No1;
        }
          
    
    }
    //posicao de referencia != 0 : musica1 depois de musica2
    else{
        No1->anterior = No2;
        No1->proximo = No2->proximo;
        No2->proximo->anterior = No1;
        No2->proximo = No1;
    }

}int main() {
    No *playlist = NULL;
    int opcao;

    do {
        printf("\nPlaylist\n");
        printf("1. Adicionar música\n");
        printf("2. Exibir playlist\n");
        printf("3. Reordenar músicas\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // limpar buffer

        switch (opcao) {
            case 1:
                AdicionarMusica(&playlist);
                break;

            case 2:
                ExibirPlaylist(&playlist);
                break;

            case 3: {
                if (!playlist) {
                    printf("Playlist vazia.\n");
                    break;
                }

                char nome1[100], nome2[100];
                printf("Digite o título da música a mover: ");
                scanf(" %99[^\n]", nome1);
                getchar();

                printf("Digite o título da música de referência: ");
                scanf(" %99[^\n]", nome2);
                getchar();

                int antesOuDepois;
                printf("Posicionar antes (0) ou depois (1) da música de referência? ");
                scanf("%d", &antesOuDepois);
                getchar();


                 
                ReordenarPlaylist(&playlist, nome1, nome2, antesOuDepois);
                
                break;
            }

            case 4:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida.\n");
        }

    } while (opcao != 4);

    return 0;
}


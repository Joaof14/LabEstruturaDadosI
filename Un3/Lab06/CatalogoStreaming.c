/*Um serviço de streaming quer armazenar seu catálogo de filmes e séries,
incluindo nome, ano de lançamento e categoria. Crie uma lista de dicionários
para armazenar os títulos e implemente funções para:
● Adicionar um novo título
● Buscar títulos por categoria
● Listar os títulos ordenados pelo ano de lançamento*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct Titulo
{
    char nome[100];
    unsigned int ano;
    char categoria[30];
    
} Titulo;

typedef struct No{
    Titulo * titulo;
    struct No * proximo;
} No;


No* criar_no(){
    No* novo = malloc(sizeof(No));
    if (novo){
        novo->titulo = criaTitulo();
        if(!novo->titulo){
            free(novo);
            return NULL;
        }
        novo -> proximo = NULL;
   }
   return novo;

 return novo; 
}




Titulo * criaTitulo(){
    Titulo * novo = malloc(sizeof(Titulo));
    if(novo){

        printf("Digite o nome do título: \n");
        fgetc(stdin); 
        novo->nome[strcspn(novo->nome, "\n")] = '\0';
        fgets(novo->nome,100, stdin);

        printf("\nDigite o ano de lançamento: \n");
        scanf("%u", &novo->ano);
        

        const char* categorias[] = {
            "Comédia", "Romance", "Drama", "Suspense", 
            "Terror", "Documentário", "Outro"
        };


        printf("\nEscreva a categoria do Título: ");
        for (int i =0; i < 5; i++)
            {printf("%d-%s\n", i, categorias[i]);}
            printf("Para categoria diferente, digite qualquer outro número que classificaremos como: ¨Outro¨ ");

        int cat;
        scanf("%d", &cat );

        if (cat >= 0 && cat <= 6) {
            strcpy(novo->categoria, categorias[cat]);
        } else {
            strcpy(novo->categoria, categorias[6]); // "Outro"
        }
    }
    return novo;
}

void adicionarTitulo(No ** cabeca, Titulo * titulo){
    
}

void BuscarTituloCategoria(){

}

void ListarAno(){

}

int main(){

}

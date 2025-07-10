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
            "Série", "Filme"
        };


        printf("\nEscreva a categoria do Título: \n");
        for (int i =0; i < 2; i++)
            {printf("%d-%s\n", i+1, categorias[i]);}
            printf("Para categoria diferente, digite qualquer outro número que classificaremos como: ¨Outro¨ \n");

        int cat = 0;
        
        do{scanf("%d", &cat );}

        while(cat <= 0 || cat >= 3);
            strcpy(novo->categoria, categorias[cat-1]);
    }
    return novo;
}

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


void adicionarTitulo(No ** cabeca){
    No * novo = criar_no();
    //Se vazio, primeiro item
    if(!*cabeca){
        *cabeca = novo;
    }
    else{
        No * atual = *cabeca;
        //itera para alcançar o ultimo e ligar esse ao novo item
        while(atual->proximo){
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }

}

void BuscarTituloCategoria(No ** cabeca, const char * categoria){
    if(! *cabeca) {
        printf("Lista vazia");
        return;}

    printf("Títulos por categoria %s", categoria);
    No * atual = * cabeca;
    int encontrados = 0;

    while(atual){
        if ( strcmp(atual->titulo->categoria, categoria ) == 0){
            encontrados += 1;
            printf("%d. %s (%u)\n", encontrados, atual->titulo->nome, atual->titulo->ano);
        }
        atual = atual->proximo;
    }

    if (encontrados == 0)
    {
        printf("Não foram encontrados títulos desse gênero");
    }

}

void ListarOrdemAno(No ** cabeca){
    if(!* cabeca) {
        printf("Lista vazia");
        return;}
    int quantidade = 0;
    No * atual = * cabeca;

     while(atual){
        quantidade++;
        atual = atual->proximo;
        }

        //titulos
        Titulo **titulos = malloc(quantidade*sizeof(Titulo));
        atual = * cabeca;
        for (int i = 0; i < quantidade; i++){
            titulos[i] = atual->titulo;
            atual = atual->proximo;
        }

        //Insertion sort para ordenar
        int j;
        Titulo * pivo;

        for (int i = 1; i<quantidade; i++){
            pivo = titulos[i];
            j = i -1;

            while(j>=0 && titulos[j]->ano > pivo->ano)
            {
                titulos[j+1] = titulos[j];
                j--;
            }
            titulos[j] = pivo;
        }
        printf("\nTítulos ordenados por ano\n");
        for (int i = 1; i<quantidade; i++){
            printf("%u_ %s (%s) \n", atual->titulo->ano, atual->titulo->nome,atual->titulo->categoria);
        }
        


}

int main(){
No *catalogo = NULL;
    int opcao;
    
    do {
        printf("\n--- Menu ---\n");
        printf("1. Adicionar título\n");
        printf("2. Buscar por categoria\n");
        printf("3. Listar por ano\n");
        printf("4. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer
        
        switch (opcao) {
            case 1:
                adicionarTitulo(&catalogo);
                break;
            case 2: {
                char categoria[30];
                printf("Digite a categoria: ");
                fgets(categoria, sizeof(categoria), stdin);
                categoria[strcspn(categoria, "\n")] = '\0';
                BuscarTituloCategoria(&catalogo, categoria);
                break;
            }
            case 3:
                ListarOrdemAno(&catalogo);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 4);
    
    return 0;
}


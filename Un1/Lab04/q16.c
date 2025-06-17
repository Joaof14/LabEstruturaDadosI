/*Crie um registro Soldado com os campos nome, eliminações, mortes, taxa
de eliminação por morte (eliminações/mortes) e número de partidas jogadas. Na
função principal leia um soldado de um arquivo binário. Se o arquivo não
Para existir, você deve direcionar o usuário para a criação de um novo soldado.
Quando o soldado for lido (seja pelo arquivo ou pelo teclado), você deve dar as
seguintes opções ao usuário:
[N]ovo soldado (sobrescrever o anterior)
[A]ualiza o soldado (com os dados da última partida)
[E]xibe o soldado (atual)
[S]air */

#include <stdlib.h>
#include <stdio.h>

typedef struct {
        char nome[100];
        int elim;
        int mortes;
        float taxaDeElimin;
        int partidas;
} Soldado;


//Salvar soldado em arquivo binário ao fim da execução do programa
void salvarSoldado(Soldado * soldier ){
        FILE *arquivo = fopen("arquivos/soldado.bin", "wb");
        if (!arquivo) {
                printf("Erro ao abrir o arquivo");
                return;
        }

        fwrite(soldier, sizeof(Soldado), 1, arquivo);

        fclose(arquivo);
}


        

void RegistrarSoldado(Soldado * soldier){

        printf("\n Novo Soldado \n");
        printf("Digite o nome desse soldado: ");
        scanf("%s", soldier->nome);

        printf("Digite o número de eliminações desse soldado: ");
        scanf("%d", &soldier->elim);

        printf("Digite o numero de mortes desse soldado: ");
        scanf("%d", &soldier->mortes);

        printf("Dgite o numero de partidas desse soldado: ");
        scanf("%d", &soldier->partidas);
        
        soldier->taxaDeElimin = (float) soldier->elim/soldier->mortes;
        return;

}

void AtualizarSoldado(Soldado * soldier){
        printf("\n Atualizar Soldado \n");
        printf("Preencha com os dados da ultima partida \n");
        int e, m;
        printf("Digite o número de eliminações desse soldado: ");
        scanf("%d", &e);

        printf("Digite o numero de mortes desse soldado: ");
        scanf("%d", &m);

        soldier->elim += e;
        soldier->mortes += m;
        soldier->taxaDeElimin = (float) soldier->elim/soldier->mortes;
        soldier->partidas+= 1;
        return;

}

void ExibirSoldado(Soldado * soldier){
        printf("\n Dados do Soldado \n");
        printf("Nome: %s\n", soldier->nome);
        printf("Eliminações: %d\n", soldier->elim);
        printf("Mortes: %d\n", soldier->mortes);
        printf("Taxa de eliminação: %.2f\n", soldier->taxaDeElimin);
        printf("Partidas: %d\n", soldier->partidas);
        return;
}


int main(){

        Soldado * novo = (Soldado*)malloc(sizeof(Soldado));
        if (novo == NULL){
                printf("Erro de alocação de memória");
                return 1;
        }

        FILE *arquivo = fopen("arquivos/soldado.bin", "rb");
        if (!arquivo) {
                printf("Soldado ainda não foi criado\n");
                RegistrarSoldado(novo);
        }
        else{   
                //Leitura do soldado
                fread(novo, sizeof(Soldado), 1, arquivo);
                fclose(arquivo);
        }


        
        char c;
        int op = 1;
        
        do {
                printf("\nEscolha uma opção:\n[N]ovo soldado (sobrescrever o anterior)\n[A]tualiza o soldado (com os dados da última partida)\n[E]xibe o soldado (atual)\n[S]air\n");
                scanf(" %c", &c);
                switch (c)
                {
                case 'N':
                        RegistrarSoldado(novo);
                        break;
                case 'A':
                        AtualizarSoldado(novo);
                        break;
                case 'E':
                        ExibirSoldado(novo);
                        break;
                case 'S':
                        op = 0;
                        break;
                default:
                        printf("\n Opção inválida! \n");
                        break;
                }
        } while (op);
        printf("\n Programa encerrado \n");
        salvarSoldado(novo);
        free(novo);
        

        return 0;
}
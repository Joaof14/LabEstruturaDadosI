/*No exercício anterior, se o usuário digitar apenas espaços para a mensagem,
o resultado será uma faixa colorida com a cor de fundo. Podemos usar isso para
criar uma imagem formada apenas por caracteres de espaço coloridos.
Construa um programa que peça a largura e altura da imagem e leia do usuário
uma matriz de números. Cada número de 3 dígitos representa a cor de um
“bloco” da imagem. Guarde em um arquivo binário os valores de altura, largura
e de cada bloco da imagem. Assim como o programa anterior, construa um
menu para controlar as opções de armazenamento e exibição da imagem*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int largura;
    int altura;
    int **blocos;  
} ImagemColorida;

void criarImagem(ImagemColorida *img) {
    printf("Digite a largura da imagem: ");
    scanf("%d", &img->largura);
    printf("Digite a altura da imagem: ");
    scanf("%d", &img->altura);

    img->blocos = (int **)malloc(img->altura * sizeof(int *));
    for (int i = 0; i < img->altura; i++) {
        img->blocos[i] = (int *)malloc(img->largura * sizeof(int));
    }

    printf("\nDigite os codigos de cor para cada bloco (000-255):\n");
    for (int i = 0; i < img->altura; i++) {
        for (int j = 0; j < img->largura; j++) {
            do {
                printf("Bloco [%d][%d]: ", i, j);
                scanf("%d", &img->blocos[i][j]);
                if (img->blocos[i][j] < 0 || img->blocos[i][j] > 255) {
                    printf("Valor invalido! Digite um numero entre 0 e 255.\n");
                }
            } while (img->blocos[i][j] < 0 || img->blocos[i][j] > 255);
        }
    }
}

void salvarImagem(ImagemColorida *img) {
    FILE *arquivo = fopen("arquivos/imagem.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo!\n");
        return;
    }

    fwrite(&img->largura, sizeof(int), 1, arquivo);
    fwrite(&img->altura, sizeof(int), 1, arquivo);

    for (int i = 0; i < img->altura; i++) {
        fwrite(img->blocos[i], sizeof(int), img->largura, arquivo);
    }

    fclose(arquivo);
    printf("arquivos/Imagem salva com sucesso!\n");
}

void carregarImagem(ImagemColorida *img) {
    FILE *arquivo = fopen("arquivos/imagem.bin", "rb");
    if (arquivo == NULL) {
        printf("Arquivo nao encontrado!\n");
        return;
    }

    fread(&img->largura, sizeof(int), 1, arquivo);
    fread(&img->altura, sizeof(int), 1, arquivo);

    img->blocos = (int **)malloc(img->altura * sizeof(int *));
    for (int i = 0; i < img->altura; i++) {
        img->blocos[i] = (int *)malloc(img->largura * sizeof(int));
    }

    for (int i = 0; i < img->altura; i++) {
        fread(img->blocos[i], sizeof(int), img->largura, arquivo);
    }

    fclose(arquivo);
}

void exibirImagem(ImagemColorida *img) {
    printf("\n");
    for (int i = 0; i < img->altura; i++) {
        for (int j = 0; j < img->largura; j++) {
            printf("\033[48;5;%dm  ", img->blocos[i][j]);  
        }
        printf("\033[0m\n");  
    }
    printf("\033[0m");  
}

void liberarImagem(ImagemColorida *img) {
    for (int i = 0; i < img->altura; i++) {
        free(img->blocos[i]);
    }
    free(img->blocos);
}

int main() {
    ImagemColorida img = {0, 0, NULL};
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Criar nova imagem\n");
        printf("2. Salvar imagem\n");
        printf("3. Carregar imagem\n");
        printf("4. Exibir imagem\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                if (img.blocos != NULL) liberarImagem(&img);
                criarImagem(&img);
                break;
            case 2:
                if (img.blocos == NULL) {
                    printf("Nenhuma imagem criada ou carregada!\n");
                } else {
                    salvarImagem(&img);
                }
                break;
            case 3:
                if (img.blocos != NULL) liberarImagem(&img);
                carregarImagem(&img);
                break;
            case 4:
                if (img.blocos == NULL) {
                    printf("Nenhuma imagem criada ou carregada!\n");
                } else {
                    exibirImagem(&img);
                }
                break;
            case 0:
                printf("Encerrando programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 0);

    if (img.blocos != NULL) {
        liberarImagem(&img);
    }

    return 0;
}
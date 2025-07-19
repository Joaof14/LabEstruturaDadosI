/*Crie um programa que simule um sistema de desfazer e refazer utilizando
duas pilhas.
● O usuário pode digitar comandos e o programa os armazenará.
● O comando "desfazer" deve remover a última ação realizada.
● O comando "refazer" deve reaplicar a última ação desfeita.
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char * data;
    struct Node* next;
} Node;

typedef struct Stack{
    Node *top;
    int size;
} Stack;

void initStack(Stack * stack){
    stack->top = NULL;
    stack->size = 0;
}

int isEmpty(Stack * stack){
    return stack->top == NULL;
}

void push(Stack * stack, char * value){
    Node * newNode = (Node*)malloc(sizeof(Node));

    newNode->data = strdup(value);
    if (!newNode->data) {
        perror("Erro de alocação");
        free(newNode);
        exit(EXIT_FAILURE);
    }
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

char * pop(Stack * stack) {
    if (isEmpty(stack)){
        printf("Erro de fila vazia\n");
        return '\0';
    }

    Node * temp = stack->top;
    char * poppedValue = temp->data;
    stack->top =temp->next;
    stack->size--;
    free(temp);
    return poppedValue;

}

char * peek(Stack* stack){
    if (isEmpty(stack)){
        printf("Erro de fila vazia\n");
        return '\0';
    }
    return stack->top->data;

}

void display(Stack * stack){
    if (isEmpty(stack)){
        printf("Erro de fila vazia\n");
        return;
    }
    Node * temp = stack->top;
    printf("Pilha: ");
    while(temp){
        printf("%s ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void clearStack(Stack *stack) {
    while (!isEmpty(stack)) {
        char *data = pop(stack);
        free(data);  // Libera a memória da string
    }
}



int main(){
    Stack comandosFeitos;
    Stack comandosDesfeitos;
    initStack(&comandosFeitos);
    initStack(&comandosDesfeitos);
    char entrada[100];

    printf("Sistema de Desfazer/Refazer\n");
    printf("Digite comandos, 'desfazer' ou 'refazer'. Digite 'sair' para terminar.\n");

    do{
        
        
        fgets(entrada, sizeof(entrada), stdin);
        
        //remove a quebra de linha
        entrada[strcspn(entrada, "\n")] = '\0'; 
        if(strcmp(entrada, "sair") ==0) break;
        
        if (strcmp(entrada, "desfazer")== 0){
            char *ultimoComando = pop(&comandosFeitos);
            if (ultimoComando) {
                printf("Desfeito: %s\n", ultimoComando);
                push(&comandosDesfeitos, ultimoComando);
                free(ultimoComando); //libera a memória 
            } else {
                printf("Nada para desfazer\n");
            }
        }

        else if (strcmp(entrada, "refazer")== 0){
            char *ultimoComandoDesfeito = pop(&comandosDesfeitos);
            printf("Refeito: %s\n", ultimoComandoDesfeito);
            push(&comandosFeitos, ultimoComandoDesfeito);
            free(ultimoComandoDesfeito);
        }
        else{
            push(&comandosFeitos, entrada);
            printf("Comando adicionado: %s\n", entrada);
        }
    
    } while (1);

    clearStack(&comandosFeitos);
    clearStack(&comandosDesfeitos);
    return 0;

}

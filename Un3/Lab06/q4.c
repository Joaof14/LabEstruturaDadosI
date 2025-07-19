/*Com base no programa anterior, implemente um programa que solucione,
por meio de estrutura de pilha, expressões fornecidas em notação pós-fixa.*/

/*Implemente um algoritmo que, utilizando as estruturas de pilha, converta
expressões matemáticas na notação infixa (exemplo: 3 + 4 * 2) para a notação
pós-fixa (exemplo: 3 4 2 * +).*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct Node{
    int data;
    struct Node* next;
} Node;

typedef struct Stack{
    Node *top;
} Stack;

void initStack(Stack * stack){
    stack->top = NULL;
}

int isEmpty(Stack * stack){
    return stack->top == NULL;
}

void push(Stack * stack, int value){
    Node * newNode = (Node*)malloc(sizeof(Node));

    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack * stack) {
    if (isEmpty(stack)){
        printf("Erro de fila vazia\n");
        return -1;
    }

    Node * temp = stack->top;
    int poppedValue = temp->data;
    stack->top =temp->next;
    free(temp);
    return poppedValue;

}

int peek(Stack* stack){
    if (isEmpty(stack)){
        printf("Erro de fila vazia\n");
        return -1;
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
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


// Função para avaliar expressão pós-fixa
int avaliaPosfixa(char *posfixa) {
    Stack pilha;
    initStack(&pilha);

    char *token = strtok(posfixa, " ");
    while (token != NULL) {
        if (isdigit(token[0])) {
            
            push(&pilha, atoi(token));
        } else {
            
            int b = pop(&pilha);
            int a = pop(&pilha);
            switch (token[0]) {
                case '+': push(&pilha, a + b); break;
                case '-': push(&pilha, a - b); break;
                case '*': push(&pilha, a * b); break;
                case '/': push(&pilha, a / b); break;
            }
        }
        token = strtok(NULL, " ");
    }
    return pop(&pilha);
}

int main() {
    char entrada[100];
    printf("Digite a expressão pós-fixa: ");
    fgets(entrada, sizeof(entrada), stdin);
    entrada[strcspn(entrada, "\n")] = '\0'; 

    char copia[100];
    strcpy(copia, entrada);
    
    int resultado = avaliaPosfixa(copia);
    printf("Resultado: %d\n", resultado);
    
    return 0;
}

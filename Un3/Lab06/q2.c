/* Crie um programa que use uma pilha para inverter uma string. O usuário
deve inserir uma palavra ou frase, e o programa deve exibir o texto invertido.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char data;
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

void push(Stack * stack, char  value){
    Node * newNode = (Node*)malloc(sizeof(Node));

    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

char pop(Stack * stack) {
    if (isEmpty(stack)){
        printf("Erro de fila vazia\n");
        return '\0';
    }

    Node * temp = stack->top;
    char poppedValue = temp->data;
    stack->top =temp->next;
    stack->size--;
    free(temp);
    return poppedValue;

}

char peek(Stack* stack){
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
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int InverterString(char * str){
    Stack stack;
    initStack(&stack);
    for (int i =0; i < str[i] !='\0'; i++)
    {
        push(&stack, str[i]);
    }

    //Desimpilhar e armazenar na string
    int i = 0;
    while (!isEmpty(&stack)) {
        str[i] = pop(&stack);
        i++;
    }

}


int main(){
    char entrada[100];
    printf("Digite a palavra ou frase: ");
    fgets(entrada, sizeof(entrada), stdin);
    
    //remove a quebra de linha
    entrada[strcspn(entrada, "\n")] = '\0'; 
    
    InverterString(entrada);
    printf("Texto invertido: %s\n", entrada);
    return 0;

}

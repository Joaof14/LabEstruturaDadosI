/*Escreva um programa que utilize uma pilha para verificar se uma
sequência de parênteses está corretamente balanceada. Seu código deve
considerar os símbolos: {}, (), [].
Entrada: {[()()]} Entrada: {[(])}
Saída: Entrada Balanceada Saída: Entrada não Balanceada
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char data;
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

void push(Stack * stack, char value){
    Node * newNode = (Node*)malloc(sizeof(Node));

    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

char pop(Stack * stack) {
    if (isEmpty(stack)){
        printf("Erro de fila vazia\n");
        return '\0';
    }

    Node * temp = stack->top;
    int poppedValue = temp->data;
    stack->top =temp->next;
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

int verificaParenteses(const char * entrada){
     Stack stack;
    initStack(&stack);
    
    for (int i = 0; entrada[i] != '\0'; i++) {
        char c = entrada[i];
        // Empilha caracteres de abertura
        if (c == '(' || c == '[' || c == '{') {
            push(&stack, c);
        } else if (c == ')' || c == ']' || c == '}') {
            // Verifica se a pilha está vazia
            if (isEmpty(&stack)) {
                return 0; 
            }
            char top = pop(&stack);
            // Verifica correspondência
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                return 0; 
            }
        }
    }
    //se a pilha estiver vazia, está balanceado
    return isEmpty(&stack);
}


int main(){
    char entrada[100];
    printf("Digite a sequência de parênteses/colchetes/chaves: ");
    scanf("%s", entrada);
    
    if (verificaParenteses(entrada)) {
        printf("Entrada Balanceada\n");
    } else {
        printf("Entrada não Balanceada\n");
    }
    return 0;

}



/*Implemente um algoritmo que, utilizando as estruturas de pilha, converta
expressões matemáticas na notação infixa (exemplo: 3 + 4 * 2) para a notação
pós-fixa (exemplo: 3 4 2 * +).*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
    char poppedValue = temp->data;
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

int precedencia(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void EntradaPosfixa(char *entrada) {
    Stack stack;
    initStack(&stack);
    char saida[100] = ""; // Buffer para a expressão pós-fixa
    int j = 0; // Índice para o buffer de saída
    
    for (int i = 0; entrada[i] != '\0'; i++) {
        char c = entrada[i];
        
        //ignorar espaços
        if (c == ' ') continue;
        
        //se for dígito, adicionar diretamente à saída
        if (isdigit(c)) {
            saida[j++] = c;
            saida[j++] = ' '; // Adiciona espaço após o dígito
        }
        // Se for '(', empilhar
        else if (c == '(') {
            push(&stack, c);
        }
        // Se for ')', desempilhar até encontrar '('
        else if (c == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                saida[j++] = pop(&stack);
                saida[j++] = ' ';
            }
            pop(&stack); // Remove o '(' da pilha
        }
        //Se for operador
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            
            while (!isEmpty(&stack) && precedencia(peek(&stack)) >= precedencia(c)) {
                saida[j++] = pop(&stack);
                saida[j++] = ' ';
            }
            push(&stack, c); 
        }
    }
    
    //Desempilha todos os operadores restantes
    while (!isEmpty(&stack)) {
        saida[j++] = pop(&stack);
        saida[j++] = ' ';
    }
    saida[j] = '\0'; //
    
    // Copia o resultado de volta para a entrada
    strcpy(entrada, saida);
}


int main(){
    char entrada[100];
    printf("Digite a operaçao matemática infixa para transformar em pósfixa: ");
    fgets(entrada, sizeof(entrada), stdin);
    //remove a quebra de linha
    entrada[strcspn(entrada, "\n")] = '\0'; 
    
    printf("Entrada atual: %s\n", entrada);
    EntradaPosfixa(entrada);
    printf("Entrada posfixa: %s", entrada);
    return 0;

}



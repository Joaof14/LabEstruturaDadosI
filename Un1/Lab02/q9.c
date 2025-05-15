#include <stdio.h> 

/* Declare um registro Horário com os campos horas e minutos. Crie uma 
função MostrarHorario que deve receber um ponteiro para um Horário e 
mostrá-lo no formato HH:MM. Na função principal, declare uma variável do 
tipo Horário e um ponteiro que aponta para ela. Peça que o usuário digite o 
horário atual e guarde-o na variável. Usando o ponteiro, incremente o horário 
recebido em uma hora e em seguida mostre o horário corrigido com 
MostrarHorario.*/

typedef struct 
{
    int horas;
    int minutos;
} Horario;


void MostrarHorario(Horario * hr){

    printf("Seu relógio está atrasado, o horário correto é: %d:%d\n", hr->horas, hr->minutos);

}

int main() {
    Horario horaAtual;
    Horario * ptr = &horaAtual;
    printf("Digite a hora atual no formato HH:MM\n");
    
    //Receber horas
    while (1) {
        printf("Que horas são? \n");
        scanf("%d:%d", &horaAtual.horas, &horaAtual.minutos);

        //Verificar se horario está nos requisitos
        if( (horaAtual.horas < 24 &&  horaAtual.horas >= 00 ) && (horaAtual.minutos < 60 && horaAtual.minutos >= 00) ) {
            break;
        }
        else {
            printf("O valor em horas deve estar ser de 0 a 23 e de 0 a 59 para minutos\n");
        }

    }

    //Corrigir horário
    if (ptr->horas == 23) {
        ptr->horas = 00;
    }
    else {
        ptr->horas = ptr->horas+1;
    }

    MostrarHorario(ptr);
    
    
    return 0;
}
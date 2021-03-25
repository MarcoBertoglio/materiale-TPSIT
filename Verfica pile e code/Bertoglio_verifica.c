#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

typedef struct el{
    char seme;
    int num;
    struct el* next;
}El;

int is_empty(El *head){
    if(head==NULL){
        return 1;
    }else{
        return 0;
    }
}

void push(El** head, El* element){
    if(is_empty(*head)){
        *head=element;
        element->next=NULL;
    }else{
        element->next=*head;
        *head= element;
    }
}

El* pop(El **head){
    El* ret= *head;
    if(is_empty(*head)){
        return NULL;
    }else{
        *head= ret->next;
    }
    return ret;
}

int main(){
    El* pila = NULL;
    El* alice = NULL;
    El* bob = NULL;
    El* element;
    El* appoggioBob;
    El* appoggioAlice;
    int val;
    
   for(int k = 0; k < 4; k++){      //uso il doppio for per caricare i 13 numeri dei vari semi e i semi sono 4
        for(int i = 1; i < 14; i++){
            element = (El*) malloc(sizeof(El));

            element->num = i ;

            if(k == 0){         //verifico che i semi siano corretti
                element->seme = 'C';
            }
            if(k == 1){
                element->seme = 'P';
            }
            if(k == 2){
                element->seme = 'Q';
            }
            if(k == 3){
                element->seme = 'F';
            }
            if(k > 3){
                printf("non corretto");
            }

            printf("%d%c ", element->num, element->seme);   //stampo la pila principale(numero e seme)

            push(&pila, element);   //inserisco in pila i i numeri e i semi delle carte
        }
    }

    while (is_empty(pila) == 0) //si cicla finche la pila principale non è vuota per caricare le carte in bob e alice
    {
        val = rand() % 1 + 0; //serve per mettere randomicamente le carte a bob e ad alice
        if (val == 0) //controllo se il valore e' = 0 allora la carta verra assegnata a bob se esce 1 si assegna a alice
        {
            appoggioBob = (El*) malloc(sizeof(El)); //puntatore d'appoggio che serve per caricare in bob
            appoggioBob = pop(&pila);
            push(&bob,element); //carico nella pila bob le carte
        }else{
            appoggioAlice = (El*) malloc(sizeof(El));   //puntatore d'appoggio che serve per caricare in alice
            appoggioAlice = pop(&pila);
            push(&alice,element);   //carico nella pila alice le carte
        }
    }
    printf("caret di bob %d%c", alice->num,alice->seme);
    printf("carte di alice %d%c", bob->num,bob->seme);
    
}
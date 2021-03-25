//Creare un programma che dato un numero intero, avente un numero arbitrario di cifre inserite
//dall’utente, lo scriva in output con le cifre in ordine inverso. Utilizzare una pila e le implementazioni
//dei metodi push e pop.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct el{
    int valore;
    struct el* next;
}El;

int is_empty(El* head){
    
    if (head == NULL){
        return 1;
    }else{
        return 0;
    }
}

void push(El **head,El *element){
    if (is_empty(*head)){
        *head = element;
        element->next = NULL;
    }else{
        element->next = *head;
        *head = element;
    }
}

 El* pop(El **head){
    El *ret = *head;
    if(is_empty(*head)){
        return NULL ;
    }else{
        *head = ret->next;
    }
    return ret;
}

int main(){
    El* pila = (El*)malloc(sizeof(El));
    El* element;
    int num;

    printf("inserisci il numero: ");
    scanf("%d", &num);

    while (num != 0)
    {
        element = (El*)malloc(sizeof(El));
        element->valore = num % 10;
        push(&pila,element);

        num = num / 10;
    }

    while (is_empty(pila) != 0)
    {
        printf("%d", (pop(&pila))->valore);
    }
    


    
}
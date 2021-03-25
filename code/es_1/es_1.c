//Implementare i metodi enqueue() e dequeue()  e creare un programma che permetta
//all’utente di riempire una coda di numeri interi di lunghezza arbitraria. Successivamente
//testare la funzione dequeue per svuotare la coda.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct el{
    char valore;
    struct el* next;
}El;

int is_empty(El* head){
    if (head == NULL) return 1;
    else return 0;
}

void enqueue( El **head,  El **tail,  El *element){

    if(is_empty(*head)){
        *head = element;
    }else{
        (*tail)->next=element;
    }
    *tail = element;
    element->next=NULL;    
}


El * dequeue( El **head,  El **tail){
    El *ret = *head;
    if(is_empty(*head)){
        return NULL;
    }else{
        *head = ret->next;
    }
    if (*head==NULL){
        *tail = NULL;
    }
    return ret;
}

int main(){
    El* tail = (El*)malloc(sizeof(El));
    El* head = (El*)malloc(sizeof(El));
    tail = NULL;
    head = NULL;

    El* element;
    char risp;
    do
    {
        element = (El*)malloc(sizeof(El));

        printf("inserisci un numero: " );
        fflush(stdin);
        scanf("%d", &element->valore);

        enqueue(&head, &tail, element);

        printf("vuoi ancora caricare valori? ");
        fflush(stdin);
        scanf("%c", &risp);

    } while (risp == 's' || risp == 'S');

    while (element != NULL)
    {
        element = dequeue(&head, &tail);
        printf("%d\n", element->valore);
    }
    
    
}
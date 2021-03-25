#include <stdio.h>
#include <stdlib.h>
/*
Creare un programma che dato un numero intero, avente un numero arbitrario di cifre inserite
dall’utente, lo scriva in output con le cifre in ordine inverso. Utilizzare una pila e le implementazioni
dei metodi push e pop.
*/
typedef struct cifra{
    int n;
    struct cifra* next;
}Cifra;

int isEmpty(Cifra *struttura){
    if(struttura == NULL) return 1;
    return 0;
}
void push(Cifra** testa,Cifra* elemento){
    if(isEmpty(*testa)){
        *testa = elemento;
        elemento->next = NULL;
    }else{
        elemento->next = *testa;
        *testa = elemento;
    }
}
Cifra* pop(Cifra** testa){
    Cifra* ret = *testa;
    if(isEmpty(*testa)) return NULL;
    *testa = ret->next;
    return ret;
}

void pushModificato(Cifra** testa,int numero){
    if(isEmpty(*testa)){
        *testa = (Cifra*) malloc(sizeof(Cifra));
        (*testa)->n= numero;
        (*testa)->next = NULL;
    }else{
        Cifra* temp = (Cifra*) malloc(sizeof(Cifra));
        temp->next = *testa;
        temp->n = numero;
        *testa = temp;
    }
}
void rigiraPila(Cifra **pila){
    Cifra* pilaModificata = (Cifra*) malloc(sizeof(Cifra));
    while (*pila!=NULL){
        push(&pilaModificata,pop(pila));   
    }
    *pila = pilaModificata->next;
    return;    
}

void main(){
    int n;
    printf("inserire un numero");
    printf("ciao");
    scanf("%d",&n);
    int temp;
    Cifra* pila = (Cifra*) malloc(sizeof(Cifra));
    while (n!=0){
        temp = n%10;
        pushModificato(&pila,temp);
        n = n/10;
    }

    rigiraPila(&pila);

    while (pila->next!=NULL){
        printf("%d",pop(&pila)->n);
    }
    

}
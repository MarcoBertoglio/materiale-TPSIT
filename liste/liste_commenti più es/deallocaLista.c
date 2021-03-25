#include <stdio.h>
#include <stdlib.h>

typedef struct el
{
    int n;
    int valore;
    struct el* next;
}El;

void deallocaLista(El* lista){
    if(lista != NULL){
        deallocaLista(lista->next);
        free(lista);
    }
}

int main(){
    El* lista = NULL;
    El* l;
    int n;
    
    do{
        printf("inserisci un numero positivo per andare a vanti oppure -1 per uscire: ");
        scanf("%d", &n);
        if(n >= 0){
            if(lista == NULL){
                lista = ( El*)malloc(sizeof( El));

                l = lista;
            }else{
                l->next = (El*)malloc(sizeof(El));
                l = l->next;
            }
            l->valore = n;
            l->next = NULL;
        }
    }while(n >= 0);

    l = lista;
    while(l != NULL){
        printf("\n%d %p\n", l->valore, l->next);
        l = l->next;
    }
    deallocaLista(lista);
}
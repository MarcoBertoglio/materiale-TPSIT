#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo{
    int valore;
    struct nodo* successivo;
}Nodo;

void push(Nodo* lista, int n){
    El* l = lista;
    while(l->next != NULL){
        l = l->next;
    }
    l->next = (El*)malloc(sizeof(El));
    l->next->valore = n;
    //l->next->valore2 = n2 se volessi mettere in contemporaneamente due valori
    l->next->next = NULL;
}

void stampaLista_ricorsiva(Nodo* lista){
    //funzione ricorsiva
    if(lista == NULL){
        printf("------\n");
    }else
    {
        printf("-%d-\n", lista->valore);
        stampaLista_ricorsiva(lista->successivo);
    }
    
}

void stampaLista(El* l){
    while (l != NULL)
    {
        printf("%d - %p \n", l->valore, l->next);
        l = l->next; /* assegno ad l l'indirizzo della prossima struttura */
    }
}

int lunghezzaLista(Nodo* lista){
    int cnt = 0;
    while(lista != NULL){
        lista = lista->successivo;
        cnt++;
    }
    return cnt;
}

int lunghezzaLista_ricorsiva(Nodo* lista){
    if(lista == NULL){
        return 0;
    }else
    {
        return 1 + lunghezzaLista_ricorsiva(lista->successivo);//1 + 1 + 1 + 1 + 0
    }
    
}

void deallocaLista_ricorsiva(Nodo* lista){
    if(lista != NULL){
        deallocaLista(lista->successivo);
        printf("dealloco lista: %d\n", lista->valore);

        free(lista);
        printf("free: %d\n", lista->valore);
    }
}

lista->next(1->2->3->NULL)
lista->next(1->2->NULL)
lista->next(1->NULL)
lista->next(NULL)

void deallocaLista_iterattiva(struct El*lista){
    struct El* l;
    while(lista!=NULL){
        l=lista;
        lista=lista->next;
        free(l);
    }
}

void stampaLista(Nodo* lista){
    while (lista != NULL){
        printf("%d - %p \n", lista->valore, lista->successivo);
        lista = lista->successivo;  //fa puntare all'offset la prossima struttura 
    }
    return;
}

void trovaMassimo_iterattiva(Nodo* lista){
    int max = lista->valore;

    while(lista != NULL){
        if(lista->valore > max){
            max = lista->valore;
        }
        lista = lista->successivo;
    }
    printf("%d", max);
}

void trovaMassimo_ricorsiva(Nodo* lista){
    int max = lista->valore;
    if(lista == NULL){
        return 0;
    }else{
        if (max < lista->valore)
        {
            max = lista->valore;
        }
        return trovaMassimo_ricorsiva(lista->successivo);
        
    }
    printf("%d ", max);
}

Nodo* trovaMassimo(Nodo* lista){
    int max = lista->valore;
    Nodo* posMax = 0;
    while(lista != NULL){
        if(max < lista->valore){
            max = lista->valore;
            posMax = lista;
        }
        lista = lista->successivo;
    }
    printf("%d", max);
    return posMax;
}

int trovaNumPari_iterattiva(Nodo* lista){
    int cnt = 0;
    while (lista != NULL)
    {
        if(lista->valore % 2 == 0){
            cnt++;
        }
        lista = lista->successivo;
    }
    return cnt;
}

int trovaNumeri_ricorsiva(Nodo* lista){
    if(lista == NULL){
        return 0;
    }else{
        if(lista->valore % 2 == 0){
            return 1+trovaNumeri_ricorsiva(lista->successivo);
        }else{
            return trovaNumeri_ricorsiva(lista->successivo);
        }
    }
}

int ePresente(Nodo* lista,int n){
    while(lista != NULL){
        if(lista->valore == n){
            return 1;
        }else{
            return 0;
        }
        lista = lista->next;
    }
}

int main(){}
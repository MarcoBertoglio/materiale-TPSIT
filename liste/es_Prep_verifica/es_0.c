#include <stdio.h>
#include <stdlib.h>
struct El{
    int valore;
    struct El next;
};

void push(struct El lista,struct El* l){
    if (lista == NULL){ /* se lista non punta a niente /

                /usando la malloc alloco El in memoria. Assegna poi a l'indirizzo puntato alla lista */

        lista = (struct El )malloc(sizeof(struct El));

        l = lista;
    }else{ /* se la lista punta a qualcosa cioè è vuoto*/

         next di l /* (l sarebbe l'offset) viene allocato struttura El, e l punterà a next di l. */

        l->next = (struct El )malloc(sizeof(struct El));
        l = l->next;
    }
    return;
}

void stampaLista(struct El l){
    while (l != NULL){
        printf("%d - %p \n", l->valore, l->next);
        l = l->next; /* si incrementa l per farlo puntare alla lista succeaaiva */
    }
    return;
}
int main(){
    int n;
    struct El *lista;
    struct El l;
    lista = NULL; /* viene svuotata la lista successiva e non punta a niente */

    do{
        printf("Inserisci un naturale o -1 per terminare\n");
        scanf("%d", &n);
        if (n >= 0){
                push(lista,l);
            }
            l->valore = n;  /* viene inserito il numero naturale dentro la lista */
            l->next = NULL; /* cancella il contenuto del puntatore alla prossima struttura */
    } while (n >= 0);

    l = lista; /* fa puntare a l la prima struttura */
    printf("numeri inseriti: ");
    stampaLista(l);
    printf("\n");
    return 0;
}
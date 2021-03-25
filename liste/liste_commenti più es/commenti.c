#include <stdio.h>
#include <stdlib.h>
typedef struct el
{
    int valore;
    struct el *next;
}El;

void push(El* lista, int n){
    El* l = lista;
    while(l->next != NULL){
        l = l->next;
    }
    l->next = (El*)malloc(sizeof(El));
    l->next->valore = n;
    l->next->next = NULL;
}

void stampaLista(El* l){
    while (l != NULL)
    {
        printf("%d - %p \n", l->valore, l->next);
        l = l->next; /* assegno ad l l'indirizzo della prossima struttura */
    }
}

int main()
{
    int n;
    El *lista;
    //struct El *l;
    lista = NULL; /* assegna al punatore di tipo El NULL(cioè nonpunta a niente) */

    do
    {
        printf("Inserisci un naturale o -1 per terminare\n");
        scanf("%d", &n);
        if (n >= 0)
        {
            if (lista == NULL) /* chiedo se lista non punta a niente */
            {
                /* alloco in memoria una struttura El e l'indirizzo lo assegno a lista, assegno la struttura punatata da lista a l  */

                lista = (El *)malloc(sizeof(El));
                lista->valore = n;
                lista->next = NULL;

            }
            else /* entra nell'else se lista contiene un indirizzo */
            {
                /* alloco in memoria una struttura El e assegno l'indirizzo della struttura allocata ad l->next, assegno ad l la cella punata da l->next(vado alla struttura successiva) */

                push(lista, n);
            }
            //l->valore = n;  /* assegno alla struttura attuale nel campo valore il numero inserito da tastiera */
            //l->next = NULL; /* assegno all'indirizzo della prossima struttura NULL per indicare che è arrivata all'ultima */
        }
    } while (n >= 0);

    //lista assegno a l la struttura puntata da lista, quindi ala prima struttura 
    printf("numeri inseriti: ");
    stampaLista(lista);
    printf("\n");
    stampaLista(lista);
    return 0;
}
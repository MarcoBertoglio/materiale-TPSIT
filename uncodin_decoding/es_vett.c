#include <stdlib.h>
#include <stdio.h>
#define DIM 20


void uncoding(char v[], int n){                 //serve per comprimere e semplificare la stringa di caratteri
    printf("inserisci la stringa di caratteri: ");
    fflush(stdin);      //trattandosi di caratteri bisogna pulire ogni volta che si inserisce una serie di lettere
    scanf("%s", v);

    int cnt = 1;

    for(int k=0; v[k] != '\0'; k++){        //si controlla che il contenuto di una cella sia uguale a quella successiva e si fa fino
                                            //alla fine della stringa
        if(v[k] == v[k+1]){
            cnt++;
        }else{
            printf ("%d%c", cnt, v[k]) ;
            cnt = 1 ;
        }
    }
}

void decoding(char v[], int n){         //da un numero semplificato di stringhe lo si deve visualizzare per intero
    printf("\ninserisci la stringa di caratteri: ");
    fflush(stdin);
    scanf("%s", v);

    int temp = 0;
    int cnt = 1;

    for(int k=0; v[k] != '\0'; k++){        //lo si esegue fino alla fine della stringa
        temp = v[k] - 48;
        if(temp > 0 && temp <= 9){      //si controlla se il primo carattere che si trova sia un numero
            while(cnt < temp){          //se e' cosi' si scrive la lettera tante volte quanto e' il valore del numero visualizzato prima
                printf("%c", v[k+1]);
                cnt++;
            }
        }else{
            printf("%c", v[k]);
            cnt = 1;
        }
    }

}

void main(){
    char v[DIM];        //dichiarazione del vettore

    uncoding(v, DIM);
    decoding(v, DIM);
}

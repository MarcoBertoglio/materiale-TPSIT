#include <stdlib.h>
#include <stdio.h>
#define DIM 20


void comprimistringa(char v[], int n){
    printf("inserisci la stringa di caratteri: ");
    fflush(stdin);
    scanf("%s", v);

    int cnt = 1;

    for(int k=0; v[k] != '\0'; k++){
        if(v[k] == v[k+1]){
            cnt++;
        }else{
            printf ("%d%c", cnt, v[k]) ;
            cnt = 1 ;
        }
    }
}

void decoding(char v[], int n){
    printf("\ninserisci la stringa di caratteri: ");
    fflush(stdin);
    scanf("%s", v);

    int temp = 0;
    int cnt = 1;

    for(int k=0; v[k] != '\0'; k++){
        temp = v[k] - 48;
        if(temp > 0 && temp <= 9){
            while(cnt < temp){
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
    char v[DIM];

    comprimistringa(v, DIM);
    decoding(v, DIM);
}

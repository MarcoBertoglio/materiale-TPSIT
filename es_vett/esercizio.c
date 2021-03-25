/*
Author: Bertoglio Marco
Date :
es :
*/
#include <stdlib.h>
#include <stdio.h>
#define DIM 100

void visVettFloat(float v[], int n){
    int k;
    for(k = 0; k < n; k++){
        printf("%f", v[k]);
    }
}

main(){
    float r;
    int n;
    float v[DIM];
    int k = 0;
    float x  = 1;

    printf("inserisci il numero di contagi: ");
    scanf("%f", &r);
    printf("inserisci il numero di alunni: ");
    scanf("%d", &n);

    do{
       x = x * r;
       v[k] = x;
       k++;
    }while(x < (float)n);

    for(int i = 0; i < k; i++){
        printf("i contagi sono: %.2f\n", v[i]);
    }

    printf("\n%d giorni", k);

	printf("\n premi un tasto per uscire");
	getch();
}

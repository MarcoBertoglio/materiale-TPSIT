#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define DIM 100

typedef struct canzone
{
    int num;
    char autore[DIM];
    char nome[DIM];
    int val;
    struct canzone *next; //prima della riga 11 non si può utulizzare Canzone perchè C non lo ha ancora eseguito
} Canzone;

void leggiFile(FILE *fp, Canzone *primaCanzone, int *cnt)
{
    char* riga = (char*)malloc(sizeof(char) * 200);
    Canzone *temp = primaCanzone;
    while (fgets(riga, 200, fp))
    {
        temp->num = atoi(strtok(riga, ","));
        strcpy(temp->autore, strtok(NULL, ","));
        strcpy(temp->nome, strtok(NULL, ","));
        temp->next = (Canzone*)malloc(sizeof(Canzone));
        temp->val = rand()%10000000;
        temp = temp->next;
        free(riga);
        riga = (char*)malloc(sizeof(char) * 200);      //svuoto la riga e la rialloco in memoria
        *cnt += 1;
    }
    return;
}

Canzone* accediCanzone(Canzone* primaCanzone, int cnt){
    Canzone* temp = primaCanzone;
    for(int k = 0;k < cnt; k++){
        temp = temp->next;
    }
    return temp;
}

void canzoniRandom(Canzone* primaCanzone, int cnt){
    Canzone* temp;
    int max = primaCanzone->num;
    int posMax = 0;
    for(int k = 0; k < cnt; k++){
        temp = primaCanzone;
        for(int i=0; i < cnt; i++){
            if(max < temp->val){
                max = temp->val;
                posMax = i;
            }
            temp = temp->next;
        }
        temp = accediCanzone(primaCanzone, posMax);
        printf("canzone: %d %s %s", temp->num, temp->autore, temp->nome);
        max = 0;
        posMax = 0;
        temp->val = -1;
    }
}

int main()
{
    FILE *fp;
    fp = fopen("canzoni.csv", "r");
    if (fp == NULL)
    {
        printf("il file non esiste");
    }
    else
    {
        int cnt = 0;
        Canzone *primaCanzone = (Canzone *)malloc(sizeof(Canzone));
        leggiFile(fp, primaCanzone, &cnt);
        canzoniRandom(primaCanzone, cnt);
    }
}
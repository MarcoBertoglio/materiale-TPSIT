#include <stdlib>
#include <stdio>
#include <stdbool.h>
#include <stringh.h>
#define LUNG 20
#define DIM 100;

typedef struct spotify{
    int num;
    char canzone[LUNG];
    char autore[LUNG];
}Spotify;

void main(){
    Spotify canzone;
    char car;
    int cnt = 0;
    Spotify vett[DIM];
    FILE *fp;
    char nomeFile[] = "canzoni.csv";
    char car;
    fp = fopen(nomeFile, "r");
    if(fp == NULL){
        printf("il file non esiste");
    }else{
        while(fscanf(fp,"%c", car) != EOF){
            vett[cnt] = car;
            printf("le canzoni sono: %c", vett[cnt]);
            cnt++;
        }
    }
}
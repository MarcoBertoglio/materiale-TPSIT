//Un drone registra i dati di volo in due file .csv. Nel file Volo_drone.csv esso registra la sua 
//posizione (latitudine e longitudine) ogni 5 secondi. 
//Nel file Anomalie_drone.csv, il drone registra eventuali anomalie avvenute durante 
//il volo indicando soltanto il tempo al quale si è verificata l'anomalia.
//Scrivere un programma in C, che faccia uso della allocazione dinamica e della aritmetica dei 
//puntatori (requisiti obbligatori): il programma deve calcolare latitudine e longitudine alle 
//quali si sono verificate tutte le anomalie avvenute durante il volo.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#define DIM 200

typedef struct drone{   //struttura
    int tempo;
    float latitudine;
    float longitudine;
    char* anomalia;
}Drone;

int contaRighe(FILE *fp){       //conte il numero di righe presenti nei 
                                //file assegnando il valore a una variabile nel main
    int cnt = 0;
    char* riga = (char*) malloc(sizeof(char)*DIM);

    while(fgets(riga,200,fp)){
        cnt++;
    }
    free(riga);
    return cnt;
}

void leggiFile(Drone* volo, FILE *fp){      //leggo il contenuto del file volo_drone
    int cnt = 0;
    char* riga = (char*) malloc(sizeof(char)*DIM);

    while(fgets(riga,DIM,fp)){
        (volo+cnt)->tempo=atoi(strtok(riga,","));
        (volo+cnt)->latitudine = atof(strtok(NULL,","));
        (volo+cnt)->longitudine = atof(strtok(NULL,","));
        cnt++;
    }
    free(riga);
    return;
}

void leggiFile2(FILE *fp,Drone* volo){      //leggo il conenuto del file anomalie_drone 
    int cnt = 0;
    char* riga = (char*) malloc(sizeof(char)*DIM);

    while(fgets(riga,DIM,fp)){
        (volo+cnt)->tempo = atoi(strtok(riga,","));
        strcpy((volo+cnt)->anomalia,strtok(NULL,","));
    }
    free(riga);
    return;
}

void stampaAnomalie(Drone* volo, int n1, int n2){    //stampa la latitudine e la longitudine delle anomalie
                                                    //che riscontra
    for(int k = 0; k< n2; k++){
        for(int i = 0; i<n1;i++){
            if((volo+k)->tempo == (volo+i)->tempo){
                printf("anomalia in: latitudine %f, longitudine %f", (volo+i)->latitudine, (volo+i)->longitudine);
            }
        }
    }
    return;
}

int main(){
    FILE *fp;
    int dim1, dim2;

    fp = fopen("volo_drone.csv", "r");
    if(fp == NULL){
        printf("il file non esiste");
    }else{
        dim1 = contaRighe(fp);      
        fclose(fp);
        fp = fopen("volo_drone","r");
        Drone *volo = (Drone*) malloc(sizeof(Drone)*DIM);   //metodo malloc: dimensione massima del puntantore
        leggiFile(volo, fp);
        fclose(fp);
        fp = fopen("anomalie_drone.csv","r");
        if(fp == NULL){
            printf("il file non esiste");
        }else{
            dim2 = contaRighe(fp);
            fclose(fp);
            fp = fopen("anomalie_drone.csv","r");
            leggiFile2(fp,volo);
            fclose(fp);
            stampaAnomalie(volo, dim1, dim2);

        }

    }
    free(volo);
}
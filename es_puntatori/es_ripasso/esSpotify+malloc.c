#include <stdlib.h>
#include <stdio.h>
#include <string.h> 
#define MAX 10
#define MIN 1

typedef struct playlist{
    int num;
    char* canzone;
    char* artista;
}Playlist;

int contaRighe(FILE *fp){
    int cnt = 0;
    char* riga = (char*) malloc(sizeof(char)*200);

    while(fgets(riga,200,fp) != NULL){
        cnt++;
    }
    free(riga);
    return cnt;
}
void leggiFile(Playlist* canzone, int n, FILE *fp){
    char* riga=(char*) malloc(sizeof(char)*200);
    int cnt=0;
    while(fgets(riga,200,fp) != NULL){
        (canzone+cnt)->num = atoi(strtok(riga,","));
        strcpy((canzone+cnt)->canzone,strtok(NULL,","));
        strcpy((canzone+cnt)->artista,strtok(NULL,","));
        cnt++;
    }
    printf("ciao");
    free(riga);
    return;
}

void canzoniRandom(Playlist* canzone, int n){
    int temp;
    for(int k=0;k<n;k++){
        do{
            temp = rand()% (MAX-MIN+1)+MIN;
        }while((canzone+temp)->num == -1);
        (canzone+temp)->num = -1;
        printf("%s %s\n", (canzone+temp)->canzone, (canzone+temp)->artista);
    }
}

int main(){
    FILE *fp;
    fp = fopen("canzoni.csv", "r");
    if(fp == NULL){
        printf("il file non esiste");
    }else{
        int dim = contaRighe(fp);
        fclose(fp);
        fp = fopen("canzoni.csv","r");
        Playlist* canzone = (Playlist*) malloc(sizeof(Playlist)*dim);
        leggiFile(canzone,dim,fp);
        fclose(fp);
        canzoniRandom(canzone,dim);
    }
}
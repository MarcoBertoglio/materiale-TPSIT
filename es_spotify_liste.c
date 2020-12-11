#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct canzone{
    int numero;
    char autore[100];
    char nome[100];
    int val;
    struct canzone* next;
}Canzone;

void leggiFile(Canzone* playlist,FILE* fp,int *cnt){
    char* riga = (char *) malloc(sizeof(char)*200);
    Canzone* temp = playlist;
    while(fgets(riga,200,fp)){
        temp->numero=atoi(strtok(riga,","));
        strcpy(temp->autore,(strtok(NULL,",")));
        strcpy(temp->nome,strtok(NULL,","));
        temp->next = (Canzone*) malloc(sizeof(Canzone)); 
        temp->val=rand()%10000000;
        temp=(temp->next);
        *cnt += 1; 
        free(riga);
        riga=(char *)malloc(sizeof(char)*200);      
    }
    free(temp);
    return;
}

Canzone* accediCanzone(Canzone* playlist,int numero){
    Canzone* temp = playlist;
    for(int i=0;i<numero;i++){
        temp=temp->next;
    }
    return temp;
}


void canzoniRandom(Canzone* playlist,int cnt){
    int max,posMax;
    Canzone* temp;
    for(int j=0;j<cnt;j++){
        temp=playlist;
        posMax=0;
        max=temp->val;
        for(int x=0;x<cnt;x++){
            if(max<temp->val){
                max=temp->val;
                posMax=x;
            }
            temp=temp->next;
        }
        temp=accediCanzone(playlist,posMax);
        printf("%d %s %s\n",temp->numero,temp->nome,temp->autore);
        temp->val=-100-posMax;
    }
    return;
}


void main(){
    srand(time(NULL));
    FILE *fp;
    if((fp=fopen("canzoni.csv","r"))==NULL){
        printf("il file non esiste");
    }else{
        int cnt=0;
        Canzone* playlist = (Canzone *) malloc(sizeof(Canzone));
        leggiFile(playlist,fp,&cnt);
        
        fclose(fp);
        canzoniRandom(playlist,cnt);
        free(playlist);
    }
    return;
}
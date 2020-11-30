#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct regione{
    char data[200];
    char stato[200];
    int codice_regione;
    char denominazione_regione[200];
    float lat;
    float longit;
    int ricoverati_con_sintomi;
    int terapia_intensiva;
    int totale_ospedalizzati;
    int isolamento_domiciliare;
    int totale_positivi;
    int variazione_totale_positivi;
    int nuovi_positivi;
    int dimessi_guariti;
    int deceduti;
    int casi_da_sospetto_diagnostico;
    int casi_da_screening;
    int totale_casi;
    int tamponi;
    int casi_testati;
    bool temp;
}Regione;

int contaRighe(FILE *fp){
    int cntRighe = 0;
    char* riga;
    riga = (char*) malloc(sizeof(char)*200);
    while(fgets(riga,200, fp)){
        cntRighe++;
        free(riga);
        riga = (char*) malloc(sizeof(char)*200);
    }
    return cntRighe;
}

/*void leggiFile(FILE *fp, Regione* covid){
    char* vet;
    int cnt=0;
    vet = (char*) malloc(sizeof(char)*200);
    while(fgets(vet,200,fp)){
        strcpy((covid+cnt)->data,strtok(vet,","));
        strcpy((covid+cnt)->stato,strtok(NULL,","));
        (covid+cnt)->codice_regione = atoi(strtok(NULL,","));
        strcpy((covid+cnt)->denominazione_regione,strtok(NULL,","));
        (covid+cnt)->lat = atof(strtok(NULL,","));
        (covid+cnt)->longit = atof(strtok(NULL,","));
        (covid+cnt)->ricoverati_con_sintomi=atoi(strtok(NULL,","));
        (covid+cnt)->terapia_intensiva=atoi(strtok(NULL,","));
        (covid+cnt)->totale_ospedalizzati=atoi(strtok(NULL,","));
        (covid+cnt)->isolamento_domiciliare=atoi(strtok(NULL,","));
        (covid+cnt)->totale_casi=atoi(strtok(NULL,","));
        (covid+cnt)->variazione_totale_positivi=atoi(strtok(NULL,","));
        (covid+cnt)->nuovi_positivi=atoi(strtok(NULL,","));
        (covid+cnt)->dimessi_guariti=atoi(strtok(NULL,","));
        (covid+cnt)->deceduti=atoi(strtok(NULL,","));
        (covid+cnt)->casi_da_sospetto_diagnostico=atoi(strtok(NULL,","));
        (covid+cnt)->casi_da_screening=atoi(strtok(NULL,","));
        (covid+cnt)->totale_casi=atoi(strtok(NULL,","));
        (covid+cnt)->tamponi=atoi(strtok(NULL,","));
        (covid+cnt)->casi_testati=atoi(strtok(NULL,","));
        //(covid+cnt)->temp=true;
        printf("%d", (covid+cnt)->codice_regione);
        cnt++;
    }
    free(vet);
    return;
}
*/

void leggiFile(FILE* fp, Regione* regioni){
    char* reg = (char*) malloc(sizeof(char)*1000);
    int cnt=0;
    while(fgets(reg,1000,fp)){
        strcpy((regioni+cnt)->data ,strtok(reg,","));
        strcpy((regioni+cnt)->stato ,strtok(NULL,","));
        (regioni+cnt)->codice_regione=atoi(strtok(NULL,","));
        strcpy((regioni+cnt)->denominazione_regione,strtok(NULL,","));
        (regioni+cnt)->lat=atof(strtok(NULL,","));
        (regioni+cnt)->longit=atof(strtok(NULL,","));
        (regioni+cnt)->ricoverati_con_sintomi=atoi(strtok(NULL,","));
        (regioni+cnt)->terapia_intensiva=atoi(strtok(NULL,","));
        (regioni+cnt)->totale_ospedalizzati=atoi(strtok(NULL,","));
        (regioni+cnt)->isolamento_domiciliare=atoi(strtok(NULL,","));
        (regioni+cnt)->totale_casi=atoi(strtok(NULL,","));
        (regioni+cnt)->variazione_totale_positivi=atoi(strtok(NULL,","));
        (regioni+cnt)->nuovi_positivi=atoi(strtok(NULL,","));
        (regioni+cnt)->dimessi_guariti=atoi(strtok(NULL,","));
        (regioni+cnt)->deceduti=atoi(strtok(NULL,","));
        (regioni+cnt)->casi_da_sospetto_diagnostico=atoi(strtok(NULL,","));
        (regioni+cnt)->casi_da_screening=atoi(strtok(NULL,","));
        (regioni+cnt)->totale_casi=atoi(strtok(NULL,","));
        (regioni+cnt)->tamponi=atoi(strtok(NULL,","));
        (regioni+cnt)->casi_testati=atoi(strtok(NULL,","));
        (regioni+cnt)->temp=true;
        cnt++;
    }
    free(reg);
    return;
}

void topIntensiva(Regione* covid, int cnt){
    int max = 0;
    for(int i=0;i < 3; i++){
        max = 0;
        while((covid+max)->temp == false){
            max += 1;
        }
        for(int k=0; k<cnt;k++){
            if((covid+max)->terapia_intensiva < (covid+k)->terapia_intensiva && (covid+k)->temp == true){
                max = k;
            }
        }
        printf("%s\n ", (covid+max)->denominazione_regione);
        (covid+max)->temp = false;
    }
}

void totTerapiaIntensiva(Regione* covid, int cnt){
    int somma=0;
    for(int k=0;k<cnt;k++){
        somma = somma+(covid+k)->terapia_intensiva;
    }
    printf("%d\n ", somma);
}

void menoCasiPos(Regione* covid, int cnt){
    int min = 0;
    for(int i=0;i < 3; i++){
        min = 0;
        while((covid+min)->temp == false){
            min += 1;
        }
        for(int k=0; k<cnt;k++){
            if((covid+min)->totale_positivi > (covid+k)->totale_positivi && (covid+k)->temp == true){
                min = k;
            }
        }
        printf("%s ", (covid+min)->denominazione_regione);
        (covid+min)->temp = false;
    }
}

int main(){
    FILE *fp;

    fp = fopen("covid.csv", "r");
    if(fp == NULL){
        printf("il file non esiste");
    }else{
        int cnt = contaRighe(fp);
        fclose(fp);
        fp = fopen("covid.csv", "r");
        Regione* covid;
        covid = (Regione*) malloc(sizeof(Regione)*cnt);
        leggiFile(fp, covid);
        fclose(fp);
        printf("top 3 terapia intensiva:\n");
        topIntensiva(covid,cnt);
        printf("tot terapia intensiva: ");
        totTerapiaIntensiva(covid,cnt);
        printf("meno casi positivi: ");
        menoCasiPos(covid,cnt);
    }
    return 0;
}
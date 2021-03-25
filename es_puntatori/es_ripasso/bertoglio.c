#include <stdlib.h>
#include <stdio.h>
#include <string.h> 
#define MIN 1
#define DIM 100 


typedef struct playlist{
    int num;
    char canzone[DIM] ;     //char *canzone è un errore perchè deve essere una stringa, non un carattere
    char artista[DIM] ;     //char *artista è un errore perchè deve essere una stringa, non un carattere
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
    free(riga);
    return;
}

void canzoniRandom(Playlist* canzone, int n){       
    int temp;
    for(int k=0;k<n;k++){
        do{
            temp = rand()% (n-MIN+1)+MIN;
        }while((canzone+temp)->num == -1);
        (canzone+temp)->num = -1;
        printf("%s %s\n", (canzone+(temp % n))->canzone, (canzone+(temp % n))->artista); 

        //(canzone + temp)->canzone non funziona perchè temp fa uscire canzone dalla parte di memoria dove è contenuto il vettore.
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
        
        Playlist* canzone = (Playlist*) malloc(sizeof(Playlist)*dim);

        fp = fopen("canzoni.csv","r");
        leggiFile(canzone,dim, fp);
        fclose (fp) ;

        for (int k = 0; k < dim; k++) {
            printf ("%d %s %s\n", (canzone + k)->num, (canzone + k)->artista, (canzone + k)->canzone);
        }
        printf ("RANDOM\n");
        canzoniRandom(canzone,dim);
    }
}
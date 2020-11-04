/*marco Bertoglio
es leggi da file .csv
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 100

typedef struct canzone{
    int numero;
    char autore[DIM];
    char nome[DIM];
    int val;
}Canzone;

void leggiFile(Canzone playlist[],FILE *fp,int *cnt){       //*cnt è il numero di canzoni
    char lettera;           // lettera che legge nel file (lettera per lettera)
    char parola[DIM];       //parola completa (successione di tutte le lettere prima della ',')
    int indice=0;           // indice che serve a capire cosa sto leggendo
    while(fscanf(fp,"%c",&lettera)!=EOF){       //legge lettera
        if(lettera==','){               // se è arrivata alla fine della parola
            parola[strlen(parola)]='\0';        //aggiunge alla fine della parola completa '0'
            /*
            INDICE:
            0-> numero della canzone
            1-> titolo della canzone
            2-> autore della canzone
            */
            switch (indice){
                case 0:
                    playlist[*cnt].numero=(*cnt)+1;
                    break;
                case 1:
                    strcpy(playlist[*cnt].nome,parola);
                break;
                case 2:
                    strcpy(playlist[*cnt].autore,parola);
                break;
            }
            indice=(indice+1)%3;        //incremento indice
            memset(&parola[0],0,sizeof(parola));        //azzera parola
            if(indice==0)               //se ho finito di leggere la canzone
                *cnt = *cnt + 1;        //incremento contatore canzone
        }else{
            parola[strlen(parola)]=lettera;     //aggiunge alla fine della parola l'ultima lettera letta
        }
    }
    return;
}

void canzoniRandom(Canzone playlist[],int cnt){
    srand(time(NULL));
    for(int i=0;i< cnt;i++)
        playlist[i].val=rand()%10000000;
    int max=0;
    for(int i=0;i<cnt;i++){
        max=i;
        for(int j=0;j<cnt;j++){
            if(playlist[max].val<playlist[j].val){
                max=j;
            }
        }
        printf("%d %s %s %d\n",playlist[max].numero,playlist[max].nome,playlist[max].autore,playlist[max].val);
        playlist[max].val=-DIM+i;
    }
    return;
}

void main(){
    Canzone playlist[DIM];
    FILE *fp;
    if((fp=fopen("spotify.csv","r"))==NULL){
        printf("il file non esiste");
    }else{
        int cnt=0;
        leggiFile(playlist,fp,&cnt);
        canzoniRandom(playlist,cnt);
    }

    /*for(int i=0;i<cnt;i++){
        printf("numero: %d %s %s\n",playlist[i].numero,playlist[i].nome,playlist[i].autore);
    }*/
    return;
}

/*
 * testo composto da caratteri alfanumerici isalnum
 * parole divise da spazi o segni di punteggiatura (isspace ispunct)
 *
 * localizzare in un testo
 *
 * occorenze di ogni parola che contiene una certa sequenza di caratteri
 *
 * file sorgente
 * prima riga -> numero totale sequenze (20)
 * righe succesive -> sequenze da ricercare
 *      lunghezza sequenza max 5
 *      trascurare differenza maiuascole e minuscole
 *
 * file testo
 *      numero riga non noto a priori
 *      max lunghezza riga 200
 *      max lunghezza parola 25
 *
 * visualizzare:
 *      per ogni sequenza
 *          quali parole contengono la sequenza
 *          dove si trovano
 *              posizione: parola n.esima a partire dall inizio del testo
 *
 */



#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define maxsequenze 20
#define lensequenze 5
#define lenparola 25

struct sequenza{
    char ricodifica[lensequenze];
};
void leggi_dim(int *dim, FILE *fpsequenza);
void caricasequenza(struct sequenza sqz[], int dim, FILE *fpsequenza);
void verifica(struct sequenza sqz[],char c[], int dim, int count);

int main(){
    FILE *fptesto,*fpsequenza;
    struct sequenza sqz[maxsequenze];
    char c[lenparola];
    int dim,i,count=1;
    fptesto=fopen("../input0.txt","r");
    fpsequenza=fopen("../sorgente.txt","r");

    if(fptesto!=NULL && fpsequenza!=NULL){
        //lettura sequenza
        leggi_dim(&dim,fpsequenza);
        caricasequenza(sqz,dim,fpsequenza);

        //testo
            while(!feof(fptesto)) {
                fscanf(fptesto,"%s",c);
                //printf("%s ",c);
                //tolower
                for(i=0;i<strlen(c);i++){
                    c[i]=tolower(c[i]);
                }
                verifica(sqz,c,dim,count);
                count++;
            }
    }else{
        printf("errore file");
    }

    fclose(fptesto);
    fclose(fpsequenza);
    return 0;
}

void leggi_dim(int *dim, FILE *fpsequenza){
    do{
        fscanf(fpsequenza,"%d",dim);
    }while(*dim<=0 || *dim>maxsequenze);
}

void caricasequenza(struct sequenza sqz[], int dim, FILE *fpsequenza){
    int i;
    for(i=0;i<dim;i++){
        fscanf(fpsequenza,"%s",sqz[i].ricodifica);
    }
}

void verifica(struct sequenza sqz[],char c[], int dim, int count){
    int i;
    for(i=0;i<dim;i++){
        if (strstr(c, sqz[i].ricodifica) != NULL) {
            printf("la sequenza %s e' contenuta in %s, in posizione alla %d-isema parola\n",sqz[i].ricodifica,c,count);
        }
    }
}


/*
 * compattare spazi multipli in spazi singoli
 * aggiunga la meta arrontandata all inferiore degli spazi elimati all inizio
 *
 * output
 * elaborazione effettuata nei 2 punti
 *
 */

#include <stdio.h>
#define MAXN 80

int main(){
    FILE *fpin;
    char riga[MAXN];
    int i,j,dimensionespazi;
    fpin=fopen("../input0.txt","r");
    if(fpin!=NULL){
        while(!feof(fpin)) {
            fgets(riga,MAXN,fpin);
            i=0;
            j=0;
            while(riga[i]!='\0'){
                if(i==0 || riga[i]!=' ' || riga[i-1]!=' '){
                    riga[j++]=riga[i]; //riscrivo dall inizio il vettore se e solo se sto
                    // nella prima posizione, il carattere attuale è diverso da spazio o quello
                    // precedente è diverso da spazio
                }
                i++;
            }
            dimensionespazi=(i-j)/2;//i-j sono il numero di spazi
            for(i=dimensionespazi;i>=0;i--){
                printf(" ");//inserisco spazi all inizio della stampa
            }
            printf("%s",riga);//stampo riga sovrascritta
        }
    }else{
        printf("errore nei file");
    }
    fclose(fpin);
    return 0;
}

/*
 * campionato max 20 squadre
 * max 20 giornate
 * matrice mxn
 * riga matrice punti n squadre nelle m giornate
 * 3 win 1 draw 0 lost
 *
 * risultati giornata k esima sono contenuti nelle righe della colonna l
 *
 * acquisire matrice da file
 *
 * per ogni giornata del campionato
 * stampi l indice capolista
 */

#define n 20
#define m 20
#include <stdio.h>


void leggi_dim(int *dimrighe, int *dimcolonne, FILE *fpin);
void caricamatrice(int campionato[][m], int team[],  int dimrighe,int dimcolonne,FILE *fpin);
void cercamassimo(int team[],int dimcolonne);
int main(){
    FILE *fpin;
    int dimrighe,dimcolonne;
    int campionato[n][m];
    int team[n];
    fpin=fopen("../mat.txt","r");
    leggi_dim(&dimrighe,&dimcolonne,fpin);
    caricamatrice(campionato,team,dimrighe,dimcolonne,fpin);
    fclose(fpin);
    return 0;
}

void leggi_dim(int *dimrighe, int *dimcolonne, FILE *fpin){
    do{
        fscanf(fpin,"%d %d",dimrighe,dimcolonne);
    }while(*dimrighe>n && *dimcolonne>m);
}

void caricamatrice(int campionato[][m],int team[],int dimrighe,int dimcolonne,FILE *fpin){
    int i,j;
    int flag_inizializzavettore=0;
    for(i=0;i<dimrighe;i++){
        for(j=0;j<dimcolonne;j++){
            fscanf(fpin,"%d",&campionato[i][j]);
            if(flag_inizializzavettore==0){
                team[j]=campionato[i][j];
            }else{
                team[j]=team[j]+campionato[i][j];
            }
        }
        cercamassimo(team,dimcolonne);
        flag_inizializzavettore=1;
    }
}

void cercamassimo(int team[],int dimcolonne){
    int i;
    int ricordaindice;
    int massimo=team[0];
    for(i=0;i<dimcolonne;i++){
        if(team[i]>=massimo){
            ricordaindice=i;
            massimo=team[i];
        }
    }
    printf("team capolista n.%d\n",ricordaindice);
}

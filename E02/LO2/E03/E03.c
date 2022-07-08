#define MAXN 30
#define S 100
#include <stdio.h>
#include <string.h>
#define inputext "../mat.txt"

void leggi_dim(int *dimrighe, int *dimcolonne, FILE *fpin);
void caricamatrice(int matrix[][MAXN],  int dimrighe,int dimcolonne,FILE *fpin);
void operazione(int matrix[][MAXN],  int dimrighe,int dimcolonne,char selettore[],int indice,char direzione[],int posizioni);
void ruotadestrariga(int matrix[][MAXN],int dimcolonne,int indice,int posizioni);
void ruotasinistrariga(int matrix[][MAXN],int dimcolonne,int indice,int posizioni);
void ruotasucolonna(int matrix[][MAXN],int dimrighe,int indice,int posizioni);
void ruotagiucolonna(int matrix[][MAXN],int dimrighe,int indice,int posizioni);
void visualizzamatrice(int matrix[][MAXN], int dimrighe,int dimcolonne);

int main(){
    FILE *fpin;
    int dimrighe,dimcolonne;
    int matrix[MAXN][MAXN];
    char selettore[S];
    int indice;
    char direzione[S];
    int posizioni;
    fpin=fopen(inputext,"r");
    leggi_dim(&dimrighe,&dimcolonne,fpin);
    caricamatrice(matrix,dimrighe,dimcolonne,fpin);

    while(strcmp(selettore,"fine")!=0){
        printf("inserisci tuo comando\n");
        fflush(stdin);
        scanf("%s %d %s %d",selettore,&indice,direzione,&posizioni);
        if(strcmp(selettore,"fine")!=0){
            indice=indice-1;
            operazione(matrix,dimrighe,dimcolonne,selettore,indice,direzione,posizioni);
       }
    }
    fclose(fpin);
    return 0;
}

void leggi_dim(int *dimrighe, int *dimcolonne, FILE *fpin){
    do{
        fscanf(fpin,"%d %d",dimrighe,dimcolonne);
    }while(*dimrighe>MAXN && *dimcolonne>MAXN);
}

void caricamatrice(int matrix[][MAXN], int dimrighe,int dimcolonne,FILE *fpin){
    int i,j;
    for(i=0;i<dimrighe;i++){
        for(j=0;j<dimcolonne;j++){
            fscanf(fpin,"%d",&matrix[i][j]);
        }
    }
}

void operazione(int matrix[][MAXN],  int dimrighe,int dimcolonne, char selettore[],int indice,char direzione[],int posizioni){

    if(strcmp(selettore,"riga")==0){
        if(strcmp(direzione,"dx")==0){
            ruotadestrariga(matrix,dimcolonne,indice,posizioni);
            visualizzamatrice(matrix,dimrighe,dimcolonne);
        }else if(strcmp(direzione,"sx")==0){
            ruotasinistrariga(matrix,dimcolonne,indice,posizioni);
            visualizzamatrice(matrix,dimrighe,dimcolonne);
        }
    }else if(strcmp(selettore,"colonna")==0){
        if(strcmp(direzione,"su")==0){
            ruotasucolonna(matrix,dimrighe,indice,posizioni);
            visualizzamatrice(matrix,dimrighe,dimcolonne);
        }else if(strcmp(direzione,"giu")==0){
            ruotagiucolonna(matrix,dimrighe,indice,posizioni);
            visualizzamatrice(matrix,dimrighe,dimcolonne);
        }
    }
}

void ruotadestrariga(int matrix[][MAXN],int dimcolonne,int indice,int posizioni){
    int tmp;
    int i,j;
    for(j=0;j<(posizioni%dimcolonne);j++) {
        tmp = matrix[indice][dimcolonne-1];
        for (i = dimcolonne-1; i >0; i--) {
            matrix[indice][i]=matrix[indice][i-1];
        }
        matrix[indice][0]=tmp;
    }
}

void ruotasinistrariga(int matrix[][MAXN],int dimcolonne,int indice,int posizioni){
    int tmp;
    int i,j;
    for(j=0;j<(posizioni%dimcolonne);j++) {
        tmp = matrix[indice][0];
        for (i = 0; i<dimcolonne-1; i++) {
            matrix[indice][i]=matrix[indice][i+1];
        }
        matrix[indice][dimcolonne-1]=tmp;
    }
}

void ruotasucolonna(int matrix[][MAXN],int dimrighe,int indice,int posizioni){
    int tmp;
    int i,j;
    for(j=0;j<(posizioni%dimrighe);j++) {
        tmp = matrix[0][indice];
        for (i = 0; i<dimrighe-1; i++) {
            matrix[i][indice]=matrix[i+1][indice];
        }
        matrix[dimrighe-1][indice]=tmp;
    }
}

void ruotagiucolonna(int matrix[][MAXN],int dimrighe,int indice,int posizioni){
    int tmp;
    int i,j;
    for(j=0;j<(posizioni%dimrighe);j++) {
        tmp = matrix[dimrighe-1][indice];
        for (i = dimrighe-1; i>0; i--) {
            matrix[i][indice]=matrix[i-1][indice];
        }
        matrix[0][indice]=tmp;
    }
}

void visualizzamatrice(int matrix[][MAXN],int dimrighe, int dimcolonne){
    int i,j;
    for(i=0;i<dimrighe;i++){
        for(j=0;j<dimcolonne;j++){
            printf("%d",matrix[i][j]);
        }
        printf("\n");
    }
}

/*
3 3
1 2 3
4 5 6
7 8 9
*/

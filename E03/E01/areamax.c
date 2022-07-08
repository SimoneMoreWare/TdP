#include <stdio.h>
#define MAXN 50

void leggi_dim(int *dimrighe, int *dimcolonne, FILE *fpin);
void caricamatrice(int matrix[][MAXN],  int dimrighe,int dimcolonne,FILE *fpin);
void stampasommarighe(int matrix[][MAXN],  int dimrighe,int dimcolonne);
int max_area_histogram(int appoggio[], int dimcolonne);
int minimo(int a, int b);
int massimo(int a, int b);

int main(){
    FILE *fpin;
    int dimrighe,dimcolonne;
    int matrix[MAXN][MAXN];

    fpin=fopen("../input0.txt","r");
    if(fpin!=NULL){
        leggi_dim(&dimrighe,&dimcolonne,fpin);
        caricamatrice(matrix,dimrighe,dimcolonne,fpin);
        stampasommarighe(matrix,dimrighe,dimcolonne);
    }else{
        printf("A MOCC A MAMT");
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
            //printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

void stampasommarighe(int matrix[][MAXN],  int dimrighe,int dimcolonne){
    int i,j;
    int appoggio[dimcolonne];
    int max=0;
    int result;
    for (i=0;i<dimrighe;i++){
        for(j=0;j<dimcolonne;j++){
            if(matrix[i][j]==0){
                appoggio[j]=0;
            }else{
                if(i!=0) {
                    appoggio[j] = appoggio[j] + matrix[i][j];
                }else{
                    appoggio[j] = matrix[i][j];
                }
            }
            printf("%d ",appoggio[j]);
        }
        result=max_area_histogram(appoggio,dimcolonne);
        if(result>max){
            max=result;
        }
        printf("\n");
    }
    printf("MOCC A MAMMT %d",max);
}

int max_area_histogram(int appoggio[], int dimcolonne){
    int max_area = 0;
    int i,j,k,min_height;
    for(i=0;i<dimcolonne;i++){
        for(j=0;j<dimcolonne;j++){
            min_height=minimo(appoggio[i],appoggio[j]);
            for(k=i;k<j;k++){
                min_height=minimo(min_height,appoggio[k]);
            }
            max_area = massimo(max_area, min_height * ((j - i) + 1));
        }
    }
    printf("max area %d",max_area);
    return max_area;
}

int minimo(int a, int b){
    if(a<b){
        return a;
    }else{
        return b;
    }
}

int massimo(int a, int b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}

//0 bianco 1 nero

#include <stdio.h>
#define MAXN 50

void leggi_dim(int *dimrighe, int *dimcolonne, FILE *fpin);
void caricamatrice(int mappa[][MAXN],  int dimrighe,int dimcolonne,FILE *fpin);
void altezza(int mappa[][MAXN], int dimrighe,int dimcolonne);
void larghezza(int mappa[][MAXN], int dimrighe,int dimcolonne);
void stampasommarighe(int mappa[][MAXN],  int dimrighe,int dimcolonne);
int max_area_histogram(int appoggio[], int dimcolonne);
int minimo(int a, int b);
int massimo(int a, int b);

int main(){
    FILE *fpin;
    int dimrighe,dimcolonne;
    int mappa[MAXN][MAXN];



    fpin=fopen("../input0.txt","r");

    if(fpin!=NULL){
        leggi_dim(&dimrighe,&dimcolonne,fpin);
        caricamatrice(mappa,dimrighe,dimcolonne,fpin);
        altezza(mappa,dimrighe,dimcolonne);
        larghezza(mappa,dimrighe,dimcolonne);
        stampasommarighe(mappa,dimrighe,dimcolonne);
    }else{
        printf("errore file");
    }

    fclose(fpin);
    return 0;
}

void leggi_dim(int *dimrighe, int *dimcolonne, FILE *fpin){
    do{
        fscanf(fpin,"%d %d",dimrighe,dimcolonne);
    }while(*dimrighe>MAXN && *dimcolonne>MAXN);
}

void caricamatrice(int mappa[][MAXN], int dimrighe,int dimcolonne,FILE *fpin){
    int i,j;
    for(i=0;i<dimrighe;i++){
        for(j=0;j<dimcolonne;j++){
            fscanf(fpin,"%d",&mappa[i][j]);
            printf("%d ",mappa[i][j]);
        }
        printf("\n");
    }
}

void altezza(int mappa[][MAXN], int dimrighe,int dimcolonne){
    int ricordariga,ricordacolonna,i,j;
    int hmax=0;
    int h_precedente=0;
    int count,area;
    int h;

    for(j=0;j<dimcolonne;j++){
        h=0;
        count=0;
        for(i=0;i<dimrighe;i++){
            if(mappa[i][j]==1){
                h++;
                if(h>hmax){
                    hmax=h;
                    count++;
                    ricordariga=i;
                    ricordacolonna=j;
                }else{
                    count=0;
                }
            }else{
                h=0;
            }
        }
        if(hmax==h_precedente && hmax!=0){
            count++;
        }else{
            count=1;
        }
        h_precedente=hmax;
    }
    area=hmax*count;
    printf("Max Altezza: estremo(%d,%d), altezza=%d, larghezza=%d, area=%d\n",ricordariga-hmax+1,ricordacolonna-count+1,hmax,count,area);
}

void larghezza(int mappa[][MAXN], int dimrighe,int dimcolonne){
    int ricordariga,ricordacolonna,i,j;
    int lmax=0;
    int l_precedente=0;
    int count,area;
    int l;

    for(i=0;i<dimrighe;i++){
        l=0;
        count=0;
        for(j=0;j<dimcolonne;j++){
            if(mappa[i][j]==1){
                l++;
                if(l>lmax){
                    lmax=l;
                    count++;
                    ricordariga=i;
                    ricordacolonna=j;
                }else{
                    count=0;
                }
            }else{
                l=0;
            }
        }
        if(lmax==l_precedente && lmax!=0){
            count++;
        }else{
            count=1;
        }
        l_precedente=lmax;
    }
    area=lmax*count;
    printf("Max Larghezza: estremo(%d,%d), altezza=%d, larghezza=%d, area=%d\n",ricordacolonna-lmax+1,ricordariga-count+1,count,lmax,area);
}

void stampasommarighe(int mappa[][MAXN],  int dimrighe,int dimcolonne){
    int i,j;
    int appoggio[dimcolonne];
    int max=0;
    int result;
    for (i=0;i<dimrighe;i++){
        for(j=0;j<dimcolonne;j++){
            if(mappa[i][j]==0){
                appoggio[j]=0;
            }else{
                if(i!=0) {
                    appoggio[j] = appoggio[j] + mappa[i][j];
                }else{
                    appoggio[j] = mappa[i][j];
                }
            }
            //printf("%d ",appoggio[j]);
        }
        result=max_area_histogram(appoggio,dimcolonne);
        if(result>max){
            max=result;
        }
        //printf("\n");
    }
    printf("Max Area: estremo(x,x), altezza=h, larghezza=l, area=%d",max);
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

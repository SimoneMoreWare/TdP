#include <stdio.h>
#define MAXN 20
void leggidimensioni(int *nr,int *nc, FILE *fpin);
void leggimatrice(int m[][MAXN],int nr,int nc, FILE *fpin);
int minimo_nr_nc(int nr,int nc);
void stampasottomatrice(int m[][MAXN],int nr,int nc,int dim);
void stampasottomatricemassima(int m[][MAXN],int ricordariga,int ricordacolonna, int massimo,int dim);
int main(){
    FILE *fpin;
    int nr,nc;
    int dim=1;
    int minimo;
    int m[MAXN][MAXN];
    char fname[MAXN];

    //input nome file from user.
    printf("Enter .txt file name\n");
    scanf("%123s",fname);
    fpin=fopen(fname,"r");

    if(fpin!=NULL){
        leggidimensioni(&nr,&nc,fpin);
        leggimatrice(m,nr,nc,fpin);
        minimo=minimo_nr_nc(nr,nc);
        while(dim>=1 && dim<=minimo){
            printf("inserisci dimensione");
            scanf("%d",&dim);
            if(dim>=1 && dim<=minimo){
                stampasottomatrice(m,nr,nc,dim);
            }
        }
    }else{
        printf("errore nel file");
    }

    fclose(fpin);
}

void leggidimensioni(int *nr,int *nc,FILE *fpin){
    fscanf(fpin,"%d",nr);
    fscanf(fpin,"%d",nc);
}

void leggimatrice(int m[][MAXN],int nr, int nc,FILE *fpin){
    int i,j;
    for(i=0;i<nr;i++){
        for(j=0;j<nc;j++){
            fscanf(fpin,"%d",&m[i][j]);
        }
    }
}

int minimo_nr_nc(int nr,int nc){
    int minimo;
    if(nr>nc){
        minimo=nc;
    }else{
        minimo=nr;
    }
    return minimo;
}

void stampasottomatrice(int m[][MAXN],int nr,int nc,int dim){
    int i,j,k,u;
    int flagfirstinteraction=0;
    int massimo,somma,ricordariga,ricordacolonna;
    printf("Le sottomatrici quadrate di dimensione %d sono:\n",dim);
    for(i=0;i<=nr-dim;i++){
        for(j=0;j<=nc-dim;j++){
            somma=0;
            for(k=i;k<i+dim;k++){
                for(u=j;u<j+dim;u++){
                    printf("%d",m[k][u]);
                    somma=somma+m[k][u];
                }
                flagfirstinteraction++;
                if(flagfirstinteraction==1){
                    massimo=somma;
                }
                printf("\n");
            }
            if(somma>=massimo){
                ricordariga=i;
                ricordacolonna=j;
                massimo=somma;
            }
            printf("\n");
        }
        printf("\n");
    }

    stampasottomatricemassima(m,ricordariga,ricordacolonna,massimo,dim);
}

void stampasottomatricemassima(int m[][MAXN],int ricordariga,int ricordacolonna, int massimo,int dim){
    int i,j;
    printf("La sottomatrice con somma degli elementi massima (%d) e’:\n",massimo);
    for(i=ricordariga;i<ricordariga+dim;i++){
        for(j=ricordacolonna;j<ricordacolonna+dim;j++){
            printf("%d",m[i][j]);
        }
        printf("\n");
    }
}

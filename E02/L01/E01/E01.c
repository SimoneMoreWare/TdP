//v vettore di n interi
#include <stdio.h>
#define MAXN 30

void caricavettore(int v[],int *lenvettore,int *massimo, FILE *fpin);
void sottosequenze(int v[],int lenvettore,int massimo);

int main(){
    FILE *fpin;
    int v[MAXN];
    int lenvettore=0;
    int massimo=0;

    fpin=fopen("../input0.txt","r");

    if(fpin!=NULL){
        caricavettore(v,&lenvettore,&massimo,fpin);
    }
    sottosequenze(v,lenvettore,massimo);

    fclose(fpin);
    return 0;
}

void caricavettore(int v[],int *lenvettore,int *massimo,FILE *fpin){
    int lunghezzasottovettore=0;
    int i=0;

    *massimo=0;
    *lenvettore=0;


    while(!feof(fpin)) {
        fscanf(fpin,"%d",&v[i]);
        if(v[i]==0){
            if(lunghezzasottovettore>=*massimo){
                *massimo=lunghezzasottovettore;
            }
            lunghezzasottovettore=0;
        }else{
            lunghezzasottovettore++;
        }
        i++;
        *lenvettore=*lenvettore+1;
    }

}
void sottosequenze(int v[],int lenvettore,int massimo){
    int lunghezzasottovettore=0;
    int i,j,start;
    for(i=0;i<lenvettore;i++){
        if(v[i]==0){
            if(lunghezzasottovettore==massimo) {
                start = i - massimo;
                printf("[");
                for (j = start; j < i; j++) {
                    printf("%d", v[j]);
                }
                printf("] ");
            }
            lunghezzasottovettore=0;
        }else{
            lunghezzasottovettore++;
        }
    }
}

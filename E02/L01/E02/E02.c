//v vettore di n interi
#include <stdio.h>
#define MAXN 30

void caricavettore(int v[],int dim);
void leggi_dim(int *dim);
void ruotadestra(int v[MAXN], int dim, int P);
void ruotasinistra(int v[MAXN], int dim, int P);
void visualizzavettore(int v[MAXN],int dim);

int main(){
    int v[MAXN];
    int dim,dir;
    int P=-1;


    leggi_dim(&dim);
    caricavettore(v,dim);
    while(P!=0){
        printf("inserisci posizioni P");
        scanf("%d",&P);
        if(P<dim && P!=0){
            printf("dx o sx?");
            scanf("%d",&dir);
            if(dir==-1) {
                ruotadestra(v,  dim,  P);
                visualizzavettore(v,dim);
            }else if(dir==1) {
                ruotasinistra(v,dim,P);
                visualizzavettore(v,dim);
            }

        }
    }

    return 0;
}

void leggi_dim(int *dim){
    do{
        printf("inserisci dimensione vettore");
        scanf("%d",dim);
    }while(*dim<=0 || *dim>MAXN);
}

void caricavettore(int v[],int dim){
    int i;
    for(i=0;i<dim;i++){
        printf("inserisci valore vettore \n");
        scanf("%d",&v[i]);
    }
}

void ruotadestra(int v[MAXN], int dim, int P){
    int tmp;
    int i,j;
    for(j=0;j<(P%dim);j++) {
        tmp = v[dim-1];
        for (i = dim-1; i >0; i--) {
            v[i]=v[i-1];
        }
        v[0]=tmp;
    }
}

void ruotasinistra(int v[MAXN],int dim, int P){
    int tmp;
    int i;
    for(i=0;i<(P%dim);i++) {
        tmp = v[0];
        for (i = 0; i < dim - 1; i++)
            v[i] = v[i + 1];
        v[dim - 1] = tmp;
    }
}

void visualizzavettore(int v[MAXN],int dim){
    int i;
    for(i=0;i<dim;i++){
        printf("%d",v[i]);
    }
}

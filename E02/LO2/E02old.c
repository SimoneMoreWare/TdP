#include <stdio.h>
#include <string.h>
#define S 30
#define MAXN 200

struct dizionario{
    char originale[MAXN];
    char ricodifica[MAXN];
};

void leggi_dim(int *dim, FILE *fpdiz);
void caricavettore(struct dizionario diz[], int dim, FILE *fpdiz);
void verifica(struct dizionario diz[],char c[], int dim);

int main(){
    FILE *fpintest,*fpdiz;
    int dim;
    char c[MAXN];
    struct dizionario diz[S];

    fpintest=fopen("../sorgente.txt","r");
    fpdiz=fopen("../dizionario.txt","r");

    leggi_dim(&dim,fpdiz);
    caricavettore(diz,dim,fpdiz);

    if(fpintest!=NULL){
        while(!feof(fpintest)) {
            fscanf(fpintest,"%s",c);
            verifica(diz,c,dim);
        }
    }
}

void leggi_dim(int *dim, FILE *fpdiz){
    do{
        fscanf(fpdiz,"%d",dim);
    }while(*dim<=0 || *dim>S);
}

void caricavettore(struct dizionario diz[], int dim, FILE *fpdiz){
    int i;
    for(i=0;i<dim;i++){
        fscanf(fpdiz,"%s %s",diz[i].ricodifica,diz[i].originale);
    }
}

void verifica(struct dizionario diz[],char c[], int dim){
    int i;
    int flag_trovato=0;
    int ricordaindice;
    for(i=0;i<dim && flag_trovato==0;i++){
        if (strstr(c, diz[i].originale) != NULL) {
            flag_trovato=1;
            ricordaindice=i;
        }
    }
    if(flag_trovato==1){
        printf("%s ",diz[ricordaindice].ricodifica);
    }else{
        printf("%s ",c);
    }
}

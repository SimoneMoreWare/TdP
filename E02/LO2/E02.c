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
char *strreplace(char *c, const char *s1, const char *s2);

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
    for(i=0;i<dim && flag_trovato==0;i++){
        if (strstr(c, diz[i].originale) != NULL) {
            flag_trovato=1;
            c=strreplace(c, diz[i].originale, diz[i].ricodifica);
        }
    }

    printf("%s ",c);

}

char *strreplace(char *c, const char *s1, const char *s2) {
    char *p = strstr(c, s1); //nella variabile p è presenta il carattere c ma dal punto in cui inizia a presentarsi la sottostringa (ciao ia -> iao)
    if (p != NULL) {
        size_t len1 = strlen(s1);//dimensione sottostringa
        size_t len2 = strlen(s2);//dimensione di quello che voglio sostituire
        memmove(p + len2, p + len1, strlen(p + len1) + 1);
        //alla vecchia stringa p dobbiamo aggiunge len2 spazi (Oggetto di destinazione).
        //Oggetto di origine e dobbiamo considerare dalla prima posizione len1 posizioni
        //dobbiamo copiare xcaratteri a partire dalla dimensione da quella stringa p "depurata" e la lunghezza della sottostringa e aggiungerci 1 
        //in questo modo possiamo stamapare per esempio venn$81%o con la o alla fine , in quanto abbiamo elaborato i primi 7 e non tutti e 8
        memcpy(p, s2, len2);
        //sostituisco una eventuale (o totalità) del pezzo p con stringa s2 ($...$) per la len2 (dimension di $..$) volte
    }
    return c;
}

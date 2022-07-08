#include <stdio.h>
#include <string.h>
#define MAXL 100
#define MAXS 50
struct squadre{
    char nome_team[MAXL];
    int punti;
};
void leggidim(int *dim,FILE *fp);
void caricasquadre(struct squadre sqd[],int dimsquadre,FILE *fpteam);
void caricascore(struct squadre sqd[],int dimscore,int dimsquadre,FILE *fpscore);
void assegnapunti(char team1[],char team2[],int score1,int score2, int dimsquadre,struct squadre sqd[]);
void cercateam(char team[],int dimsquadre,struct squadre sqd[], int punti);
void visualizzateam(struct squadre sqd[],int dimsquadre);
void initscore(struct squadre sqd[], int dimsquadre);
int main(){
    FILE *fpteam,*fpscore;
    struct squadre sqd[MAXS];
    int dimsquadre,dimscore;
    fpteam=fopen("../input0.txt","r");
    fpscore=fopen("../sorgente.txt","r");
    if(fpteam!=NULL && fpscore!=NULL){
        leggidim(&dimsquadre,fpteam);
        caricasquadre(sqd,dimsquadre,fpteam);
        initscore(sqd,dimsquadre);
        leggidim(&dimscore,fpscore);
        caricascore(sqd,dimscore,dimsquadre,fpscore);
        visualizzateam(sqd,dimsquadre);
    }else{
        printf("errore file");
    }
    fclose(fpteam);
    fclose(fpscore);
    return 0;
}
void leggidim(int *dim,FILE *fp){
    do{
        fscanf(fp,"%d",dim);
    }while(*dim<=0 || *dim>MAXS);
}

void caricasquadre(struct squadre sqd[],int dimsquadre,FILE *fpteam){
    int i;
    for(i=0;i<dimsquadre;i++){
        fscanf(fpteam,"%s",sqd[i].nome_team);
    }
}

void caricascore(struct squadre sqd[],int dimscore,int dimsquadre,FILE *fpscore){
    int i,score1,score2;
    char team1[MAXL];
    char team2[MAXL];
    for(i=0;i<dimscore;i++){
        fscanf(fpscore,"%s %d %s %d",team1,&score1,team2,&score2);
        assegnapunti(team1,team2,score1,score2,dimsquadre,sqd);
    }
}

void assegnapunti(char team1[],char team2[],int score1,int score2,int dimsquadre,struct squadre sqd[]){
    int punti;
    if(score1>score2){
        punti=3;
        cercateam(team1,dimsquadre,sqd,punti);
    }else if(score1==score2){
        punti=1;
        cercateam(team1,dimsquadre,sqd,punti);
        cercateam(team2,dimsquadre,sqd,punti);
    }else{
        punti=3;
        cercateam(team2,dimsquadre,sqd,punti);
    }
}

void cercateam(char team[],int dimsquadre,struct squadre sqd[],int punti){
    int i;
    int flag=0;
    for(i=0;i<dimsquadre && flag==0;i++){
        if(strcmp(team,sqd[i].nome_team)==0){
            sqd[i].punti=sqd[i].punti+punti;
            flag=1;
        }
    }
}

void visualizzateam(struct squadre sqd[],int dimsquadre){
    int i;
    for(i=0;i<dimsquadre;i++){
        printf("%s %d\n",sqd[i].nome_team,sqd[i].punti);
    }
}

void initscore(struct squadre sqd[],int dimsquadre){
    int i;
    for(i=0;i<dimsquadre;i++){
        sqd[i].punti=0;
    }
}

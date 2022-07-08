#include <stdio.h>
#define maxrighe 100
#define maxlen 20
#define maxid 10

struct studente{
    char cognome[maxlen];
    char nome[maxlen];
    char idmatricola[maxid];
    int votoscritto;
    int votoorale;
};

int main(){
    struct studente st[maxrighe];
    FILE *fpstudenti,*fpvoti;
    int i,media;
    int lode,nullo;
    fpstudenti=fopen("../input0.txt","r");
    fpvoti=fopen("../ricodificato.txt","r");
    if(fpstudenti!=NULL && fpvoti!=NULL){
        i=0;
        while(!feof(fpstudenti) && !feof(fpvoti)){
            fscanf(fpstudenti,"%s %s %s",st[i].cognome,st[i].nome,st[i].idmatricola);
            fscanf(fpvoti,"%*s %d %d",&st[i].votoscritto,&st[i].votoorale);
            lode=(st[i].votoscritto==30 && st[i].votoorale==30);
            nullo=(st[i].votoscritto==0 && st[i].votoorale==0);
            media=(st[i].votoscritto+st[i].votoorale)/2;
            if(media>=18){
                if(lode==1){
                    printf("%s %s %s 30L\n",st[i].idmatricola,st[i].cognome,st[i].nome);
                }
            }else{
                if(nullo==1){
                    printf("%s %s %s S.V\n",st[i].idmatricola,st[i].cognome,st[i].nome);
                }else{
                    printf("%s %s %s insuf\n",st[i].idmatricola,st[i].cognome,st[i].nome);

                }
            }
            i++;
        }
    }else{
        printf("errore file");
    }
    fclose(fpstudenti);
    fclose(fpvoti);
    return 0;
}


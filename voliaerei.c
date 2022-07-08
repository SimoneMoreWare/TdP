

#include <stdio.h>
#include <string.h>
#define MAXN 20
#define maxvol 4

struct volo{
    char partenza[maxvol];
    char arrivo[maxvol];
};


int main(){
    FILE *fpin;
    struct volo v[MAXN];
    char arrivocheck[maxvol],partenzacheck[maxvol];
    int i,j,dim,flag;
    int count=0;
    fpin=fopen("../input0.txt","r");

    if(fpin!=NULL){
        i=0;
        //carica struct
        while(!feof(fpin)) {
                fscanf(fpin,"%s %s",v[i].partenza,v[i].arrivo);
                i++;
            }
        dim=i;
        for(i=0;i<=dim;i++){
            strcpy(partenzacheck,v[i].partenza);
            strcpy(arrivocheck,v[i].arrivo);
            flag=0;
            for(j=0;j<=dim && flag==0 && i!=j;j++){
                if(strcmp(arrivocheck,v[j].partenza)==0 && strcmp(partenzacheck,v[j].arrivo)==0){
                    printf("%s %s\n",arrivocheck,partenzacheck);
                    flag=1;
                    count++;
                }
            }
        }
    }else{
        printf("errore file");
    }
    printf("%d",count);
    fclose(fpin);
    return 0;
}


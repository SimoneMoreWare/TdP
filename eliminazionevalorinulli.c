#include <stdio.h>
#define MAXN 16
void visualizzavettoreinverso(int numarray[],int dim);
int main(){
    FILE *fpin;
    int num,i;
    int numarray[MAXN];
    fpin=fopen("../input0.txt","r");
    if(fpin!=NULL){
        i=0;
        while(!feof(fpin)) {
            fscanf(fpin,"%d",&num);
            if(num!=0){
                numarray[i]=num;
                i++;
            }
        }
        visualizzavettoreinverso(numarray,i);
    }
    fclose(fpin);
    return 0;
}

void visualizzavettoreinverso(int numarray[], int dim){
    int i;
    for(i=dim-1;i>=0;i--){
        printf("%d ",numarray[i]);
    }
}

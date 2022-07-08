#include <stdio.h>
#define MAXN 100

void inserctionsort(int *a,int n);
void selectionsort(int *a,int n);
void shellsort(int *a,int n);

int main(){
    FILE *fpin;
    int casetest,n,i,j;
    int a[MAXN];
    fpin=fopen("../input0.txt","r");
    if(fpin!=NULL){
        fscanf(fpin,"%d",&casetest);
        for(i=0;i<casetest;i++){
            fscanf(fpin,"%d",&n);
            for(j=0;j<n;j++){
                fscanf(fpin,"%d",&a[j]);
            }
            inserctionsort(a,n);
            selectionsort(a,n);
            shellsort(a,n);
        }
    }else{
        printf("errore file");
    }
    fclose(fpin);
    return 0;
}
void inserctionsort(int *a,int n){
    int l=0;
    int r=n-1;
    int i,j,tmp;
    for(i=l+1;i<=r;i++){
        tmp=a[i];
        j=i-1;
        while(j>=l && tmp<a[j]){
            a[j+1]=a[j]; //asseggno alla casella successiva il valore presente in quella
            //precedente, in parole pavore sposto il valore (se maggiore di quello corrente) a dx
            j--;
        }
        a[j+1]=tmp;
    }

    printf("\n");
}

void selectionsort(int *a,int n){
    int l=0;
    int r=n-1;
    int i,j,indiceminimo,tmp;
    for(i=l;i<r;i++){
        indiceminimo=i;
        for(j=i;j<r;j++){
            if(a[j]<a[indiceminimo]){
                indiceminimo=j;
            }
            if(indiceminimo!=i){
                tmp=a[indiceminimo];
                a[indiceminimo]=a[i];
                a[i]=tmp;
            }
        }
    }
}

void shellsort(int *a,int n){
    //scegliere il gap, e tenere conto nell
    int l=0;
    int r=n-1;
    int i,j,tmp;
    int gap=1;
    //knut
    while(gap<n/3){
        gap=3*gap+1;
    }
    for(i=l+gap;i<=r;i++){
        tmp=a[i];
        j=i;
        while(j>=l+gap && tmp<a[j-gap]){
            a[j]=a[j-gap]; //asseggno alla casella successiva il valore presente in quella
            //precedente, in parole pavore sposto il valore (se maggiore di quello corrente) a dx
            j=j-gap;
        }
        a[j]=tmp;
        gap=gap/3;
    }

    printf("\n");
}

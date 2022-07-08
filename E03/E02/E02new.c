#include <stdio.h>
#define MAXN 100000

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
    int numerodiscambi=0,numeroiterazionicicloesterno=0,iterazioniciclointerno,numerototaleiterazioni;
    for(i=l+1;i<=r;i++){
        tmp=a[i];
        j=i-1;
        while(j>=l && tmp<a[j]){
            a[j+1]=a[j]; //asseggno alla casella successiva il valore presente in quella
            //precedente, in parole pavore sposto il valore (se maggiore di quello corrente) a dx
            numerodiscambi++;
            j--;
        }
        numeroiterazionicicloesterno++;
        a[j+1]=tmp;
    }
    iterazioniciclointerno=numerodiscambi;
    numerototaleiterazioni=numerodiscambi+numeroiterazionicicloesterno;
    printf("inseriction sort\nn. iterazioni esterne %d\nn.iterazioni ciclo interno %d\nn. totale di scambi %d\nn. tot iterazioni %d",numeroiterazionicicloesterno,iterazioniciclointerno,numerodiscambi,numerototaleiterazioni);
    printf("\n");
}

void selectionsort(int *a,int n){
    int l=0;
    int r=n-1;
    int i,j,indiceminimo,tmp;
    int numerodiscambi=0;
    int numeroiterazionicicloesterno=0;
    int iterazioniciclointerno=0;
    int numerototaleiterazioni;

    for(i=l;i<r;i++){
        indiceminimo=i;
        numeroiterazionicicloesterno++;
        for(j=i+1;j<=r;j++){
            iterazioniciclointerno++;
            if(a[j]<a[indiceminimo]){
                indiceminimo=j;
            }
        }
        if(indiceminimo!=i){
            numerodiscambi++;
            tmp=a[indiceminimo];
            a[indiceminimo]=a[i];
            a[i]=tmp;
        }
    }

    numerototaleiterazioni=numerodiscambi+iterazioniciclointerno+numeroiterazionicicloesterno;
    printf("selection sort\nn. iterazioni esterne %d\nn.iterazioni ciclo interno %d\nn. totale di scambi %d\nn. tot iterazioni %d",numeroiterazionicicloesterno,iterazioniciclointerno,numerodiscambi,numerototaleiterazioni);
    printf("\n");
}

void shellsort(int *a,int n){
    //scegliere il gap, e tenere conto nell
    int l=0;
    int r=n-1;
    int i,j,tmp;
    int numerodiscambi=0,numeroiterazionicicloesterno=0,iterazioniciclointerno,numerototaleiterazioni;

    int gap=1;
    //knut
    while(gap<n/3){
        gap=3*gap+1;
    }
    while(gap>=1) {
        for (i = l + gap; i <= r; i++) {
            j = i;
            tmp = a[i];
            while (j >= l + gap && tmp < a[j - gap]) {
                a[j] = a[j - gap]; //asseggno alla casella successiva il valore presente in quella
                //precedente, in parole pavore sposto il valore (se maggiore di quello corrente) a dx
                j = j - gap;
                numerodiscambi++;
            }
            a[j] = tmp;
            numeroiterazionicicloesterno++;
        }
        gap = gap / 3;
    }
    numerototaleiterazioni=numerodiscambi+numeroiterazionicicloesterno;
    iterazioniciclointerno=numerodiscambi;
    printf("shell sort\nn. iterazioni esterne %d\nn.iterazioni ciclo interno %d\nn. totale di scambi %d\nn. tot iterazioni %d",numeroiterazionicicloesterno,iterazioniciclointerno,numerodiscambi,numerototaleiterazioni);
    printf("\n");
}


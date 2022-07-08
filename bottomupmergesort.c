#include <stdio.h>
#define MAXN 100
void Merge(int A[], int B[], int l, int q, int r);
void BottomUpMergeSort(int A[], int B[], int N);
int main(){
    FILE *fpin;
    int a[MAXN];
    int b[MAXN];//vettore b stessa dimensione di quello A; vettore di appoggio per la fusione dei vettori
    int dim;
    fpin=fopen("../input0.txt","r");
    if(fpin!=NULL){
        fscanf(fpin,"%d",&dim);
        for(int i=0;i<dim;i++){
            fscanf(fpin,"%d",&a[i]);
        }
        BottomUpMergeSort(a,b,dim);
        for(int i=0;i<dim;i++){
            printf("%d ",b[i]);
        }
    }

    fclose(fpin);
    return 0;
}

void Merge(int A[], int B[], int l, int q, int r) {
    int i, j, k;
    i = l; //=0
    j = q+1;
    //scorro i sottovettori sinistro e destro mediante indici i e j
    //scorro vettore b mediante k

    //confronto elemento corrente a[i] del sottovettore sinistro
    //con quello del sottovettore destro a[j]
    //  se a[i]<=[j] ricopiare a[i] in B e avanzare i (j resta invariato)
    //  altrimenti ricopiare a[j] in b e avanzare j, i resta invariato
    //se è esaurito il sottovettore sinistro ricopiare gli elementi rimanenti del sottovettore destro in b
    //se è esaurito sottovettore destro ricopiare gli elementi rimanenti del sottovettore sinistro in b
    for (k = l; k <= r; k++)
        if (i > q) //esaurito sottovettore sinistro
            B[k] = A[j++];
        else if (j > r) //esaurito sottovettore destro
            B[k] = A[i++];
        else if ((A[i]< A[j]) || (A[i]==A[j])) //se a[i]<=[j] ricopiare a[i] in B e avanzare i (j resta invariato)
            B[k] = A[i++];
        else //altrimenti ricopiare a[j] in b e avanzare j, i resta invariato
            B[k] = A[j++];
    for ( k = l; k <= r; k++ )//riscrivo a
        A[k] = B[k];
}

void BottomUpMergeSort(int A[], int B[], int N){
    int i,q,lensottovettori,l=0,r=N-1;

    //ciclo esterno
    //lensottovettori inizialmente vale 1
    //radoppia ad ogni passo (lensottovettori è la lunghezza dei sottovettori)
    //lensottovettori vale al MAX N
    //divido array in blocchi grandi lensottovettori
    //m=[1 2 4 8 16]

    for(lensottovettori=1;lensottovettori<=r-l;lensottovettori=lensottovettori+lensottovettori){

        //ciclo interno
        //ad ogni coppia di sottovettori ordinati ed adiacenti
        //di dimensione lensottovettori
        //si applica merge
        //risultato: sottovettore ORDINATO di lunghezza 2*lensottovettori

        //i posizione sottovettori di lunghezza lensottovetori
        //INDENTIFICA TUTTI I SOTTOVETTORI DI LUNGHEZZA LENSOTTOVETTORI
        for(i=l;i<=r-lensottovettori;i+=lensottovettori+lensottovettori){//i+=m+m identificazione dell’indice iniziale della prossima coppia di sottovettori
            //contigui e ordinati di dimensione m (aka passi dal primo al terzo vettore)
            q=i+lensottovettori-1;//divedere sottovettori di A a metà in due sottovettori sinistro e destro di indice q=i+m-1
            //sottovettore sinistro indice l < i <q quindi va da Ai ... Aq
            //sottovettore destro indici q+1<=j<=r Aq+1 ... Aq+m

            //fusione vettori di dimensione lensottovettori
            //ottenere a ogni passo vettori ordinati
            //di lunghezza m doppia

            //q è l'estremo del vettore di sx
            //r è l'estremo del vettore di dx
            Merge(A,B,i,q,r);
            //B è il vettore di appoggio di dimesione N
            //contiene il risultato della fusione

            //tutto termina quando B ha dimensione pari a quello di lunghezza (i<r-m)
        }
    }
}

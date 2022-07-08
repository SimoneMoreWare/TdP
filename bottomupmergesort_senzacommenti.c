#include <stdio.h>
#define MAXN 100

void Merge(int A[],int B[],int l,int q,int r);
void bottomup(int A[],int B[],int dim);
void visualizza(int A[],int dim);
int main() {
    FILE *fpin;
    int A[MAXN],B[MAXN];
    int dim;
    fpin=fopen("../input0.txt","r");
    if(fpin!=NULL){
        fscanf(fpin,"%d",&dim);
        for(int i=0;i<dim;i++){
            fscanf(fpin,"%d",&A[i]);
        }
        bottomup(A,B,dim);
        visualizza(A,dim);
    }else{
        printf("errore file");
    }
    fclose(fpin);
    return 0;
}

void bottomup(int A[],int B[],int dim){
    int i,m,q,l=0,r=dim-1;
    for(m=1;m<=r-l;m=m+m){
        for(i=l;i<=r-m;i=i+m+m){
            q=i+m-1;
            Merge(A,B,i,q,r);
        }
    }
}

void Merge(int A[],int B[],int l,int q,int r){
    int i,j,k;
    i=l;
    j=q+1;
    for(k=l;k<=r;k++){
        if(i>q){
            B[k]=A[j++];
        }else if(j>r){
            B[k]=A[i++];
        }else if((A[i]<A[j]) || (A[i]==A[j])){
            B[k]=A[i++];
        }else{
            B[k]=A[j++];
        }
    }
    for(k=l;k<=r;k++){
        A[k]=B[k];
    }
}

void visualizza(int A[],int dim){
    int i;
    for(i=0;i<dim;i++){
        printf("%d ",A[i]);
    }
}

#include <stdio.h>
//massimo comune divisore
int main(){
    int x,y,maggiore,minore;
    int resto = -1;
    do{
        printf("inserisci x : ");
        scanf("%d",&x);
        printf("inserisci y : ");
        scanf("%d",&y);
    }while(x<0 || y<0);

    if (x>=y){
        maggiore=x;
        minore=y;
    }else{
        maggiore=y;
        minore=x;
    }

    while(resto!=0){
        resto=maggiore%minore;
        maggiore=minore;
        if (resto!=0){
            minore=resto;
        }
    }
    printf("MCD= %d",minore);

    return 0;
}

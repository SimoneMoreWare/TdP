#define inputtext "../input0.txt"
#include <stdio.h>

int somma(int d0,int d1,int d2);
int prodotto(int d0,int d1,int d2);
int divisione(int d0,int d1,int d2);
int sottrazione(int d0, int d1,int d2);
int operation(int d0,int d1,int d2);

int main(){
FILE *fp_read,*fp_write;
int d0,d1,d2;
int checkoperation;
int countscartati =0;
int massimo,minimo;
fp_read=fopen(inputtext,"r");
fp_write=fopen("../output.txt","w");

if(fp_read!=NULL && fp_write!=NULL){
    fscanf(fp_read,"%d%d%d",&d0,&d1,&d2);
    if(d0>d1){
        massimo=d0;
        minimo=d1;
    }else{
        massimo=d1;
        minimo=d0;
    }
    while(!feof(fp_read)) {
        checkoperation=operation(d0,d1,d2);
        //printf("%d",checkoperation);
        if(checkoperation==0){
            fscanf(fp_read,"%d",&d2);
            if(d2>massimo){
                massimo=d2;
            }
            if(d2<minimo){
                minimo=d2;
            }
            countscartati++;
        }else{
            d0=d1;
            d1=d2;
            if(d2>massimo){
                massimo=d2;
            }
            if(d2<minimo){
                minimo=d2;
            }
            fscanf(fp_read,"%d",&d2);

        }


    }
}

fprintf(fp_write,"Numero massimo: %d\n",massimo);
fprintf(fp_write,"Numero minimo: %d\n",minimo);

if (countscartati==0){
    printf("tutti i dati rispettano la condizione");
}else{
    fprintf(fp_write,"Numeri scarati: %d",countscartati);
}

fclose(fp_read);
fclose(fp_write);
return 0;

}

int operation(int d0,int d1,int d2){
    if(somma(d0,d1,d2)==1){
        return 1;
    }else if (prodotto(d0,d1,d2)==1){
        return 1;
    }else if (sottrazione(d0,d1,d2)==1){
        return 1;
    }else if (divisione(d0,d1,d2)==1){
        return 1;
    }else{
        return 0;
    }
}

int somma(int d0,int d1,int d2){
    int sum;
    sum = d0+d1;
    if (sum==d2){
        return 1;
    }else{
        return 0;
    }
}

int prodotto(int d0,int d1,int d2){
    int product;
    product = d0*d1;
    if (product==d2){
        return 1;
    }else{
        return 0;
    }
}

int sottrazione(int d0,int d1, int d2){
    int sottrazione;
    sottrazione = d0-d1;
    if(sottrazione==d2){
        return 1;
    }else{
        return 0;
    }
}

int divisione(int d0,int d1,int d2){
    int divisione;
    if(d1!=0){
        divisione=d0/d1;
        if(divisione==d2){
            return 1;
        }else{
            return 0;
        }
    }else{
        return 0;
    }
}

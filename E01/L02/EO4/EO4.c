/*
 * numero caratteri non noto
 *
 * scopo
 * ricodificare testo
 * generare secondo file
 *      contente i caratteri modificati
 *
 * regole modifiche:
 * 0...9 modificati NEI CARATTERI NUMERICI posto k posizioni piu avanti
 * k parte da 0 incrementato ad ogni carattere numerico ricodificato
 * arrivati a 9 si riparte da 0
 *
 * caratteri alfabetici
 * • Se un carattere alfabetico è preceduto da un carattere non alfabetico, resta inalterato
 * se è preceduto da un carattere alfabetico c0 il suo codice si sposta di h pos. in avanti
 *  (con h = c0-‘A’, se c0 è maiuscolo, h=c0-‘a’, se c0 è minuscolo.
 *  L’incremento di h è modulo 26, cioè arrivati alla ‘z’ o ‘Z’ (a seconda che il carattere ricodificato sia maiuscolo o minuscolo) si riparte da ‘a’ o ‘A
 */

#include <stdio.h>

int isnum(char c);
int main(){
    FILE *fp_read,*fp_write;
    char c0,c1;
    int checknum,convertchartoint;
    int k=0;

    fp_read = fopen("../input0.txt","r");
    fp_write = fopen("../output.txt","w");

    if (fp_read!=NULL && fp_write!=NULL) {
        fscanf(fp_read,"%c",&c0);
        while(!feof(fp_read)) {
            checknum = isnum(c0);
            if(checknum==1){
                c0=c0+k;
                k++;
                convertchartoint=c0-'0';
                if(convertchartoint>=0 && convertchartoint<=9){
                    printf("%c",c0);
                }else{
                    c0='0';
                    k=0;
                    printf("%c",c0);
                }
            }else{
                printf("%c",c0);
            }

            fscanf(fp_read, "%c", &c0);
        }
    }else{
        printf("errore nei file");
    }
    fclose(fp_read);
    fclose(fp_write);

    return 0;
}

int isnum(char c){
    char ifnumber;
    int conversioncharinint;
    ifnumber = c-'0';
    conversioncharinint = ifnumber;
    if (conversioncharinint>=0 && conversioncharinint<=9){
        return 1;
    }else{
        return 0;
    }
}


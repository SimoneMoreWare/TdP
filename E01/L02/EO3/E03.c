/*
 * un file di testo contiene un numero indefinito
 * di righe
 *
 * Scopo:
 * ricodificare testo:
 *      sostituire sequenze di caratteri ripetuti
 *      da 2 a 9 volte. AA 2 ripetizioni
 *      con la terna
 *      <carattere_ripetuto>$<num_di_ripetizione>
 *      per numero di ripetizioni è sufficiente
 *      un carattere
 *      se un carattere fosse ripetuto piu di 9
 *      volte le ripetizione sarebbero spezzate
 *      in piu intervalli
 *
 *      si scrivano due funzioni in grado di
 *      effettuare
 *      compressione e decompressione
 *      prototipi
 *      int comprimi(FILE *fin, FILE *fout);
        int decomprimi(FILE *fin, FILE *fout);
        in caso di errore le funzioni ritorano 0
        diversamente ritornano il numero di
        caratteri
        scritto nel file di uscita.
        nel main utente può scegliere se
        codificare o decodificare
        apre i file input e output
        chiama la funziona selezionata
        terzon file per la decompressione
 */
#include <stdio.h>

void comprimi(FILE *fp_input, FILE *fp_write);
void decomprimi(FILE *fp_input, FILE *fp_write);

int main(){
    FILE *fp_input,*fp_write;
    char scelta;

    fp_input = fopen("../input0.txt","r");
    fp_write = fopen("../decompresso.txt","w");

    printf("Decodificare (D) o Codificare (C) ");
    scanf("%c",&scelta);

    if(scelta=='C'){
        comprimi(fp_input,fp_write);
    }else if(scelta=='D'){
        decomprimi(fp_input,fp_write);
    }else{
        return 1;
    }

    fclose(fp_input);
    fclose(fp_write);
    return 0;
}

void comprimi(FILE *fp_input, FILE *fp_write){
    char c1,c2,c3;
    int count =1;
    int endword;

    fscanf(fp_input,"%c%c",&c1,&c2);
    if(c1!=c2){
        fprintf(fp_write,"%c",c1);
    }

    while(!feof(fp_input) || c3==EOF) {
        fscanf(fp_input,"%c",&c3);
        if (c2 == c1) {

            endword = (c2!=c3 || c3==EOF);

            if(count==1 && c2!=c3){
                fprintf(fp_write,"%c%c",c2,c2);
            }
            if (count >= 2 && count <= 9 && endword) {
                    fprintf(fp_write,"%c$%d", c2, count);
            } else if (count > 9) {
                fprintf(fp_write,"%c$%d", c2, count-1);
                count = 1;
            }
            count = count + 1;

        }else{
            if (c2!=c3 || c3==EOF){
                fprintf(fp_write,"%c",c2);
            }

            count=1;

        }
        c1 = c2;
        c2 = c3;
    }
}

void decomprimi(FILE *fp_input, FILE *fp_write){
    char c1,c2,c3;
    int count;
    int i;
    fscanf(fp_input,"%c%c",&c1,&c2);
    fprintf(fp_write,"%c",c1);
    while(!feof(fp_input)) {
        fscanf(fp_input,"%c",&c3);
        if(c2=='$'){
            count=c3-'0';
            for(i=0;i<count;i++){
                fprintf(fp_write,"%c",c1);
            }
        }else if(c1!='$'){
            fprintf(fp_write,"%c",c2);
        }
        c1 = c2;
        c2 = c3;
    }
}

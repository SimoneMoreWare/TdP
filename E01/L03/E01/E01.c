/*
 input
Caratterizzata da un passato turbolento, in
epoca medievale Rouen fu devastata piu' volte
da incendi ed epidemie e durante la Guerra
dei Cent'Anni fu occupata dagli inglesi.
nel 1431 nella sua piazza centrale la giovane
Giovanna d'Arco (Jeanne d'Arc) fu processata
per eresia e arsa sul rogo!durante la seconda
guerra mondiale gli Alleati bombardarono
ampie zone della citta', soprattutto il
quartiere che si estende a sud della cattedrale.

output generato dal MIO codice
Caratterizzata da un pass| c:25
ato turbolento, in       | c:19
epoca medievale Rouen fu | c:25
devastata piu' volte     | c:21
da incendi ed epidemie e | c:25
durante la Guerra        | c:18
dei Cent' Anni fu occupat| c:24
a dagli inglesi.         | c:17
Nel 1431 nella sua piazza| c:25
 centrale la giovane     | c:21
Giovanna d' Arco ( Jeanne| c:23
 d' Arc) fu processata   | c:22
per eresia e arsa sul rog| c:25
o! Durante la seconda    | c:21
guerra mondiale gli Allea| c:25
ti bombardarono          | c:16
ampie zone della citta' ,| c:24
 soprattutto il          | c:16
quartiere che si estende | c:25
a sud della cattedrale.  | c:24
 */

#include <stdio.h>
#include <ctype.h>
#define filein "../input0.txt"
int isnum(char c);
int isfineperiodo(char c0);

int main(){
    FILE *fp_read,*fp_write;
    int countword =1; //variabile per contare 25 caratteri in riga
    int countoriginalword=0; //variabile per contare caratteri originale presenti nel file di input
    char c0,c1; //c0 carattere attuale e c1 carattere successivo
    int checknum,chekcpunteggiatura,checkfineperiodo,flagfineperido,iterspace;
    fp_read = fopen(filein,"r");
    fp_write = fopen("../output.txt","w");
    if (fp_read!=NULL) {
        fscanf(fp_read,"%c",&c0);
        fscanf(fp_read,"%c",&c1);
        while(!feof(fp_read)) {
            if(countword<=25){ //se i caratteri contanti sono meno di 25
                checkfineperiodo = isfineperiodo(c0);
                if(checkfineperiodo==1){
                    flagfineperido=1;//ho bisogno di un flag in modo tale che utilizzo questa variabile che sarà vera finche non becca una lettera
                }
                if(flagfineperido==1 && isalpha(c0)!=0){//se hai incontrato prima un punto e il carattere attuale è una loettera...
                    c0=toupper(c0); //allora la fai diventare maiuscolo se non lo è
                    flagfineperido=0;//false in quanto oramai hai effettuato la operazione
                }
                fprintf(fp_write,"%c",c0);

                chekcpunteggiatura = ispunct(c0);//controllo se il carattere attuale è un segno di punteggiatura
                if(chekcpunteggiatura!=0){//se vero
                    countoriginalword++; //devo incrementare la variabile countoriginalword in quanto lo bisogna contare dal file originale
                    if(c1!=' ' && c1!='\n'){//se è il carattere successivo è uno a capo o un spazio allora
                        fprintf(fp_write," ");//mi scrive uno spazio dopo la variabile attuale
                        countword++; //incrementa il numero di carattere presenti nella riga presente nel file output
                    }
                }
                checknum = isnum(c0);//vedo se carattere attuale è un numero
                if(checknum==1){//se si
                    c0='*';//sarà convertito in *
                    countoriginalword++;//incremento variabile countoriginalword in quanto era presente tale carattere nel file originale
                }
                if(isalpha(c0)!=0 || c0==' '){//se il caratterre attuale è un numero o uno spazio
                    countoriginalword++;//incremento variabile countoriginalword in quanto era presente nel file input
                }

                c0=c1;//finite le operazioni il caratterre successivo diventa quello attuale
                fscanf(fp_read,"%c",&c1);//assegnno alla variabile carattere successivo presente nel file che mano mano sarà processato
                countword++;//incremento la variabile legata al numero di caratteri presenti in quella determinata riga

                if(c0=='\n'){//se sono arrivato alla fine della riga devo lasciare x=25-countword spazi
                    iterspace = 25 - countword;//usero questa variabile per iterare un for che mi permetta di stampare x volte spazi
                    countoriginalword++;//il carattere \n è sempre un carattere !
                    for(int i=0;i<iterspace;i++){
                        fprintf(fp_write," ");//stampare iterspace volte spazio
                    }
                    fprintf(fp_write,"| c:%d",countoriginalword);//stampa riga
                    countword=0;
                    countoriginalword=0;

                }

                if(countword>25){//se super la soglia prefissata di max charatteri in una riga allora
                    printf("\n");
                    fprintf(fp_write,"| c:%d\n",countoriginalword);//vai a capo
                    countword=0;
                    countoriginalword=0;

                }
            }
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
int isfineperiodo(char c0){
    if(c0=='.' ||  c0=='!' || c0=='?'){
        return 1;
    }else{
        return 0;
    }
}

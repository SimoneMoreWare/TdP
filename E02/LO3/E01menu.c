#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXL 51

typedef enum comando {r_date, r_partenza, r_capolinea,
    r_ritardo, r_ritardo_tot, r_fine}comando_e;

void menuparola(void);
comando_e leggicomando(void);
void strtolower(char s[]);

int main(){
    menuparola();
    return 0;
}

void menuparola(void){
    comando_e codicecomando;
    char riga[MAXL];
    int continua=1;

    while(continua){
        codicecomando=leggicomando();
        //fflush(stdin);
        //scanf("%s",riga);//resto della riga

        switch (codicecomando){
            case r_date:
                printf("inserisci f.date\n");
                break;
            case r_partenza:
                printf("inserisci partenza\n");
                break;
            case r_capolinea:
                printf("inserisci capolinea\n");
                break;
            case r_ritardo:
                printf("inserisci ritardo\n");
                break;
            case r_ritardo_tot:
                printf("inserisci ritardo tot\n");
                break;
            case r_fine:
                printf("fine\n");

                continua=0;
                break;
            default:
                printf("comando errato");
        }
    }
}

comando_e leggicomando(void){
    comando_e c;
    char cmd[MAXL];
    char *tabella[r_fine]={
            "date","partenza","capolinea","ritardo","ritardo_tot"
    };
    printf("inserisci comando\n");
    fflush(stdin);
    scanf("%s",cmd);
    strtolower(cmd);
    c=r_date;
    while(c<r_fine && strcmp(cmd,tabella[c])!=0){
        c++;
    }
    return c;
}

void strtolower(char s[]){
    int i;
    for(i=0;s[i]!='\0';i++){
        s[i]=tolower(s[i]);
    }
}

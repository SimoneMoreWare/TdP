#include <stdio.h>

int parentesiaperte(char c0);
int parentesichiuse(char c0);
int isoperando(char c0);
int isnum(char c0);

int main(){
    FILE *fp_input,*fp_write;
    char c0,c1;
    int flagforspace_btwtwonumber;
    int countparentesiaperte=0;
    int countparentesichiuse=0;
    int countespressione=0;
    int spacebtwnumber=0;

    fp_input = fopen("../input0.txt","r");
    fp_write = fopen("../output.txt","w");

    if(fp_input!=NULL && fp_write!=NULL){
        fscanf(fp_input,"%c",&c0);
        fscanf(fp_input,"%c",&c1);
        while(!feof(fp_input)) {

                if(parentesiaperte(c0)==1){
                    countparentesiaperte++;
                    flagforspace_btwtwonumber=0;
                }else if(parentesichiuse(c0)==1){
                    countparentesichiuse++;
                    flagforspace_btwtwonumber=0;
                }

                if(isnum(c0)==1){
                    flagforspace_btwtwonumber=1;
                }

                if(isoperando(c0)==1){
                    flagforspace_btwtwonumber=0;
                }

                if(c0==' ' && flagforspace_btwtwonumber==1 && isnum(c1)==1){
                    spacebtwnumber=1;
                }
                if(c0=='\n'){
                    countespressione++;

                    if(countparentesiaperte!=countparentesichiuse){
                        printf("errore nella lettura di una parentesi (espressione %d)\n",countespressione);
                    }

                    if(spacebtwnumber==1){
                        printf("Errore nella lettura di un numero a causa di spazio tra di essi (espressione %d)\n",countespressione);
                    }
                    countparentesiaperte=0;
                    flagforspace_btwtwonumber=0;
                    countparentesichiuse=0;
                    spacebtwnumber=0;
                }
            c0=c1;
            fscanf(fp_input,"%c",&c1);

        }
    }


    fclose(fp_input);
    fclose(fp_write);
    return 0;
}

int parentesiaperte(char c0){
    if(c0=='(' || c0=='[' || c0=='{'){
        return 1;
    }else{
        return 0;
    }
}

int parentesichiuse(char c0){
    if(c0==')' || c0=='}' || c0==']'){
        return 1;
    }else{
        return 0;
    }
}

int isnum(char c0){
    char ifnumber;
    int conversioncharinint;
    ifnumber = c0-'0';
    conversioncharinint = ifnumber;
    if (conversioncharinint>=0 && conversioncharinint<=9){
        return 1;
    }else{
        return 0;
    }
}

int isoperando(char c0){
    if(c0=='+' || c0=='/' || c0=='-' || c0=='*'){
        return 1;
    }else{
        return 0;
    }
}

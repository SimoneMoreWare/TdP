#include <stdio.h>
/*
input
(3 + 2) / 7
((3 - 7) 4)
(3 - 2) +
(8 * 9 1) * 4
((4*(2+23)) / (7-3))


output
Errore 3.2 nella lettura di un operando (espressione 2)
Errore 3.3 nella lettura di un operando (espressione 3)
Errore nella lettura di un numero a causa di spazio tra di essi (espressione 4)

*/

int parentesiaperte(char c0);
int parentesichiuse(char c0);
int isoperatore(char c0);
int isnum(char c0);

int main(){
    FILE *fp_input,*fp_write;
    char c0,c1,c2;
    int flagforspace_btwtwonumber;
    int countparentesiaperte=0;
    int countparentesichiuse=0;
    int countespressione=0;
    int spacebtwnumber=0;
    int flagforopenparentesi_r31=0;
    int flag_r32=0;
    int flag_r33=0;
    int r31final=0;
    int r32final=0;
    int r33final=0;
    int r31=0;
    int r32=1;
    int r33=1;

    fp_input = fopen("../input0.txt","r");
    fp_write = fopen("../output.txt","w");

    if(fp_input!=NULL && fp_write!=NULL){
        fscanf(fp_input,"%c",&c0);
        fscanf(fp_input,"%c",&c1);
        fscanf(fp_input,"%c",&c2);
        while(!feof(fp_input)) {

            if(parentesiaperte(c0)==1){
                countparentesiaperte++;
                flagforspace_btwtwonumber=0;
                flagforopenparentesi_r31=1;
                r31=1;
                r32=1;
                r33=1;
                flag_r33=0;
                r32final=0;
                r33final=0;


            }else if(parentesichiuse(c0)==1){
                countparentesichiuse++;
                flagforspace_btwtwonumber=0;
                flagforopenparentesi_r31=0;
                flag_r32=1;
                r31final=0;
                r31=1;
                r32=1;
                r33=0;
            }

            if(isnum(c0)==1){
                flagforspace_btwtwonumber=1;
                flagforopenparentesi_r31=0;
                r31final=0;
                r32final=0;
                r31=1;
                r32=1;

                r33=1;
                flag_r32=1;
                flag_r33=0;
                r33final=0;
            }

            if(isnum(c2)==1){
                r32=0;
            }

            if(isoperatore(c0)==1){
                flagforspace_btwtwonumber=0;
                r31=0;
                r32=1;
                r32final=0;
                flag_r32=0;
                flag_r33=1;
                if(isoperatore(c1)==1 || isoperatore(c2)==1){
                    r33=0;
                }
            }
//punto 2
            if(c0==' ' && flagforspace_btwtwonumber==1 && isnum(c1)==1){
                spacebtwnumber=1;
                flagforspace_btwtwonumber=0;
            }
//punto 3.1
            if(flagforopenparentesi_r31==1 && r31==0) {
                flagforopenparentesi_r31 = 0;
                r31final = 1;
            }

            //printf("%d",flag_r32);
            //punto 3.2
            if(flag_r32==1 && r32==0){
                flag_r32=0;
                r32final=1;
            }
            // printf("rffinal %c %d %d \n",c0,r32,r32final);

            //punto 3.3
            if(flag_r33==1 && r33==0){
                flag_r33=0;
                r33final=1;
            }



            if(c0=='\n'){
                countespressione++;
//punto 1
                r32=1;
                if(countparentesiaperte!=countparentesichiuse){
                    printf("errore nella lettura di una parentesi (espressione %d)\n",countespressione);
                    r32=0;
                }
//punto 2
                if(spacebtwnumber==1){
                    printf("Errore nella lettura di un numero a causa di spazio tra di essi (espressione %d)\n",countespressione);
                }

//Punto 3.1
                if(r31final==1){
                    printf("Errore 3.1 nella lettura di un operando (espressione %d)\n",countespressione);

                }

                if(r32final==1 && r32!=0){
                    printf("Errore 3.2 nella lettura di un operando (espressione %d)\n",countespressione);

                }

                if(r33final==1){
                    printf("Errore 3.3 nella lettura di un operando (espressione %d)\n",countespressione);

                }





                countparentesiaperte=0;
                flagforspace_btwtwonumber=0;
                countparentesichiuse=0;
                flagforopenparentesi_r31=0;
                r31=1;
                r32=0;
                r31final=0;
                flag_r33=0;
                r33=1;
                r33final=0;
                r32final=0;
                spacebtwnumber=0;
            }
            c0=c1;
            c1=c2;
            fscanf(fp_input,"%c",&c2);

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

int isoperatore(char c0){
    if(c0=='+' || c0=='/' || c0=='-' || c0=='*'){
        return 1;
    }else{
        return 0;
    }
}

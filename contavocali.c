#include <stdio.h>
int checkvocale(char c);
int main(){
    char namefile[30];
    FILE *fp_read;
    int count=0;
    char name[30];
    int i;

    printf("inserisci nome file ");
    scanf("%s",namefile);

    fp_read=fopen(namefile,"r");

    if (fp_read!=NULL) {
        while(!feof(fp_read)) {
            fscanf(fp_read," %s",&name);
            i=0;
            while(name[i]!='\0'){
                if(checkvocale(name[i])==1) {
                    count++;
                }
                i++;
            }
            if (count>=2){
                printf("%s\n",name);
            }
            count=0;
        }
    }else{
        printf("errore nei file");
        }

    fclose(fp_read);
    return 0;

}

int checkvocale(char c){
    if(c=='A' || c=='a' || c=='E' || c=='e' || c=='I' || c=='i' || c=='O' || c=='o' || c=='U' || c=='u'){
        return 1;
    }else{
        return -1;
    }
}

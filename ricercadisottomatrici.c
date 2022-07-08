#include <stdio.h>
/*
 * determinare se minimatrix è contenuta - e quante volte - nella prima
 */
int main(){
    FILE *fpin;
    int matrix[5][5];
    int minimatrix[2][2];
    int i,j,k,l;
    int c=0;
    int q=0;
    fpin=fopen("../input0.txt","r");

    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            fscanf(fpin,"%d ",&matrix[i][j]);
        }
    }

    for(i=0;i<2;i++) {
        for (j = 0; j < 2; j++) {
            scanf("%d", &minimatrix[i][j]);
        }
    }

    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(matrix[i][j]==minimatrix[0][0]){
                for(k=0;k<2;k++){
                    for(l=0;l<2;l++){

                        if(matrix[i+k][j+l]==minimatrix[k][l]){
                            c++;
                            if(c==4){
                                q++;
                                c=0;
                            }
                        }
                    }
                }
            }
        }
    }
    printf("La seconda matrice e' contenuta %d volta(e) nella prima",q);
    fclose(fpin);
    return 0;
}

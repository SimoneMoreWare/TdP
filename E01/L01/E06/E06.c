#include <stdio.h>

float calculator(char operation,float op1,float op2);
int main() {
    char operation;
    float op1,op2;
    float result;

    FILE *fp_read,*fp_write;
    fp_read = fopen("../input.txt","r");
    fp_write = fopen("../output_e06.txt","w");

    if (fp_read!=NULL && fp_write!=NULL) {
        while(!feof(fp_read)) {
            fscanf(fp_read, "%c %f %f ", &operation, &op1, &op2);
            result = calculator(operation,op1,op2);
            fprintf(fp_write,"%c %.2f\n",operation,result);

        }
    }else{
        printf("errore file");
    }

    fclose(fp_read);
    fclose(fp_write);

    return 0;
}

float calculator(char operation,float op1,float op2){
    float result;

    switch(operation){
        case '+':
            result = op1 + op2;
            break;
        case '-':
            result = op1-op2;
            break;
        case '/':
            if (op2!=0){
                result=op1/op2;
            } else{
                printf("impossibile eseguire operazione");
                return -1;
            }
            break;
        case '*':
            result = op1*op2;
            break;
        default:
            printf("hai digitato male");
            return -2;
    }
    return result;
}

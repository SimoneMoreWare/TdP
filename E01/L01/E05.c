#include <stdio.h>

int main() {
    char operation;
    float op1,op2;
    float result;

    printf("inserire operazione da eseguire ");
    operation = getchar();

    printf("inserisci valore 1 ");
    scanf("%f",&op1);
    printf("inserisci valore 2 ");
    scanf("%f",&op2);

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
    printf("%.2f",result);
    return 0;
}

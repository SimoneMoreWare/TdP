#include <stdio.h>
int max_area_histogram(int arr[], int dim);
int minimo(int a, int b);
int massimo(int a, int b);
int main(){
    int result;
    int arr[] = {0, 0, 2, 2};
    result=max_area_histogram(arr,4);
    printf("%d",result);
}

int max_area_histogram(int arr[], int dim){
    int max_area = 0;
    int i,j,k,min_height;
    for(i=0;i<dim;i++){
        for(j=0;j<dim;j++){
            min_height=minimo(arr[i],arr[j]);
            for(k=i;k<j;k++){
                min_height=minimo(min_height,arr[k]);
            }
            max_area = massimo(max_area, min_height * ((j - i) + 1));
        }
    }
    return max_area;
}

int minimo(int a, int b){
    if(a<b){
        return a;
    }else{
        return b;
    }
}

int massimo(int a, int b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}

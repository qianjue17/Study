#include<stdio.h>
void swap(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
int main(){
    int a[5] = {3, 2 , 5, 4, 1};
    int i;
    for (i=0; i < 5; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}

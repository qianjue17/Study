#include<stdio.h>
#include"sort.h"
int main(){
    int a[5] = {3, 2 , 5, 4, 1};
    int i;
    sort(a, 5);
    for (i=0; i < 5; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
#include"sort.h"
#include<stdio.h>

void sort(int *a, int n){
    int i, j;
    for (i=1; i<n; i++){
        int key = a[i];
        for (j=i-1; j>=0 && a[j] >= key; j--){
            a[j+1] = a[j];
        }
        a[j+1] = key;
    }
}
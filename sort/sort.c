#include<stdio.h>
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void show(int *a, int n){
    int i;
    for (i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void bubble(int *a, int n){
    int i,j;
    for(i = 0; i < n-1; i++){
        int flag = 0;
        for(j = 0; j< n-1-i; j++){
            if(a[j] > a[j+1]){
                swap(&a[j], &a[j+1]);
                flag = 1;
            }
        }
        if(flag == 0){
            break;
        }
    }
}

void insert(int *a, int n){
    int i,j;
    for(i = 1; i < n; i++){
        int key = a[i];
        for(j = i-1; j >= 0 && a[j]<key; j--){
            a[j+1] = a[j];
        }
        a[j+1] = key;
    }
}

void quick_sort(int *a, int left, int right){
    int key = a[left];
    int i = left, j = right;
    while(i < j){
        while(i<j && a[j]>=key){
            j--;
        }
        a[i] = a[j];
        while(i<j && a[i]<key){
            i++;
        }
        a[j] = a[i];
    }
    a[i] = key;
    if(i-left > 1){
        quick_sort(a, left, i-1);
    }
    if(right-i > 1){
        quick_sort(a, i+1,  right);
    }
}

void quick(int *a, int n){
    quick_sort(a, 0, n-1);
}

void bin_insert(int *a, int n){
    int i, j;
    int left, right, key;
    for(i=1; i<n; i++){
        left = 0;
        right = i-1;
        key = a[i];
        while(left<=right){
            int mid = (left+right)/2;
            if(a[mid]>key){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        for(j = i-1; j>=left; j--){
            a[j+1] = a[j];
        }
        a[left] = key;
    }
}

void choice(int *a, int n){
    int i, j;
    int max;
    for(i=0; i<n; i++){
        max = 0;
        for(j=0; j<n-i; j++){
            if(a[j]>a[max]){
                max = j;
            }
        }
        if(max != n-1-i){
            swap(&a[max], &a[n-1-i]);
        }
    }
}

void cocktail(int *a, int n){
    int max, min;
    int i, j;
    for(i=0; i<n/2; i++){
        max = i;
        min = i;
        for(j=i; j<n-i; j++){
            if(a[max]<a[j]){
                max = j;
            }
            if(a[min]>a[j]){
                min = j;
            }
        }
        if(max != n-1-i){
            swap(&a[max], &a[n-1-i]);
            if(min == n-1-i){
                min = max;
            }
        }
        if(min != i){
            swap(&a[min], &a[i]);
        }
    }
}

void shell(int *a, int n){
    int key, step;
    int i, j;
    for(step=n/2; step>0; step/=2){
        for(i=0; i<n; i++){
            key = a[i];
            for(j=i-step; j>=0 && a[j]>key; j-=step){
                a[j+step] = a[j];
            }
            a[j+step] = key;
        }
    }
}

void count(int *a, int n){
    int i, j;
    int len, max, min;
    max = a[0];
    min = a[0];
    for(i=0; i<n; i++){
        if(max<a[i]){
            max = a[i];
        }
        if(min>a[i]){
            min = a[i];
        }
    }
    len = max-min+1;
    int b[len];
    for(i=0; i<len; i++){
        b[i]=0;
    }
    for(i=0; i<n; i++){
        b[a[i]-min]++;
    }
    j = 0;
    for(i=0; i<len; i++){
        while(b[i]--){
            a[j++] = i+1;
        }
    }
}

void reheap(int *a, int n, int index){
    int child = 2*index+1;
    while(child<n){
        if(child+1<n && a[child+1]<a[child]){
            child++;
        }
        if(a[child]<a[index]){
            swap(&a[child], &a[index]);
            index = child;
        }else{
            break;
        }
        child = 2*index+1;
    }
}

void heapsort(int *a, int n){
    int i;
    for(i=n/2-1; i>=0; i--){
        reheap(a, n, i);
    }
    for(i=n-1; i>=0; i--){
        swap(&a[i], &a[0]);
        reheap(a, i, 0);
    }
}

void arr(int *a, int left, int right){
    int mid = (left+right)/2;
    int len =right-left+1;
    int b[len];
    int i=left, j=mid+1, k=0;
    while(i<=mid && j<=right){
        if(a[i]<a[j]){
            b[k++] = a[i++];
        }else{
            b[k++] = a[j++];
        }
    }
    while(i<=mid){
        b[k++] = a[i++];
    }
    while(j<=right){
        b[k++] = a[j++];
    }
    for(i=0; i<k; i++){
        a[left+i] = b[i];
    }
}

void merge_sort(int *a, int left, int right){
    if(left>=right){
        return;
    }
    int mid = (left+right)/2;
    merge_sort(a, left, mid);
    merge_sort(a, mid+1, right);
    arr(a, left, right);
}

void merge(int *a, int n){
    merge_sort(a, 0, n-1);
}

int main(){
    int a[5] = {3, 1, 2, 5, 4};
    //bubble(a, 5);
    //insert(a, 5);
    //quick(a, 5);
    //bin_insert(a, 5);
    //choice(a, 5);
    //cocktail(a, 5);
    //shell(a, 5);
    //count(a, 5);
    //heapsort(a, 5);
    merge(a, 5);
    show(a, 5);
    return 0;
}
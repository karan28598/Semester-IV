#include<stdlib.h>
#include<stdio.h>

void merge(int arr[], int l, int m, int r){
    int i, j, k, n1 = m - l + 1, n2 =  r - m, L[n1], R[n2];

    for(i = 0; i < n1; i++){
        L[i] = arr[l + i];
    }

    for(j = 0; j < n2; j++){
        R[j] = arr[m + 1+ j];
    }

    i = 0, j = 0, k = l; 

    while(i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 

    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(int arr[], int l, int r){
    if (l < r){
        int m = l+(r-l)/2;
 
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}

int main(){
    int i, j, n, *data;

    printf("Merge Sort Application\n");
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    data = (int *)malloc(sizeof(int)*n);
    
    for(j=0; j<n; j++){
        scanf("%d", &data[j]);
    }
    
    mergeSort(data, 0, n-1);

    printf("The sorted array is: ");

    for (i=0; i<n; i++){
        printf("%d ", data[i]);
    }

    printf("\n");

    return 0;
}
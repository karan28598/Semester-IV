#include<stdio.h>
#include<stdlib.h>
 
int getMax(int A[], int n){
    int i;
    int max = A[0];
    for (i = 1; i < n; i++){
        if (A[i] > max){
            max = A[i];
        }
    }
    return max;
}
 
void radixSort(int A[], int n){
    int i, digitPlace = 1, result[n], largestNum = getMax(A, n);
 
    while(largestNum/digitPlace >0){
 
        int count[10] = {0};

        for (i = 0; i < n; i++){
            count[ (A[i]/digitPlace)%10 ]++;
        }
 
        for (i = 1; i < 10; i++){
            count[i] += count[i - 1];
        }
 
        for (i = n - 1; i >= 0; i--){
            result[count[ (A[i]/digitPlace)%10 ] - 1] = A[i];
            count[ (A[i]/digitPlace)%10 ]--;
        }
 
        for (i = 0; i < n; i++){
            A[i] = result[i];
        }
 
            digitPlace *= 10;
    }
}
 
int main(){
    int i, j, n, *data;

    printf("Radix Sort Application\n");
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    data = (int *)malloc(sizeof(int)*n);
    
    for(j=0; j<n; j++){
        scanf("%d", &data[j]);
    }
    
    radixSort(data, n);

    printf("The sorted array is: ");

    for (i=0; i<n; i++){
        printf("%d ", data[i]);
    }

    printf("\n");

    return 0;
}
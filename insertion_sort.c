#include <stdio.h>
#include <math.h>

void insertionSort(int arr[], int n){
   int p, key, q;
   for (p=1; p<n; p++){
       key = arr[p];
       q = p-1;
       while (q>=0 && arr[q]>key){
           arr[q+1] = arr[q];
           q = q-1;
       }    
       arr[q+1] = key;
   }
}

int main(){
    int i, j, n, *data;

    printf("Insertion Sort Application\n");
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    data = (int *)malloc(sizeof(int)*n);
    
    for(j=0; j<n; j++){
        scanf("%d", &data[j]);
    }
    
    insertionSort(data, n);

    printf("The sorted array is: ");

    for (i=0; i<n; i++)
       printf("%d ", data[i]);
    printf("\n");

    return 0;
}
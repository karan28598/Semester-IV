#include <stdio.h>

void sort(int *data, int n){
    int i, j, temp;
    for (i = 1; i < n; i++){
        temp = data[i];
        for (j=i; j>0 && data[j-1]>temp; j--){
            data[j] = data[j-1];
        }
        data[j] = temp;
    }
}

int binarySearch(int arr[], int l, int r, int x){
   if (r >= l){
        int mid = l + (r - l)/2;
 
        if (arr[mid] == x)  
            return mid;
 
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid-1, x);
 
        return binarySearch(arr, mid+1, r, x);
   }
   return -1;
}

int main(){
    int j, c, n, *data;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    data = (int *)malloc(sizeof(int)*n);
    
	for(j=0; j<n; j++){
        scanf("%d", &data[j]);
    }
    
    sort(data, n);

	int l=0, r=n-1, flag=1, search;
    while(flag){
        printf("Enter a number to search for: ");
        scanf("%d", &search);

        int k = binarySearch(data, l, r, search);

        if(k == -1)
            printf("%d does not exist in the array.\n", search);
        else
            printf("%d exists in the array.\n", search);

        printf("\n\nDo you wish to continue?\n1. Yes\n0. No\n");
        scanf("%i", &flag);
        printf("\n");
    }    
    return 0;
}
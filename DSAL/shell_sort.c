#include<stdio.h>
#include<math.h>

int shellSort(int arr[], int n){
	int i, gap;
    for(gap=n/2; gap>0; gap/=2){
        for(i=gap; i<n; i+=1){
            int temp = arr[i], j;           
            for(j=i; j>=gap && arr[j-gap]>temp; j-=gap){
            	arr[j] = arr[j-gap];
			}
            arr[j] = temp;
        }
    }
    return 0;
}

int main(){
    int i, j, n, *data;

    printf("Shell Sort Application\n");
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    data = (int *)malloc(sizeof(int)*n);
    
    for(j=0; j<n; j++){
        scanf("%d", &data[j]);
    }
    
    shellSort(data, n);

    printf("The sorted array is: ");

    for (i=0; i<n; i++){
       printf("%d ", data[i]);
    }
    printf("\n");
    
    return 0;
}
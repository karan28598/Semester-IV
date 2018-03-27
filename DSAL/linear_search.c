#include <stdio.h>
 
int main(){
    int search, c, n, flag=1;
   
    printf("Enter the number of elements in array: ");
    scanf("%d", &n);
    
    int array[n]; 
    printf("Enter the elements\n");
   
    for(c=0; c<n; c++){
      scanf("%d", &array[c]);
    }

    while(flag){
      printf("Enter a number to search for: ");
      scanf("%d", &search);
     
      for(c=0; c<n; c++){
        if (array[c] == search){
          printf("%d is present at location %d.\n", search, c+1);
          break;
        }
      }

      if(c == n){
        printf("%d isn't present in the array.\n", search);
      }

      printf("\n\nDo you wish to continue?\n1. Yes\n0. No\n");
      scanf("%i", &flag);
      printf("\n");
    } 
    return 0;
}
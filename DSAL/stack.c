#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*top = NULL;

void push(int value){
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = value;
   if(top == NULL) newNode->next = NULL;
   else newNode->next = top;
   top = newNode;
   //printf("\nPushed element: %i\n", value);
}

void pop(){
   if(top == NULL)
      printf("\nStack is Empty.\n");
   else{
      struct Node *temp = top;
      //printf("\nDeleted element: %i", temp->data);
      top = temp->next;
      free(temp);
   }
}

void display(){
   if(top == NULL)
      printf("\nStack is Empty.\n");
   else{
      struct Node *temp = top;
      while(temp->next != NULL){
         printf("%i->",temp->data);
         temp = temp -> next;
      }
      printf("%i->NULL",temp->data);
   }
}

int main(){
    int input, nodes, data, flag=1;
    
    while(flag){
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("Operation: ");
        scanf("%i", &input);
    
        switch(input){
            case 1:
                printf("\nEnter the number of nodes: ");
                scanf("%i", &nodes);
            
                printf("\nEnter the data for each node: ");
                while(nodes--){
                    scanf("%i", &data);
                    push(data);
                }
                
                printf("\nNew Stack:\n ");
                display();
                break;
                
            case 2:
                pop();
                printf("\nNew Stack:\n ");
                display();
                break;
                
            case 3:
                printf("\nContents of Stack:\n ");
                display();
                break;
        
            default:
                printf("Invalid operation.\n");
        }
        printf("\n\nDo you wish to continue?\n1. Yes\n0. No\n");
    scanf("%i", &flag);
    printf("\n");
    }
    return 0;
}

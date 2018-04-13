#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int x){
  struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
  temp->data = x; 
  temp->next = NULL;
  if(front == NULL && rear == NULL){
    front = rear = temp;
    return;
  }
  rear->next = temp;
  rear = temp;
}

void dequeue(){
  struct Node* temp = front;
  if(front == NULL){
    printf("Queue is Empty\n");
    return;
  }
  if(front == rear){
    front = rear = NULL;
  }
  else{
    front = front->next;
  }
  free(temp);
}

void display(){
  struct Node* temp = front;
  while(temp != NULL){
    printf("%d ",temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main(){
    int input, nodes=0, data, flag=1;
    
    while(flag){
        printf("1. Park new car \n");
        printf("2. Move earliest coming car \n");
        printf("3. Print all cars \n");
        printf("4. Print the number of cars \n");
        printf("Operation: ");
        scanf("%i", &input);
    
        switch(input){
            case 1:
                printf("\nEnter the car ID number: ");
                scanf("%i", &data);
                enqueue(data);
                printf("\nCar has been parked.\n ");
                nodes++;
                break;
                
            case 2:
                dequeue();
                printf("\nNew Queue:\n ");
                display();
                break;
                
            case 3:
                printf("\nContents of Queue:\n ");
                display();
                break;

            case 4:
                printf("Total number of cars parked are %i.", nodes);
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
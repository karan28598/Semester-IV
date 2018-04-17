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
    printf("Hotel is empty\n");
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

int correct(int p){
    if(p>100 && p<131){
        return 1;
    }
    printf("Please select a valid number.\n");
    return 0;
}

int search(int p){
  printf("Checking Availability...\n");
  struct Node* temp = front;
  while(temp != NULL){
    if(temp->data == p){
        printf("This room is already booked.\n");
        return 0;
    }
    else temp = temp->next;
  }
  return 1;
}

int main(){  
  int n,ch,age,gg,status,rooms=0;
  long long phone_number;
  char name[100];
  do{
  printf("Name: ");
  scanf("%s",name);
  printf("Age: ");
  scanf("%d",&age);
  printf("Phone number: ");
  scanf("%lld",&phone_number);
  printf("\t\t\tWelcome to Hotel Paradise\t\t\t \n");
  printf("\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~\t\t\t\n");
  printf("\nChoose from the following numbers to book a room!\n101-110 -> Standard Rooms\n111-120 -> Deluxe Rooms\n121-130 -> Suite ");
  do{
    printf("\nChoose your action \n1.Book a room\n2.Vacate a room\n3.List of booked rooms\n4.Exit\n");
    scanf("%d",&ch);
    switch(ch){
      case 1:if(rooms<30){
                 printf("Enter room number you want to book:");
                 scanf("%d",&n);
                      if(correct(n)){
                         if(search(n)){
                            enqueue(n); 
                            printf("Room no. %d has been booked for you.\n", n); 
                            rooms++;
                         }
                     }   
             }
             else{
                 printf("All the rooms are occupied. Please wait in the queue until a room gets vacated. Inconvenience is regretted.");
             }
             break;
             
      case 2:dequeue();
             break;
             
      case 3:printf("\nThese are the rooms that are already occupied:\n ");
             display();
             break;
    }
  }
  while(ch!=4);
  printf("Do you want to book rooms under other user?(1.Yes  2.No)\n");
  scanf("%d", &gg);
  }
  while(gg!=2);
  return 0;
}
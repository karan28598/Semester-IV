#include<stdio.h>
#include<string.h>
#define size 20

//Functions Used
void insertq(int[],int);
void deleteq(int[]);
void display(int[]);

//Global Variables
int front = -1;
int rear = -1;

int main(){  
  int n,ch,age,queue[size],gg;
  long long phone_number;
  char name[100];
  do{
  printf("1:Name: ");
  scanf("%s",name);
  printf("2:Age: ");
  scanf("%d",&age);
  printf("3:Phone number: ");
  scanf("%lld",&phone_number);
  printf("\t\t\tWelcome to Hotel Paradise\t\t\t \n");
  printf("\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~\t\t\t\n");
  printf("\nChoose from the following numbers to book a room!\n100-110 -> Standard Rooms\n200-210 -> Deluxe Rooms\n300-310 -> Suite ");
  do{
    printf("\nChoose your action \n1.Book a room\n2.Delete a room\n3.Display status of room booked\n4.Exit\n");
    scanf("%d",&ch);
    switch(ch){
      case 1:printf("Enter room number you want to book:");
             scanf("%d",&n);
             insertq(queue,n);
             break;
             
      case 2:deleteq(queue);
             break;
             
      case 3:display(queue);
             break;
    }
  }
  while(ch!=4);
  printf("Do you want to book rooms under other user?(1:yes  2:no)\n");
  scanf("%d",&gg);
  }
  while(gg!=2);
  return 0;
}

//Function Definitions
void insertq(int queue[],int item){
  if ((front == 0 && rear == size-1)||(front == rear+1)){
      printf("Sorry you cannot book room.Rooms are full\n");
      return;
  }
  else if(rear == -1){
      rear++;
      front++;
  }
  else if(rear == size-1 && front>0){
      rear =0;
  } 
  else{
      rear++;
  }
queue[rear]=item;
}

void display(int queue[]){
  int i;
  printf("Your room has been booked.You booked room number: ");
  if(front>rear){
    for(i=front;i<size;i++){
        printf("%d\t",queue[i]);
    }
    for(i=0;i<=rear;i++)
    printf("%d\t",queue[i]);
  }
  else{
    for(i=front;i<=rear;i++)
    printf("%d\t",queue[i]);
  }
}

void deleteq(int queue[]){
  if(front==-1){
      printf("No rooms booked for deletion\n");
  }
  else if(front==rear){
      printf("\nRoom number %d has been cancelled\n",queue[front]);
      front=-1;
      rear=-1;
  }
  else{
      printf("\nRoom number %d has been cancelled", queue[front]);
      front++;
  }
}
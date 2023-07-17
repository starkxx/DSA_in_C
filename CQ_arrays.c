//Implementation of circular queue using array
#include<stdio.h>      //header files
#include<stdlib.h>

#define N 10

int front=-1,rear=-1,queue[N];   // declaring front and rear

void enqueue()          //function to enter the value into the circular queue
{
   int val;
   printf("Enter the value : ");
   scanf("%d",&val);
   
   if((rear+1)%N==front)            //checking if the circular queue is full
   {
      printf("Overflow");
      return ;
   }
   else if((front==-1)&&(rear==-1))
   {
     front=0;
     rear=0;
   }
   else if((rear==N-1)&&(front!=0))
   rear=0;
   
   else
   rear=(rear+1)%N;
   
   queue[rear]=val;
   printf("Value enqueued\n");
}

void dequeue()         //function to delete the value into the circular queue
{
  int val;
  if((front==-1)&&(rear==-1))           //checking if the circular queue is empty
  {
    printf("Underflow");
    return ;
  }
  
  val=queue[front];
  
  if(front==rear)
  {
    front=-1;
    rear=-1;
  }
  
  else if(front==N-1)
  front=0;
  
  else
  front=front+1;
  
  printf("Value = %d Dequeued\n",val);
}

void display()         //function to display the values in the circular queue
{
  int i=front;
  
  if((front==-1)&&(rear==-1))          //checking if the queue is empty
  {
    printf("Queue is empty");
    return ;
  }
  
  else
  {
    printf("Elements in a queue are : ");
    while(i!=rear)
    {
      printf("%d\t",queue[i]);
      i=(i+1)%N;
    }
    printf("%d",queue[i]);
  }
  
  printf("\n");
  
}


int main()
{
  int choice;
  while(1)
  {
    printf("Select the operation\n");
    printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n"); 
    scanf("%d",&choice);
    switch(choice)
    {
      case 1: enqueue();
              break;
      case 2: dequeue();
              break;
      case 3: display();
              break;
      case 4: exit(0);
      default: printf("Invalid choice");
              break;
     }   
   }
  return 0;
  
}   
    

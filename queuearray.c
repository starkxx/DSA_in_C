//Implementation of queues using array
#include<stdio.h>  //header files
#include<stdlib.h>

#define size 15

int front=-1,rear=-1;
int queue[size];

void insert()   	//function to insert element into the queue
{
  int item;
  printf("Enter the element : ");
  scanf("%d",&item);
 
  if(rear==size-1)        	// checking if queue is full
  {
	printf("Overflow");
	return ;
  }
 
  if(front==-1&&rear==-1)   
  {
	front=0;
	rear=0;
  }
 
  else
  {
	rear=rear+1;
  }
  queue[rear]=item;
  printf("Value inserted\n");
}

void delete()  	// function to delete the first element entered
{
  int item;
  if(front==-1||front>rear)  //checking if queue is empty
  {
	printf("Underflow");
  }
 
  else
  {
	item=queue[front];
	if(front==rear)
	{
  	front=-1;
  	rear=-1;
	}
    
	else
	{
  	front=front+1;
	}
    
   printf("Value Deleted %d\n",item);
  }
}

void display()	// function to display the elements in the queue
{
  int i;
  if(rear==-1)	// checking if queue is empty+
  printf("Empty Queue");
 
  else
  {
	printf("Printing values\n");
	for(i=front;i<=rear;i++)
	{
  	printf("%d\t",queue[i]);
	}
	printf("\n");
  }
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
  	case 1: insert();
          	break;
  	case 2: delete();
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

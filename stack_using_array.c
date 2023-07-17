//Implementaion of a stack using array
#include<stdio.h>
#include<stdlib.h>

#define SIZE 4

int top=-1;
int arr[SIZE];        // Taking stack array of size  4


// Function declarations
void push();
void pop();
void show();
int main()
{
    int choice;
    while(1)          // Taking user input for the operation to be performed

    {
        printf("Select the operation on stack\n");
        printf("1.push\n2.pop\n3.show\n4.Exit\n");
        scanf("%d",&choice);
        switch(choice) 
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            show();
            break;
        case 4:
            exit(0);
        default :
            printf("Invalid choice");
        }
    }
}
void push()        //function to push an element to the stack
{
    int x;
    if(top==SIZE-1)
        printf("Overflow\n");
    else 
    {
        printf("Enter the element to be inserted\n");
        scanf("%d",&x);
        top++;
        arr[top]=x;
    }
}

void pop()         //function to remove an element from the stack
{
    if(top==-1)
        printf("underflow\n");
    else 
    {
        printf("Removed element is %d\n",arr[top]);
        top--;
    }
}

void show()                //function to display the elements in the stack
{
    int i;
    if(top!=-1) 
    {
        for(i=top; i>=0; i–) 
        {
            printf("%d\t",arr[i]);
        }
        printf("\n");
    } 
    else 
    {
        printf("Stack is empty\n");
    }
}

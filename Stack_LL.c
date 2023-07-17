//Implementation of stack using linked lists
#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void display();

struct node  // Structure to create a node with data and the next pointer
{
    int val;
    struct node *next;
};
struct node *head;

void push()        //function to push an element inside the stack
{
    int val;
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    if(ptr==NULL) 
    {
        printf("Not able to push the element");
    } 
    else 
    {
        printf("Enter the value\n");
        scanf("%d",&val);
        if(head==NULL) 
        {
            ptr->val=val;
            ptr->next=NULL;
            head=ptr;
        } 
        else 
        {
            ptr->val=val;
            ptr->next=head;
            head=ptr;
        }
        printf("Item pushed\n");
    }
}

void pop()    //function to remove the element from the stack
{
    int item;
    struct node *ptr;
    if(head==NULL) 
    {
        printf("Underflow\n");
    } 
    else 
    {
        item=head->val;
        ptr=head;
        head=head->next;
        free(ptr);
        printf("Item popped %d\n",item);
    }
}


void display()       // function to display the elements in the stack
{
    int i;
    struct node *ptr;
    ptr=head;
    if(ptr==NULL) 
    {
        printf("Stack is empty\n");
    } 
    else 
    {
        printf("printing stack elements\n");
        while(ptr!=NULL)
        {
            printf("%d\t",ptr->val);
            printf("\n");
            ptr=ptr->next;
        }
    }
}

int main()         // main where the execution starts
{
    int choice;
    while(1) 
    {
        printf("Select the operation\n");
        printf("1.push\n2.pop\n3.display\n4.exit\n");
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
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");

        }
    }
}

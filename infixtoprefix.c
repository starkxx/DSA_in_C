// Conversion of expression from infix to prefix expression
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define max 25


int top=-1;
char stack[50];

void push(char x)  // Push function here, inserts value in stack and increments stack top by 1
{
    stack[++top]=x;
}

char pop()  // Function to remove an item from stack.  It decreases top by 1 
{
    if(top==-1)     // checking is stack is empty
        return -1;
    else
        return stack[top--];
}

int priority(char x) // Fucntion to compare precedence If we return larger value means higher precedence 

{
    if(x=='(')
        return 0;
    if(x=='+'||x=='-')
        return 1;
    if (x=='*'||x=='/')
        return 2;
    if(x=='^'||x=='$')
        return 3;
    return 0;
}





void reverse(char *exp)  // reverse string
{ 

    int size = strlen(exp);
    char temp[size];
    temp[size--]='\0';
    int i=0;
    while(exp[i]!='\0') 
    {
        temp[size]=exp[i];
        i++;
        size--;
    }
    strcpy(exp,temp);
}

void brackets(char *exp)   //change brackets
{
    int i=0;
    while(exp[i]!='\0')
    {
        if(exp[i]==')')
            exp[i]='(';
        else if(exp[i]=='(')
            exp[i]=')';
        i++;
    }
}


void postfix(char *exp)  // The driver function for infix to postfix conversion 
{
    char temp,postfix[50];
    int j=0,i=0;
    temp=exp[i];
    char x;

    while(exp[i]!='\0') 
    {
        temp=exp[i];
        if(isalnum(temp))  // If the scanned character is an operand, store it

            postfix[j++]=temp;


        else if (temp=='(')  // If the scanned character is an ‘(‘, push it to the stack.
            push(temp);
        else if (temp==')')   // If the scanned character is an ‘)’,
                            // pop and output from the stack
                             // until an ‘(‘ is encountered.

        {
            while((x=pop())!='(')
                postfix[j++]=x;
        } 
        else   // an operator is encountered
        {
            while(priority(stack[top])>=priority(temp))
                postfix[j++]=pop();

            push(temp);

        }

        i++;
    }
    while(top!=-1)
    {
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    strcpy(exp,postfix);
}

void InfixtoPrefix(char *exp) //function converting infix to prefix
{
    reverse(exp);
    brackets(exp);
    postfix(exp);
    reverse(exp);
}





int main()
{
    char exp[50];
    printf("Enter the expression");
    scanf("%s",exp);

    InfixtoPrefix(exp);
    printf("%s",exp);
    return 0;
}

//Conversion of an expression from infix to postfix expression
#include<stdio.h>
#include<ctype.h>

char stack[25];
int top = -1;

void push(char x) //function to push an element to the stack
{
    stack[++top] = x;
}

char pop() //function to remove an element from the stack
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)            // A utility function to return precedence of a given operator
                                        // Higher returned value means
{                                       // higher precedence
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}

int main()
{
    char exp[35];
    char *e, x;
    printf("Enter the expression \n ");
    scanf("%s",exp);
    printf("\n");
    e = exp;

    while(*e != '\0') 
    {
        if(isalnum(*e))  // If the scanned character is an operand, print it
            printf("%c ",*e);
        else if(*e == '(') // If the scanned character is an ‘(‘, push it to the stack.
            push(*e);
        else if(*e == ')')  // If the scanned character is an ‘)’,
                            // pop and output from the stack
                             // until an ‘(‘ is encountered.
        {
            while((x = pop()) != '(')
                printf("%c ", x);
        } 
        else  // an operator is encountered
        {
            while(priority(stack[top]) >= priority(*e))
                printf("%c ",pop());
            push(*e);
        }
        e++;
    }

    while(top != -1)    // pop all the operators from the stack
    {
        printf("%c ",pop());
    }
    return 0;
    printf("\n");
}

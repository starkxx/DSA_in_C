//Evation of postfix expression
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define max 500

int top=-1;
char stack[max];

void push(int x)  // function to push the element in the stack
{
  stack[++top]=x;
}

int pop() //function to remove element from the stack
{

    return stack[top--];
}

int main()
{
    char exp[50], *e;
    int a,b,c,num;
    printf("Enter the postfix expression\n");
    scanf("%s",exp);

    e=exp;
    while(*e!=0) 
    {

        if(isdigit(*e)) // If the scanned character is an operand (number here),
        // push it to the stack.
        {
            num=(*e)-48;
            push(num);
        }
        else  // If the scanned character is an operator, pop two
        // elements from stack apply the operator
        {
            a=pop();
            b=pop();
            switch(*e) // switch case to perform the operator operation
            {
            case '+':
                c=b+a;
                break;

            case '-':
                c=b-a;
                break;

            case '*':
                c=b*a;
                break;

            case '/':
                c=b/a;
                break;

            case '^':
                c=pow(b,a);
                break;

            case '$':
                c=pow(b,a);
                break;

            default:
                printf("Invalid operators exist\n");
                break;
            }
            push(c);
        }
        e++;
    }
    printf("Final answer is %d",pop());
    return 0;
}

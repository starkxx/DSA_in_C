// Factorial using recursion
#include<stdio.h>
int factorial(int);
int main()
{
  int n,a;
  printf("Enter the number you want to find factorial : "); //Taking input for the number you want to find factorial
  scanf("%d",&n);
  
  printf("Factorial of %d is %d \n",n,factorial(n));
  return 0;
}

int factorial(int n) // Function definition of factorial
{
  if(n==0)  // if entered number is zero then return 1
  return 1;
  
  else if(n==1) // if entered number is 1 then return 1
  return 1;
  
  else   // if entered number is anything postive then return the number itself and call the function for number - 1
  return n*factorial(n-1);  
} 

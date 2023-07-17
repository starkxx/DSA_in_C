//Binary search using recursion
#include<stdio.h>
int binary_search(int arr[],int x,int low,int high) // Function defintion of binary search
{
  if(high>=low)
  {
    int mid=(low+high)/2;
    if(arr[mid]==x)
     return mid;
    else if(arr[mid]>x)
     return binary_search(arr,x,low,mid-1);
    else 
     return binary_search(arr,x,mid+1,high);
   }
   return -1;
}

int main()
{
 int i,n,x;
 
 printf("Enter the no of elements in array\n"); // Taking the input for no of elements in array
 scanf("%d",&n);
 
 int arr[n];
 
 printf("Enter the elements of the array in ascending order\n"); // taking input for the array in ascending order
 for(i=0;i<n;i++)
 {
   scanf("%d",&arr[i]);
 }  
 
 printf("Enter the element you want to search : "); // taking iinput for the element to search
 scanf("%d",&x);

 int result=binary_search(arr,x,0,n-1);  //functions returns a value based on if the element is present or not
 if(result==-1)
  printf("Not found");
 else 
 printf("Element is found at %d ",result+1);
} 

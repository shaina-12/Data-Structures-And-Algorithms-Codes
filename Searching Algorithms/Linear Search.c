#include<stdio.h>
int lsearch(int arr[],int size,int item)
{
for(int i=0;i<size;i++)
{
if(arr[i]==item)
{
return i;
}
}
return -1;
}
int main()
{
int size, arr[100],item;
printf("\nEnter the array limit/size: ");
scanf("%d",&size);
printf("\nEnter the array elements: ");
for(int i=0;i<size;i++)
{
scanf("%d",&arr[i]);
}
printf("\nEnter the item to be searched: ");
scanf("%d",&item);
int l=lsearch(arr,size,item);
if(l==-1)
{
printf("\nThe item is not found in the given array.");
}
else
{
printf("\nThe item is found in the given array at index no %d.",l);
}
return 0;
}

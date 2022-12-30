#include<stdio.h>
void selectionsort(int arr[100],int size)
{
int small,pos;
for(int i=0;i<size-1;i++)
{
small=arr[i];
pos=i;
for(int j=i;j<size;j++)
{
if(small>arr[j])
{
small=arr[j];
pos=j;
}
}
int temp=arr[i];
arr[i]=arr[pos];
arr[pos]=temp;
}
for(int i=0;i<size;i++)
{
printf("%d ",arr[i]);
}
}
int main()
{
int size, arr[100];
printf("\nEnter the array limit/size: ");
scanf("%d",&size);
printf("\nEnter the array elements: ");
for(int i=0;i<size;i++)
{
scanf("%d",&arr[i]);
}
printf("The sorted array is: ");
selectionsort(arr,size);
return 0;
}

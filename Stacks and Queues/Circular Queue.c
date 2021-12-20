//Circular Queue Implementation
#include <stdio.h> 
int front=-1 ,rear=-1; 
#define maxsize 5 
void enqueue(int cqueue[maxsize],int value); 
int dequeue(int cqueue[maxsize]); 
void traverse(int cqueue[maxsize]); 
int main() 
{ 
    int cqueue[maxsize]; 
    int value; 
    int choice; 
    int d; 
    char ch='y'; 
    do{ 
        printf("\nMain Menu"); 
        printf("\n1.Enqueue"); 
        printf("\n2.Dequeue"); 
        //printf("\n3.Peek"); 
        //printf("\n4.Traverse"); 
        printf("\nEnter your choice"); 
        scanf("%d",&choice); 
        switch(choice) 
        { 
            case 1:printf("enter the value to be entered"); 
                   scanf("%d",&value); 
                   enqueue(cqueue,value); 
                   traverse(cqueue); 
            break; 
            case 2:d=dequeue(cqueue); 
                   printf("\nthe element deleted from the circular queue is %d",d); 
                   traverse(cqueue); 
            break; 
            default:printf("\nInvalid Entry"); 
        } 
        printf("\ndo you want to continue"); 
        scanf("%s",&ch); 
    }while(ch=='y' || ch=='Y'); 
    return 0; 
} 
void enqueue(int cqueue[maxsize],int value) 
{ 
    if((rear==maxsize-1 && front==0)||(front==rear+1)) 
    { 
        printf("\nthe circular queue is overflowing"); 
    } 
    else
    { 
        if(front==-1)
        {
            front=0;
            rear=0;
        }
        else if(rear==maxsize-1)
        {
            rear=0;
        }
        else
        {
            rear=rear+1;  
        }
        cqueue[rear]=value; 
    } 
} 
int dequeue(int cqueue[maxsize]) 
{ 
    if(front==-1 && rear==-1) 
    { 
        printf("\nthe circular queue is underflow"); 
        return 0; 
    } 
    else 
    { 
        int temp;
        if(front == rear)
        {
            temp=cqueue[front];
            front =rear=-1;
        }
        else if(front==maxsize-1)
        {
            temp=cqueue[front];
            front=0;
        }
        else
        {
            temp=cqueue[front];
            front++;
        }
        return temp; 
    } 
} 
void traverse(int cqueue[maxsize]) 
{ 
    if(front==-1 && rear==-1) 
    { 
        printf("\nthe circular queue is underflow"); 
    } 
    else 
    { 
        printf("\nthe elements present in the circular queue are:"); 
        printf("\n");
        int i; 
        if(front<=rear)
        {
            for(int i=front;i<=rear;i++) 
            { 
                printf("%d ",cqueue[i]); 
            } 
            printf("\n"); 
        }
        else
        {
            for(int i=front;i<=maxsize-1;i++) 
            { 
                printf("%d ",cqueue[i]); 
            } 
            for(int i=0;i<=rear;i++) 
            { 
                printf("%d ",cqueue[i]); 
            } 
            printf("\n"); 
        }
    } 
}


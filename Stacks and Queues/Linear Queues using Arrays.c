// Linear Queue Implementation
#include <stdio.h> 
int front=-1 ,rear=-1; 
#define maxsize 10 
void enqueue(int queue[maxsize],int value); 
int dequeue(int queue[maxsize]); 
int peek(int queue[maxsize]); 
void traverse(int queue[maxsize]); 
int main() 
{ 
    int queue[maxsize]; 
    int value; 
    int choice; 
    int c,d; 
    char ch='y'; 
    do{ 
        printf("\nMain Menu"); 
        printf("\n1.Enqueue"); 
        printf("\n2.Dequeue"); 
        printf("\n3.Peek"); 
        printf("\n4.Traverse"); 
        printf("\nEnter your choice"); 
        scanf("%d",&choice); 
        switch(choice) 
        { 
            case 1:printf("enter the value to be entered"); 
                   scanf("%d",&value); 
                   enqueue(queue,value); 
            break; 
            case 2:d=dequeue(queue); 
                   printf("\nthe element deleted from the queue is %d",d);
            break; 
            case 3:c=peek(queue); 
                   printf("\nthe current element entered in the stack is %d",d); 
            break; 
            case 4:traverse(queue); 
            break; 
            default:printf("\nInvalid Entry"); 
        } 
        printf("\ndo you want to continue"); 
        scanf("%s",&ch); 
    }while(ch=='y' || ch=='Y'); 
    return 0; 
} 
void enqueue(int queue[maxsize],int value) 
{ 
    if(rear==maxsize-1) 
    { 
        printf("\nthe queue is overflowing"); 
    } 
    else{ 
        if(front==-1)
        {
            front=0;
        }
        rear=rear+1; 
        queue[rear]=value; 
    } 
} 
int dequeue(int queue[maxsize]) 
{ 
    if(front == rear+1) 
    { 
        printf("\nthe queue is underflow"); 
        return '\0'; 
    } 
    else 
    { 
        int temp; 
        temp=queue[front];
        front++;
        return temp; 
    } 
} 
int peek(int queue[maxsize]) 
{ 
    if(front==rear+1) 
    { 
        printf("\nthe queue is underflow"); 
        return '\0'; 
    } 
    else 
    { 
        return queue[front]; 
    } 
} 
void traverse(int queue[maxsize]) 
{ 
    if(front==rear+1) 
    { 
        printf("\nthe queue is underflow"); 
    } 
    else 
    { 
        printf("\nthe elements present in the queue are:"); 
        printf("\n"); 
        int i; 
        for(int i=front;i<=rear;i++) 
        { 
            printf("%d ",queue[i]); 
        } 
        printf("\n"); 
    } 
} 

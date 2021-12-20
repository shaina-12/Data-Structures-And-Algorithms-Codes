//Stack implementation using arrays
/*It will work for integers but remember to declare everything in integer not in char*/ 
#include <stdio.h>
int top=-1;
int size;
void push(char stack[size],char value);
int pop(char stack[size]);
int peek(char stack[size]);
void traverse(char stack[size]);
int main()
{
    printf("\nenter the maximum size of the stack");
    scanf("%d",&size);
    char stack[size];
    char value;
    int choice;
    char c,d;
    char ch='y';
    do{
        printf("\nMain Menu");
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Peek");
        printf("\n4.Traverse");
        printf("\nEnter your choice");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("enter the value to be entered");
                   scanf("%s",&value);
                   push(stack,value);
                   traverse(stack);
            break;
            case 2:d=pop(stack);
                   printf("\nthe element deleted from the stack is %c",d);
                   traverse(stack);
            break;
            case 3:c=peek(stack);
                   printf("\nthe current element entered in the stack is %c",c);
            break;
            case 4:traverse(stack);
            break;
            default:printf("\nInvalid Entry");
        }
        printf("\ndo you want to continue");
        scanf("%s",&ch);
    }while(ch=='y' || ch=='Y');
    return 0;
}
void push(char stack[size],char value)
{
    if(top==size-1)
    {
        printf("\nthe stack is overflowing");
    }
    else{
        top=top+1;
        stack[top]=value;
    }
}
int pop(char stack[size])
{
    if(top==-1)
    {
        printf("\nthe stack is underflow");
        return '\0';
    }
    else
    {
        char temp;
        temp=stack[top];
        top--;
        return temp;
    }
}
int peek(char stack[size])
{
    if(top==-1)
    {
        printf("\nthe stack is underflow");
        return '\0';
    }
    else
    {
        return stack[top];
    }
}
void traverse(char stack[size])
{
    if(top==-1)
    {
        printf("\nthe stack is underflow");
    }
    else
    {
        printf("\nthe elements present in the stack are:");
        printf("\n");
        int i;
        for(int i=top;i>=0;i--)
        {
            printf("%c ",stack[i]);
        }
        printf("\n");
    }
}

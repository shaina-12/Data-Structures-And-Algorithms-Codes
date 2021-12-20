//Single Linked List Implementation
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;//stores the addrerss of the node
};
struct Node *head=NULL;
struct Node *tail=NULL;
void takeinput();//inseting the node in the linked list
void insert();//inserting ith node in the linked list
void delete();//deleting ith node in the linked list
void length();//finding the length of the linked list
void print();//printing the linked list
int main()
{
    int data,pos,delpos;
    int choice;
    while(1)
    {
        printf("\n Main Menu");
        printf("\n 1.Create");
        printf("\n 2.Insert");
        printf("\n 3.Delete");
        printf("\n 4.Display");
        printf("\n 5.Length");
        printf("\n 6.Exit");
        printf("\n Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("enter the data in the linked list before it implementing it");
                   takeinput();
                   print();
            break;           
            case 2:insert();
                   print();
            break;
            case 3:delete();
                   print();
            break;
            case 4:print();
            break;
            case 5:length();
            break;
            case 6:exit(0);
            break;
            default: printf("invalid entry");
        }
    }
    return 0;
}
void takeinput()
{
    struct Node *n=(struct Node*) malloc(sizeof(struct Node));
    int data;
    printf("\n enter the data");
    scanf("%d",&n->data);
    n->next=NULL;
    if(head==NULL)
    {
        head=n;
        tail=n;
    }
    else
    {
        //tail=head;
        tail->next=n;
        tail=tail->next;
    }
}
void insert()
{
    int pos;
    struct Node *n=(struct Node*) malloc(sizeof(struct Node));
    printf("enter the position in which the data is to be inserted");
    scanf("%d",&pos);
    printf("enter the data");
    scanf("%d",&n->data);
    n->next=NULL;
    struct Node *temp;
    int ctr=0;
    if(pos==0)
    {
        n->next=head;
        head=n;
    }
    temp=head;
    while(temp!=NULL && ctr<pos-1)
    {
        temp=temp->next;
        ctr++;
    }
    if(temp!=NULL)
    {
        struct Node *a=temp->next;
        temp->next=n;
        n->next=a;
    }
}
void delete()
{
int delpos;
if(head==NULL)
{
printf("pls enter the element in the linked list");
     return;
}
    printf("enter the position in which the data is to be deleted");
    scanf("%d",&delpos);
    int ctr=0;
    struct Node *temp=head;
    if(delpos==0)
    {
        head=temp->next;
        temp->next=NULL;
        free(temp);
        return;
    }
    while(temp->next!=NULL && ctr<delpos-1)
    {
        temp=temp->next;
        ctr++;
    }
    if(temp->next!=NULL)
    {
        struct Node *a=temp->next;
        struct Node *b=a->next;
        temp->next=b;
        a->next=NULL;
        free(a);
    }
    return;
}
void print()
{
    struct Node *temp=head;
    if(temp==NULL)
    {
        printf("\n pls enter any enement in the linked list");
        return;
    }
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
    return;
}
void length()
{
    struct Node *temp=head;
    int i=0;
    while(temp!=NULL)
    {
        i++;
        temp=temp->next;
    }
    printf("\n the length of the linked list is %d",i);
}

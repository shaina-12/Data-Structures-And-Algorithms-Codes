# include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
Node *createList(){
    int data;
    cin>>data;
    Node *head = NULL;
    Node *tail = NULL;
    while(data != -1){
        Node *node = new Node(data);
        if(head==NULL){
            head = node;
            tail = node;
        }
        else{
            tail->next = node;
            tail=node;
        }
        cin>>data;
    }
    return head;
}
void printNode(Node *head){
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
Node *mergeTwoLinkedList(Node *head1,Node *head2){
    Node *temp1 = head1;
    Node *temp2 = head2;
    Node *head3 = NULL, *tail3 = NULL;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data<=temp2->data){
            if(head3==NULL){
                head3 = tail3 = temp1;
                temp1=temp1->next;
            }
            else{
                tail3->next = temp1;
                tail3 = temp1;
                temp1=temp1->next;
            }
        }
        else{
            if(head3==NULL){
                head3 = tail3 = temp2;
                temp2=temp2->next;
            }
            else{
                tail3->next = temp2;
                tail3 = temp2;
                temp2=temp2->next;
            }
        }
    }
    if(temp1==NULL){
        while(temp2!=NULL){
            tail3->next = temp2;
            tail3 = temp2;
            temp2=temp2->next;
        }
    }
    else{
        while(temp1!=NULL){
            tail3->next = temp1;
            tail3 = temp1;
            temp1=temp1->next;
        }
    }
    return head3;
}
int main(){
    cout<<"Enter the two sorted linked lists: "<<endl;
    Node *head1 = createList();
    Node *head2 = createList();
    cout<<"The merged linked list is: ";
    Node *head3 = mergeTwoLinkedList(head1,head2);
    printNode(head3);
}

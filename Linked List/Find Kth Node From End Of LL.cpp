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
int length(Node *head){
    int len = 0;
    Node *temp = head;
    while(temp!=NULL){
        len++;
        temp = temp -> next;
    }
    return len;
}
int findKthNodeFromEnd(Node *head,int k){
    int n = length(head);
    int index = n-k;
    Node *temp = head;
    int i = 0;
    while(temp!=NULL && i<index){
        temp = temp -> next;
        i++;
    }
    return temp->data;
}
int main(){
    cout<<"Enter the nodes of the linked list: ";
    Node *head = createList();
    cout<<"The linked list is: ";
	printNode(head);
    int pos;
    cout<<"Enter the index from 1 to "<<length(head)<<" : ";
	cin >> pos;
    if(pos>length(head) || pos<=0){
        cout<<"Wrong Index!!!"<<endl;
    }
    else{
        cout<<"The kth node of the linked list from the last is: "<<findKthNodeFromEnd(head,pos)<<endl;
    }
    return 0;
}

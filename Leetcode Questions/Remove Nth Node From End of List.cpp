/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
int length(ListNode *head){
    int len = 0;
    ListNode *temp = head;
    while(temp!=NULL){
        len++;
        temp = temp -> next;
    }
    return len;
}
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l = length(head);
        if(l==1){
            head=NULL;
            return head;
        }
        int index = l-n;
        cout<<index;
        ListNode *temp = head;
        int i=0;
        if(index==0){
            head=head->next;
            return head;
        }
        else{
            while(temp->next!=NULL && i<index-1){
                temp=temp->next;
                i++;
            } 
            if(temp->next!=NULL){
                ListNode *a = temp->next;
                temp->next=a->next;
                a->next=NULL;
                delete a;
            }
            return head;
        }
    }
};

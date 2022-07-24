/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int length(ListNode *head){
    if(head==NULL){
        return 0;
    }
    ListNode *temp = head;
    int ctr = 0;
    while(temp!=NULL){
        temp=temp->next;
        ctr++;
    }
    return ctr;
}
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
         ListNode *tmp1 = headA;
    ListNode *tmp2 = headB;
    if(length(tmp1)==length(tmp2)){
        while(tmp1!=NULL and tmp2!=NULL){
            if(tmp1 == tmp2){
                break;
            }
            else{
                tmp1=tmp1->next;
                tmp2=tmp2->next;
            }
        }
    }
    else if(length(tmp1)>length(tmp2)){
        int a = length(tmp1)-length(tmp2);
        int ctr = 0;
        while(ctr<a){
            tmp1=tmp1->next;
            ctr++;
        }
        while(tmp1!=NULL and tmp2!=NULL){
            if(tmp1 == tmp2){
                break;
            }
            else{
                tmp1=tmp1->next;
                tmp2=tmp2->next;
            }
        }
    }
    else{
        int a = length(tmp2)-length(tmp1);
        int ctr = 0;
        while(ctr<a){
            tmp2=tmp2->next;
            ctr++;
        }
        while(tmp1!=NULL and tmp2!=NULL){
            if(tmp1 == tmp2){
                break;
            }
            else{
                tmp1=tmp1->next;
                tmp2=tmp2->next;
            }
        }
    }
    return tmp1;
    }
};

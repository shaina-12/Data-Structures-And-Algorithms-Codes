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
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return head;
        
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *even_start = head->next;
        
        while(odd->next && even->next){
            odd->next = even->next; //Connect all odds
            even->next = odd->next->next;  //Connect all evens
            odd = odd->next;
            even = even->next;
        }
        odd->next = even_start;   //Place the first even node after the last odd node.
        return head; 
    }
};
/*ListNode *h1=NULL, *t1=NULL;
        ListNode *temp1=head;
        int i = 1;
        while(temp1!=NULL){
            if(i%2!=0){
                if(h1==NULL){
                    h1=t1=temp1;
                }
                else{
                    t1->next=temp1;
                    t1=t1->next;
                }
            }
            temp1=temp1->next;
            i++;
        }
        ListNode *temp2=head;
        i = 1;
        while(temp2!=NULL){
            if(i%2==0){
                if(h1==NULL){
                    h1=t1=temp2;
                }
                else{
                    t1->next=temp2;
                    t1=t1->next;
                }
            }
            temp2=temp2->next;
            i++;
        }
        return h1;*/

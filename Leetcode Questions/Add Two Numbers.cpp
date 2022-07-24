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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp1 = l1;
        ListNode *temp2 = l2;
        ListNode *head = NULL;
        ListNode *tail = NULL;
        int carry=0;
        while(temp1!=NULL && temp2!=NULL){
            int sum = temp1->val + temp2->val + carry;
            int ans = sum%10;
            int a = sum/10;
            if(a==0){
                carry=0;
            }
            else{
                carry=1;
            }
            ListNode *node = new ListNode(ans);
            if(head==NULL && tail==NULL){
                head = tail = node;
            }
            else{
                tail->next = node;
                tail=tail->next;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        if(temp1==NULL){
            while(temp2!=NULL){
                int sum = temp2->val + carry;
                int ans = sum%10;
                int a = sum/10;
                if(a==0){
                    carry=0;
                }
                else{
                    carry=1;
                }
                ListNode *node = new ListNode(ans);
                if(head==NULL && tail==NULL){
                    head = tail = node;
                }
                else{
                    tail->next = node;
                    tail=tail->next;
                }
                temp2=temp2->next;
            }
        }
        if(temp2==NULL){
            while(temp1!=NULL){
                int sum = temp1->val + carry;
                int ans = sum%10;
                int a = sum/10;
                if(a==0){
                    carry=0;
                }
                else{
                    carry=1;
                }
                ListNode *node = new ListNode(ans);
                if(head==NULL && tail==NULL){
                    head = tail = node;
                }
                else{
                    tail->next = node;
                    tail=tail->next;
                }
                temp1=temp1->next;
            }
        }
        if(temp1==NULL && temp2==NULL && carry==1){
            ListNode *node = new ListNode(1);
            if(head==NULL && tail==NULL){
                head = tail = node;
            }
            else{
                tail->next = node;
                tail=tail->next;
            }
        }
        return head;
    }
};

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
int Length(ListNode *head){
    ListNode *temp = head;
    int ctr=0;
    while(temp!=NULL){
        temp=temp->next;
        ctr++;
    }
    return ctr;
}
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int n = Length(head);
        if(n==1){
            return true;
        }
        stack<int> s;
        int i=1;
        ListNode *temp=head;
        while(i<=n/2){
            s.push(temp->val);
            i++;
            temp=temp->next;
        }
        if(n%2!=0){
            temp=temp->next;
        }
        while(temp!=NULL){
            if(s.top()!=temp->val){
                return false;
            }
            s.pop();
            temp=temp->next;
        }
        return true;
    }
};

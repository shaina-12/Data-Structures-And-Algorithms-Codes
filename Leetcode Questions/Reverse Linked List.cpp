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
    ListNode* reverseList(ListNode* head) {
       if (!head || !(head -> next)) {
            return head;
        }
        ListNode* node = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return node;
    }
};

// Another Approach
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
/*
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode *x = reverseList(head->next);
        ListNode *y = x;
        while(y->next!=NULL){
            y=y->next;
        }
        y->next=head;
        head->next=NULL;
        return x;
    }
};
*/

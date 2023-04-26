/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node==NULL){
            return;
        }
        ListNode *a=node->next;
        *node=*a;
        delete a;
    }
};


// Another Approach
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
     /*
class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node==NULL){
            return;
        }
        ListNode *temp=node;
        ListNode *prev;
        while(temp->next!=NULL){
            temp->val = temp->next->val;
           / prev=temp;
            temp = temp->next;
        }
        prev->next=NULL;
        delete temp;
    }
};*/

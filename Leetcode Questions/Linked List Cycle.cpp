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
    bool hasCycle(ListNode *head) {
        ListNode *temp = head;
        vector<ListNode *> m;
        while(temp!=NULL){
            if(find(m.begin(),m.end(),temp)==m.end()){
                m.push_back(temp);
                temp=temp->next;
            }
            else{
                return true;
            }
        }
        return false;
    }
};

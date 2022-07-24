/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int x = maxDepth(root->left);
        int y = maxDepth(root->right);
        return max(x,y)+1;
}
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(root==NULL){
            return v;
        }
        int h = maxDepth(root);
        for(int i=0;i<h;i++){
            vector<int> v1;
            v.push_back(v1);
        }
        queue<pair<TreeNode*,int>> q;
        pair<TreeNode*,int> p;
        p.first=root;
        p.second=0;
        q.push(p);
        while(!q.empty()){
            pair<TreeNode*,int> node;
            node.first = q.front().first;
            node.second = q.front().second;
            int level = node.second;
            v[level].push_back(node.first->val);
            q.pop();
            if(node.first->left!=NULL){
                pair<TreeNode*,int> p1;
                p1.first=node.first->left;
                p1.second=level+1;
                q.push(p1);
            }
            if(node.first->right!=NULL){
                pair<TreeNode*,int> p1;
                p1.first=node.first->right;
                p1.second=level+1;
                q.push(p1);
            }
        }
        for(int i=0;i<v.size();i++){
            if(i%2!=0){
                reverse(v[i].begin(),v[i].end());
            }
        }
        return v;
    }
};

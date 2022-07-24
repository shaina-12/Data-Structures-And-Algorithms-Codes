/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
int maxDepth(Node* root) {
        if(root==NULL){
            return 0;
        }
        int x = maxDepth(root->left);
        int y = maxDepth(root->right);
        return max(x,y)+1;
}
class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL){
            return root;
        }
        if(root->left==NULL && root->right==NULL){
            return root;
        }
        vector<vector<Node*>> v;
        int h = maxDepth(root);
        for(int i=0;i<h;i++){
            vector<Node*> v1;
            v.push_back(v1);
        }
        queue<pair<Node*,int>> q;
        pair<Node*,int> p;
        p.first=root;
        p.second=0;
        q.push(p);
        while(!q.empty()){
            pair<Node*,int> node;
            node.first = q.front().first;
            node.second = q.front().second;
            int level = node.second;
            v[level].push_back(node.first);
            q.pop();
            if(node.first->left!=NULL){
                pair<Node*,int> p1;
                p1.first=node.first->left;
                p1.second=level+1;
                q.push(p1);
            }
            if(node.first->right!=NULL){
                pair<Node*,int> p1;
                p1.first=node.first->right;
                p1.second=level+1;
                q.push(p1);
            }
        } 
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].size()-1;j++){
                v[i][j]->next = v[i][j+1];
            }
        }
        return root;
    }
};

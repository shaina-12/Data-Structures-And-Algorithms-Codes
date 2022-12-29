#include <stdio.h>
#include <stdlib.h>
struct BTNode
{
    int data;
    struct BTNode *lc;
    struct BTNode *rc;
};
struct BTNode* insert(struct BTNode *root)
{
    int data;
    struct BTNode *node=(struct BTNode*)malloc(sizeof(struct BTNode));
    printf("\nEnter the node data: ");
    scanf("%d",&data);
    if(data==-999999)
    {
        return NULL;
    }
    node->data=data;
    root=node;
    root->lc=insert(root);
    root->rc=insert(root);
    return root;
}
void Inorder_Traversal(struct BTNode *root)
{
    if(root==NULL)
    {
        return;
    }
    Inorder_Traversal(root->lc);
    printf("%d ",root->data);
    Inorder_Traversal(root->rc);
    return;
}
void Preorder_Traversal(struct BTNode *root)
{
    if(root==NULL)
    {
        return;
    }
    printf("%d ",root->data);
    Preorder_Traversal(root->lc);
    Preorder_Traversal(root->rc);
    return;
}
void Postorder_Traversal(struct BTNode *root)
{
    if(root==NULL)
    {
        return;
    }
    Postorder_Traversal(root->lc);
    Postorder_Traversal(root->rc);
    printf("%d ",root->data);
    return;
}
int Count_Nodes(struct BTNode *root)
{
   if(root==NULL)
   {
       return 0;
   }
   if(root->lc==NULL && root->rc==NULL)
   {
       return 1;
   }
   return Count_Nodes(root->lc)+Count_Nodes(root->rc)+1; 
}
int Count_Leaf_Nodes(struct BTNode *root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->lc==NULL && root->rc==NULL)
    {
        return 1;
    }
    int ans1=Count_Leaf_Nodes(root->lc);
    int ans2=Count_Leaf_Nodes(root->rc);
    //printf("Shaina: %d",ans1+ans2);
    return ans1+ans2;
}
int main()
{
    struct BTNode *root=NULL;
    printf("\nEnter the elements of the binary tree.");
    root=insert(root);
    printf("\nInorder traversal of the binary tree is: ");
    Inorder_Traversal(root);
    printf("\nPreorder traversal of the binary tree is: ");
    Preorder_Traversal(root);
    printf("\nPostorder traversal of the binary tree is: ");
    Postorder_Traversal(root);
    int nodes=Count_Nodes(root);
    printf("\nNo of nodes in the binary tree is: %d",nodes);
    int leafnode=Count_Leaf_Nodes(root);
    printf("\nNo of leaf nodes in the binary tree is: %d",leafnode);
    return 0;
}

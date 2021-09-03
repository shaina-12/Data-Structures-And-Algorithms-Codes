#include <stdio.h>
#include <stdlib.h>
struct BSTNode
{
    int data;
    struct BSTNode *lc;
    struct BSTNode *rc;
};
struct BSTNode *Insert(struct BSTNode *root)
{
    struct BSTNode *n=(struct BSTNode*)malloc(sizeof(struct BSTNode));
    printf("\nEnter the data to be inserted: ");
    scanf("%d",&n->data);
    n->lc=NULL;
    n->rc=NULL;
    struct BSTNode *temp=root;
    struct BSTNode *temp2=NULL;
    while(temp!=NULL)
    {
        temp2=temp;
        if(temp->data<n->data)
        {
            temp=temp->rc;
        }
        else
        {
            temp=temp->lc;
        }
    }
    if(temp2==NULL)
    {
        root=n;
    }
    else if(temp2->data<n->data)
    {
        temp2->rc=n;
    }
    else
    {
        temp2->lc=n;
    }
    return root;
}
void Inorder_Traversal(struct BSTNode *root)
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
void Preorder_Traversal(struct BSTNode *root)
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
void Postorder_Traversal(struct BSTNode *root)
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
struct BSTNode *search(struct BSTNode *root,int item)
{
    if(root==NULL)
    {
        printf("\nThe BST is empty.");
        return root;
    }
    else
    {
        struct BSTNode *temp=root;
        while(temp!=NULL)
        {
            if(temp->data==item)
            {
                return temp;
            }
            else if(temp->data<item)
            {
                temp=temp->rc;
            }
            else
            {
                temp=temp->lc;
            }
        }
        if(temp==NULL)
        {
            return temp;
        }
    }
}
struct BSTNode *Delete(struct BSTNode *root,int item)
{
    if(root==NULL)
    {
        return root;
    }
    if(item<root->data)
    {
        root->lc=Delete(root->lc,item);
    }
    else if(item>root->data)
    {
  /      root->rc=Delete(root->rc,item);
    }
    else
    {
        if(root->lc==NULL && root->rc==NULL)
        {
            root=NULL;
            return root;
        }
        else if(root->lc!=NULL && root->rc==NULL)
        {
            struct BSTNode *r=root;
            root=root->lc;
            r->lc=NULL;
            free(r);
            return root;
        }
        else if(root->lc==NULL && root->rc!=NULL)
        {
            struct BSTNode *r=root;
            root=root->rc;
            r->rc=NULL;
            free(r);
            return root;
        }
        else
        {
            struct BSTNode *r=root;
            struct BSTNode *t=root->rc;
            root=t;
            while(t->lc!=NULL)
            {
                t=t->lc;
            }
            t->lc=r->lc;
            r->lc=NULL;
            r->rc=NULL;
            free(r);
            return root;
        }
    }
}
int main()
{
    struct BSTNode *root=NULL;
    printf("\nEnter the elements of the binary search tree.");
    root=Insert(root);
    root=Insert(root);
    root=Insert(root);
    root=Insert(root);
    root=Insert(root);
    root=Insert(root);
    root=Insert(root);
    root=Insert(root);
    root=Insert(root);
    printf("\nInorder traversal of the Binary Search Tree is: ");
    Inorder_Traversal(root);
    printf("\nPreorder traversal of the Binary Search Tree is: ");
    Preorder_Traversal(root);
    printf("\nPostorder traversal of the Binary Search Tree is: ");
    Postorder_Traversal(root);
    printf("\nEnter the item to be searched:");
    int item;
    scanf("%d",&item);
    struct BSTNode *i=search(root,item);
    if(!i)
    {
        printf("\nThe item is not found in BST.");
    }
    else
    {
        printf("\nThe item is found in BST.");
    }
    int item1,item2,item3,item4;
    printf("\nEnter the item to be deleted: ");
    scanf("%d",&item1);
    root=Delete(root,item1);
    printf("\nInorder traversal of the Binary Search Tree is: ");
    Inorder_Traversal(root);
    printf("\nPreorder traversal of the Binary Search Tree is: ");
    Preorder_Traversal(root);
    printf("\nPostorder traversal of the Binary Search Tree is: ");
    Postorder_Traversal(root);
    printf("\nEnter the item to be deleted: ");
    scanf("%d",&item2);
    root=Delete(root,item2);
    printf("\nInorder traversal of the Binary Search Tree is: ");
    Inorder_Traversal(root);
    printf("\nPreorder traversal of the Binary Search Tree is: ");
    Preorder_Traversal(root);
    printf("\nPostorder traversal of the Binary Search Tree is: ");
    Postorder_Traversal(root);
    printf("\nEnter the item to be deleted: ");
    scanf("%d",&item3);
    root=Delete(root,item3);
    printf("\nInorder traversal of the Binary Search Tree is: ");
    Inorder_Traversal(root);
    printf("\nPreorder traversal of the Binary Search Tree is: ");
    Preorder_Traversal(root);
    printf("\nPostorder traversal of the Binary Search Tree is: ");
    Postorder_Traversal(root);
    printf("\nEnter the item to be deleted: ");
    scanf("%d",&item4);
    root=Delete(root,item4);
    printf("\nInorder traversal of the Binary Search Tree is: ");
    Inorder_Traversal(root);
    printf("\nPreorder traversal of the Binary Search Tree is: ");
    Preorder_Traversal(root);
    printf("\nPostorder traversal of the Binary Search Tree is: ");
    Postorder_Traversal(root);
    return 0;
}

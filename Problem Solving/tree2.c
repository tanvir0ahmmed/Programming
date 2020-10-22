#include<stdio.h>
#include<stdlib.h>
typedef struct node Node;
struct node
{
    int data;
    Node* left;
    Node* right;
};
Node* New_node(int data)
{
    Node* new_node=(Node*)malloc(sizeof(Node));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}
Node* insert(Node* root,int data)
{
    if(root==NULL)
    {
        root=New_node(data);
    }
    else if(data<=root->data)
        root->left=insert(root->left,data);
    else
        root->right=insert(root->right,data);
    return root;
}

/*void printl(Node* x)
{
    while(x!=NULL)
    {
        x=x->left;
        printf("%d\n",x->data);
    }
}
void printr(Node* x)
{
    while(x!=NULL)
    {
        x=x->right;
        printf("%d\n",x->data);
    }
}*/
void pre_order(Node* root)
{
    printf("%d ",root->data);
    if(root->left!=NULL)
        pre_order(root->left);
    if(root->right!=NULL)
        pre_order(root->right);

}
int main()
{
    Node* root=NULL;
    root=insert(root,15);
    root=insert(root,14);
    root=insert(root,18);
    root=insert(root,12);
    root=insert(root,15);
    root=insert(root,11);
    root=insert(root,13);
    root=insert(root,7);
    root=insert(root,8);
    root=insert(root,17);
    root=insert(root,16);
    root=insert(root,49);
    root=insert(root,40);
    root=insert(root,50);
    root=insert(root,39);
    root=insert(root,41);
    pre_order(root);

}

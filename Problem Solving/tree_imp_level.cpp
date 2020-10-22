#include<iostream>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
typedef struct node Node;
struct node
{
    int data;
    Node* left;
    Node* right;
};
Node* temp;
Node* new_node(Node* root, int x)
{
    Node *nd=(Node*)malloc(sizeof(Node));
    nd->data=x;
    nd->left=NULL;
    nd->right=NULL;
    return nd;
}

Node* insert(Node* root,int x)
{
    if(root==NULL)
    {
        root=new_node(root,x);
    }
    else if(root->data>=x)
    {
        root->left=insert(root->left,x);
    }
    else
    {
        root->right=insert(root->right,x);
    }
    return root;
}
void pre_order(Node* root)
{
    printf("%d ",root->data);
    if(root->left!=NULL)
        pre_order(root->left);
    if(root->right!=NULL)
        pre_order(root->right);
}
void search(Node* root,int x)
{
    if(root->data==x)
    {
        printf("\nFound = %d\n",root->data);
    }
    else if(root->data>=x&&root->left!=NULL)
    {
        search(root->left,x);
    }
    else if(root->data<x&&root->right!=NULL)
    {
        search(root->right,x);
    }
    else
    {
        printf("\nData Not Found\n");
    }
}
Node* find_min_right(Node* root)
{
    while(root->left!=NULL)
        root=root->left;
    return root;
}
Node* deleted(Node* root,int x)
{
    if(root==NULL)
        return root;
    else if(x<root->data)
        root->left=deleted(root->left,x);
    else if(x>root->data)
        root->right=deleted(root->right,x);
    else
    {
        if(root->left==NULL)
        {
            Node* temp=root;
            root=root->right;
            free(temp);
        }
        else if(root->right==NULL)
        {
            Node* temp=root;
            root=root->left;
            free(temp);
        }
        else if(root->left==NULL&&root->right==NULL)
        {
            free(root);
            root = NULL;
            return root;
        }
        else
        {
            Node* temp;
            temp=find_min_right(root->right);
            root->data=temp->data;
            root->right=deleted(root->right,temp->data);
        }
    }
    return root;
}

int Find_min(Node* root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root->data;

}
int Find_max(Node* root)
{
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root->data;

}
int Find_height(Node* root)
{
    if(root==NULL)
        return 0;
    int left_height=Find_height(root->left);
    int right_height=Find_height(root->right);
    if(left_height>right_height)
        return left_height+1;
    else
        return right_height+1;
}
int max(Node* root,int l,int r)
{
    int m;
    if(l>r)
    {
        m=l;
    }
    else
    {
        m=r;
    }
    l=0,r=0;
    printf("m=%d\n",m);
}
void level_order(Node* root)
{
    if(root==NULL) return;
    queue<Node*> Q;
    Q.push(root);
    cout<<"Level order: ";
    while(!Q.empty())
    {
        Node* current=Q.front();
        cout<<current->data<<" ";
        if(current->left!=NULL) Q.push(current->left);
        if(current->right!=NULL) Q.push(current->right);
        Q.pop();
    }
    cout<<endl;
}
bool right_subtree(Node* root,int n);
bool left_subtree(Node* root,int n)
{
    if(root==NULL)
        return true;
    if(root->left!=NULL)
    {
        if(root->data<=n&&left_subtree(root->left,n)&&right_subtree(root->right,n))
        {
            return true;
        }
        else
            return false;
    }
}
bool right_subtree(Node* root,int n)
{
    if(root==NULL)
        return true;
    if(root->right!=NULL)
    {
        if(root->data>n&&left_subtree(root->left,n)&&right_subtree(root->right,n))
        {
            return true;
        }
        else
            return false;
    }
}
bool check(Node* root)
{
    if(root==NULL)
        return true;
    if(left_subtree(root->left,root->data)&&right_subtree(root->right,root->data)&&check(root->left)&&check(root->right))
    {
        cout<<"BST"<<endl;
        return true;
    }
}
int main()
{
    Node* root=NULL;
    Node* t;
    root = insert(root,5);
    root = insert(root,8);
    root = insert(root,9);
    root = insert(root,7);
    root = insert(root,4);
    root = insert(root,3);
    root = insert(root,1);
    root = insert(root,100);
    root = insert(root,50);
    root = insert(root,60);
    root = insert(root,30);
    root = insert(root,40);
    root = insert(root,20);
    root = insert(root,25);
    root = insert(root,10);
    printf("Before deleted: ");
    pre_order(root);
    root=deleted(root,5);
    printf("\nAfter deleted: ");
    pre_order(root);
    search(root,8);
    int min = Find_min(root);
    printf("min=%d\n",min);
    int max=Find_max(root);
    printf("max=%d\n",max);
    int r=Find_height(root);
    printf("h=%d\n",r-1);
    level_order(root);
    check(root);
}

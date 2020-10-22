#include<stdio.h>
#include<stdlib.h>
typedef struct node Node;
struct node
{
    int data;
    Node* left;
    Node* right;
};
Node *create_node(int x)
{
    Node *new_node=(Node*)malloc(sizeof(Node));
    new_node->data=x;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}
void left_side(Node *root,Node* child)
{
    root->left=child;
}
void right_side(Node *root,Node* child)
{
    root->right=child;
}
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
    Node *two,*three,*four,*five,*six,*seven,*eight,*nine,*ten,*one;
    two=create_node(2);
    seven=create_node(7);
    nine=create_node(9);
    left_side(two,seven);
    right_side(two,nine);
    one=create_node(1);
    six=create_node(6);
    left_side(seven,one);
    right_side(one,six);
    five=create_node(5);
    ten=create_node(10);
    left_side(six,five);
    right_side(six,ten);
    eight=create_node(8);
    right_side(nine,eight);
    three=create_node(3);
    four=create_node(4);
    left_side(eight,three);
    right_side(eight,four);
    pre_order(two);
}

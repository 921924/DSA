//WAP in c to implement tree.
// Print it int preorder, inorder, postorder.
#include<stdio.h>
#include<stdlib.h>
//struct node *insertAtleft(struct node *head, int data);
//struct node *insertAtright(struct node *head, int data);
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
} tree;
struct node *createNode(int data){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
int inOrder(tree *root){
	if(root == NULL){
        return 0;
    }
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}
int preOrder(tree *root){
    if(root ==  NULL){
        return 0;
    }
    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}
int postOrder(tree *root){
    if(root == NULL){
        return 0;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->data);
}
int main()
{
    tree *root =createNode(10); 
    root->left =createNode(8); 
    root->left->left =createNode(6); 
    root->left->right =createNode(2); 
    root->left->left->left =createNode(1); 
    root->left->right->left =createNode(18); 
    root->right=createNode(7); 
    root->right->right=createNode(9); 
    root->right->right->left=createNode(16); 
    root->right->right->right=createNode(15);
    root->right->right->right->left=createNode(21);

    inOrder(root);
    printf("\n");
    preOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");
}

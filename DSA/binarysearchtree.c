//WAP in c to implement tree.
//Print it in preorder, inorder, postorder.
//all types of Deletion in BST.
//WAP in c to search a element in BST.
#include<stdio.h>
#include<stdlib.h>
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
struct node *insertion(struct node *root, int data){
    struct node *temp = root;
    struct node *newNode = createNode(data);
    if(root == NULL){
         return createNode(data);
    }
    if(temp->data > data){
        temp->left = insertion(temp->left, data);
    }
    else{
        temp->right = insertion(temp->right, data);
    }
    return root;
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
struct node *searching(struct node *root, int key){
    if(root == NULL || root->data == key){
        return root;
    }
    if(root->data < key)
    {
        searching(root->right, key);
    }
    else{
        searching(root->left, key);
    }
}
struct node *deletion(struct node *root, int data){
    if(root == NULL){
        return root;
    }
    if(root->data > data){
            root->left = deletion(root->left, data);
            return root;
    }
    else if(root->data < data){
        root->right = deletion(root->right, data);
        return root;
    }
    else{
        if(root->left == NULL){
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        if(root->right == NULL){
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *parent = root;
        struct node *next = root->right;
        while(next->left != NULL){
        parent = next;
        next = next ->left;
        }
        root->data = next->data;
        parent->left = next->right;
        free(next);
        return root;
    }
}
int main()
{
    tree *root =createNode(14);
    root=insertion(root,20);
    int val, val_1;
    //printf("Enter the value to insert in tree: \n");
    //scanf("%d",&val);
    //insertion(root,val);
    //insertion(root,30);
    insertion(root,5);
    insertion(root,18);
    insertion(root,6);
    insertion(root,21);
    insertion(root,3);
    insertion(root,7);
    insertion(root,1);
    insertion(root,5);
    insertion(root,6);
    insertion(root,18);
    inOrder(root);
    printf("\n");
    preOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");
    printf("Enter the value to delete from tree: \n");
    scanf("%d",&val_1);
    root=deletion(root,val_1);
    printf("\n");
    printf("After deletion: \n");
    inOrder(root);
    printf("\n");
    preOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");
    int val_2;
    printf("Enter the value to search from tree: \n");
    scanf("%d",&val_2);
    struct node *result = searching(root, val_2);
    if(result!=NULL){
        printf("Element %d Present in the tree.\n",val_2);
    }
    else{
        printf("Element %d not present in the tree.\n", val_2);
    }
}

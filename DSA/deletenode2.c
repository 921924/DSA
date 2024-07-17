#include<stdio.h>
#include<stdlib.h>
struct node *createNode(int data);
struct node* insertAtBeg(struct  node* head, int data);
int  lengthoflist(struct node* head);
struct node* Delete(struct node* head, int val);
void display(struct node *temp);
typedef struct node{
    int data;
    struct node *next;
}sll;
struct node* createNode(int data){
    struct node* newNode=(struct node* )(malloc(sizeof(sll)));
    newNode->next=NULL;
    newNode->data=data;

    return newNode;
}
struct node* insertAtBeg(struct  node* head, int data)
{
	struct  node* temp;
    if(head ==NULL)
	{
      return createNode(data);
	}
    temp = createNode(data);
    temp->next=head;
    return temp;
}
struct node* Delete(struct node* head, int val){
   struct node *temp=head;
   struct node *curr=head->next;
    while(curr->data!=val && curr->next!=NULL)
   {
     temp=temp->next;
     curr=curr->next;
   }
    if(curr->data == val){
       temp->next =curr->next;
        free(curr);
    }
    return head;
}
void display(struct node *temp){
    while (temp != NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int main(){
    struct node *head=NULL;
    head=insertAtBeg(head,10);
    head=insertAtBeg(head,20);
   	head=insertAtBeg(head,30);
   	head=insertAtBeg(head,40);
   	head=insertAtBeg(head,50);
    printf("After Deletion: \n");
    head=Delete(head,30);
    display(head);

    printf("\n");
    return 0;
}

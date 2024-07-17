#include<stdio.h>
#include<stdlib.h>
struct node *createNode(int data);
struct node *insertAtEnd(struct node *head, int data);
void display(struct node *temp);
struct node *reverselist(struct node *head);
typedef struct node{
    int data;
    struct node *next;
}sll;
struct node *createNode(int data)
{
    struct node* newNode=(struct node* )(malloc(sizeof(sll)));
    newNode->next=NULL;
    newNode->data=data;

    return newNode;
}
struct node *reverselist(struct node *head)
{
	if(head == NULL ){
		return;
	}
	struct node *temp = head;
	struct node *new_head= NULL;
	while(temp != NULL){
		struct node *newNode = createNode(temp->data);
		newNode->next= new_head;
		new_head=newNode;
		temp=temp->next;
	}
	head = new_head;
	display(head);
}
struct node* insertAtEnd(struct node *head, int data){
    if(head == NULL){
        return createNode(data);
    }
    else{
        struct node *temp=head;
        while(temp->next != NULL){
            temp=temp->next;
        }
        temp->next=createNode(data);
    }
    return head;
}
void display(struct node *temp){
    while (temp != NULL)
    {
        printf(",%d ",temp->data);
        temp=temp->next;
    }
    
}
int main()
{
    struct node *head=NULL;
    head=insertAtEnd(head,10);
    insertAtEnd(head,20);
    insertAtEnd(head,30);
    insertAtEnd(head,40);
    insertAtEnd(head,50);
    insertAtEnd(head,60);
    insertAtEnd(head,70);
    insertAtEnd(head,80);
    insertAtEnd(head,90);
    insertAtEnd(head,100);
    display(head);
    printf("\n");
    reverselist(head);
    return 0;
}

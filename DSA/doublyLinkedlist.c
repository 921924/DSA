#include<stdio.h>
#include<stdlib.h>
struct node *createNode(int data);
struct node *insertAtEnd(struct node *head, int data);
struct node *insertAtBeg(struct node *head, int data);
struct node *insertAtMid(struct node *head, int data);
struct node *deleteAtEnd(struct node *head);
struct node *deleteAtBeg(struct node *head);
struct node *deleteAtMid(struct node *head, int data);
void display(struct node *temp); 
typedef struct node{
    int data;
    struct node *prev;
    struct node *next;
} dll;
dll *createNode(int data){
    dll* newNode=(dll*)(malloc(sizeof(struct node)));
    newNode->data=data;
    newNode->prev=NULL;
    newNode->next=NULL;

    return newNode;
}
dll* insertAtEnd(dll *head, int data){
    dll *newNode = createNode(data);
    if(head == NULL){
        return newNode;
    }
    dll *temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
       temp->next=newNode;
       newNode->prev=temp;
    return newNode;
}
dll *insertAtMid(dll *temp, int data){
    dll *newNode = createNode(data);
    newNode->prev=temp;
    newNode->next=temp->next->next->next;
    temp->next->next->next->prev=newNode;
    newNode->prev=temp;
    temp->next->next->next=newNode;
    return temp;
}
struct node *deleteAtBeg(struct node *head){
    struct node *temp=head;
    if(temp==NULL){
        printf("List is empty");
        return;
    }
    else
    {
        head = temp->next;
        head->prev=NULL;
    }
    free(temp);
    return head;
}
struct node *deleteAtMid(struct node *head, int data){
    struct node *temp=head;
    if(head==NULL){
        printf("List is Empty");
        return NULL;
    }
    while(temp->data != data)
    {
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    free(temp);
    printf("Given node deleted \n");
}
struct node *deleteAtEnd(struct node *head)
{
    if(head == NULL){
        printf("List is Empty");
        return NULL;
    }
    dll *temp = head;
    while(temp->next != NULL)
    {
        temp=temp->next;
    }
    if(temp->prev==NULL){
        head=NULL;
    }
    else{
        temp->prev->next=NULL;
    }
    free(temp);
    printf("Last node deleted.\n");
}

void display(dll* curr){
	struct node* last;
    while (curr != NULL)
    {
        printf("%d ",curr->data);
        last = curr;
        curr = curr->next;
    }
    printf("\n");
}
int main(){
    dll *head = NULL;
    head=insertAtEnd(head,10);
    insertAtEnd(head,20);
    insertAtEnd(head,30);
    insertAtEnd(head,40);
    insertAtEnd(head,50);
    insertAtEnd(head,60);
    insertAtEnd(head,70);
    insertAtEnd(head,80);
    insertAtEnd(head,90);
    display(head);
    //head=insertAtBeg(head,90);
    deleteAtEnd(head);
    display(head);
    printf("\n");
    //printf("\n");
    //display(head);
    //head=insertAtMid(head,45);
    //printf("\n");
    //display(head);
    head=deleteAtBeg(head);
    printf("List after deletion of first node: \n");
    display(head);
    printf("\n");
    deleteAtMid(head,50);
    printf("List after deletion of given node: \n");
    display(head);
    //printf("\n");

    return 0;
}
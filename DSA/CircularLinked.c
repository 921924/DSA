#include<stdio.h>
#include<stdlib.h>
struct node *createNode(int data);
struct node *insertAtEnd(struct node *head, int data);
struct node *insertAtBeg(struct node *head, int data);
void display(struct node *temp); 
typedef struct node{
    int data;
    struct node *prev;
    struct node *next;
} dll;
struct node *createNode(int data){
    struct node* newNode=(struct node*)(malloc(sizeof(struct node)));
    newNode->data=data;
    newNode->prev=NULL;
    newNode->next=NULL;

    return newNode;
}
struct node* insertAtEnd(struct node *head, int data){
    struct node *newNode = createNode(data);
    if(head == NULL){
        return newNode;
    }
    struct node *temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
       temp->next=newNode;
       newNode->prev=temp;
    return temp;
}
struct node *insertAtBeg(struct node *head, int data){
    struct node *newNode = createNode(data);
    newNode->next=head;
    newNode->prev=NULL;
    if(head != NULL){
        head->prev=newNode;
    }
    
    head=newNode;
    return head;
}
int getLength(struct node* head) {
    if (head == NULL) {
        return 0;
    }
    int count = 0;
    struct node* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
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
    head=insertAtEnd(head,10);
    insertAtEnd(head,20);
    insertAtEnd(head,30);
    insertAtEnd(head,40);
    insertAtEnd(head,50);
    insertAtEnd(head,60);
    insertAtEnd(head,70);
    insertAtEnd(head,80);
    display(head);
    head=insertAtBeg(head,90);
    printf("\n");
    display(head);
    int length = getLength(head);
    printf("Length of the doubly circular linked list: %d\n", length);

    printf("\n");

    return 0;
}

//WAP to find the length of Circular doubly Linked List.
#include<stdio.h>
#include<stdlib.h>
struct node *createNode(int data);
struct node *insertAtEnd(struct node *head, int data);
struct node *insertAtBeg(struct node *head, int data);
struct node *insertAtMid(struct node *head, int data);
int  lengthoflist(struct node* head);
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
    return temp;
}
dll *insertAtBeg(dll *head, int data){
    dll *newNode = createNode(data);
    newNode->prev=NULL;
    newNode->next=NULL;
    newNode->data=data;
    if(head != NULL){
        head->prev=newNode;
    }
    
    head=newNode;
    return head;
}
// dll *insertAtMid(dll *head, dll *temp, int data){
  //  dll *newNode = createNode(data);
    //newNode->prev=temp;
    //newNode->next=temp->next;
    //temp->next->prev=newNode;
   // newNode->prev=temp;
    //temp->next=newNode;
//}
int lengthoflist(struct node* head){
    struct node* temp=head;
    int count=1;
    if(temp==NULL){
        return 0;
    }
    while(temp != NULL && temp->next != NULL){
        count=count+2;
        temp=temp->next->next;
    }
    if(temp==NULL){
        return count-1;
    }
    else if(temp->next == NULL){
        return count;
    }
}
void display(dll *temp){
    if(temp ==  NULL){
        printf("The list is empty.\n");
        return;
    }
    struct node *curr = temp;
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(curr!=temp);
        printf("\n");
}
int main(){
    dll *head=NULL;
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
    //head=insertAtMid(head,45);
    //printf("\n");
    //display(head);
    int size=lengthoflist(head);
    printf("%d",size);
    printf("\n");

    printf("\n");

    return 0;
}
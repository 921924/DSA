#include<stdio.h>
#include<stdlib.h>
struct node *createNode(int data);
struct node *insertAtEnd(struct node *head, int data);
struct node* insertAtMid(struct  node* temp,int data);

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
        printf("%d ",temp->data);
        temp=temp->next;
    }
    
}
struct node* insertAtMid(struct  node* head, int data)
{
    int k=4;
    if(temp ==NULL && k>1){
         return createNode(data);
    }
    if(k==1){
        temp = newNode(data);
        temp->next = head;
        head = temp;
    }
    int count =1;
    while(temp !=NULL && count < k-1){
            temp = temp->next;
            count += 1;
    }
    if(temp == NULL){
            return temp;
    }else{
        temp->next=temp->next;
        temp->next=temp;
    }
int main(){
    struct node *head=NULL;
    head=insertAtEnd(head,10);
    insertAtEnd(head,20);
    insertAtEnd(head,30);
    insertAtEnd(head,40); 
    insertAtEnd(head,50);
    insertAtEnd(head,60);
    insertAtEnd(head,80);
    display(head);
    head=insertAtMid(head,35);
    printf("\n");
    display(head);

    printf("\n");

    return 0;
}
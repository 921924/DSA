#include<stdio.h>
#include<stdlib.h>
struct node *createNode(int data);
//struct node *insertAtEnd(struct node *head, int data);
struct node* insertAtBeg(struct  node* head, int data);
int getNthterm(struct node*head, int index);
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
	int getNthterm(struct node*head, int index){
    struct node *current = head;
    int count =0;
    while(current !=NULL){
        if(count==index){
            return(current->data);
        }
            count++;
            current = current->next;
            index--;
    }
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
    head=head=insertAtBeg(head,10);
    head=insertAtBeg(head,20);
   	head=insertAtBeg(head,30);
   	head=insertAtBeg(head,40);
   	head=insertAtBeg(head,50);
   	head=insertAtBeg(head,60);
   	head=insertAtBeg(head,70);
   	head=insertAtBeg(head,80);
   	head=insertAtBeg(head,90);
   	head=insertAtBeg(head,100);
    display(head);
    printf("\n");
    printf("Element at index 6 is: %d",getNthterm(head, 6));
    return 0;
}

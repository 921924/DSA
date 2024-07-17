//WAP to find the length of Circular doubly linked list.
#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node*  nodeCreation(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the end of circular DLL
void add(struct Node** head_ref, int data) {
    struct Node* new_node = nodeCreation(data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        (*head_ref)->next = *head_ref;
        (*head_ref)->prev = *head_ref;
        return;
    }
    struct Node* last = (*head_ref)->prev;
    last->next = new_node;
    new_node->prev = last;
    new_node->next = *head_ref;
    (*head_ref)->prev = new_node;
}

// Function to calculate the length of  circular DLL
int length(struct Node* head) {
    if (head == NULL)
        return 0;
    
    struct Node* current = head;
    int count = 0;
    do {
        count++;
        current = current->next;
    } while (current != head);
    
    return count;
}

// Function to print the circular DLL
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    struct Node* current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

// Main function 
int main() {
    struct Node* head = NULL;
    
    
    add(&head, 10);
    add(&head, 20);
    add(&head, 30);
    add(&head, 40);
    add(&head, 50);
    add(&head, 60);
    add(&head, 70);  
    add(&head, 80);  
    add(&head, 90);

    // Printing the circular doubly linked list
    printf("Circular doubly linked list: ");
    display(head);


    int len = length(head);
    printf("Length of the circular doubly linked list: %d\n", len);

    return 0;
}
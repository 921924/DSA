#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode->prev = newNode;
    } else {
        Node* tail = (*head)->prev;
        newNode->next = *head;
        newNode->prev = tail;
        *head->prev = newNode;
        tail->next = *head->prev;
        *head = newNode;
    }
}

// Function to insert a node at the end
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL){
        *head = newNode;
        newNode->next = newNode->prev = newNode;
    } else {
        Node* tail = (*head)->prev;
        newNode->next = *head;
        newNode->prev = tail;
        tail->next = *head->prev = newNode;
    }
}

// Function to insert a node after a given node
void insertAfter(Node* prevNode, int data) {
    if (prevNode == NULL) return;
    Node* newNode = createNode(data);
    Node* nextNode = prevNode->next;
    newNode->next = nextNode;
    newNode->prev = prevNode;
    prevNode->next = newNode;
    nextNode->prev = newNode;
}

// Function to delete a node from the beginning
void deleteFromBeginning(Node** head) {
    if (*head == NULL) return;
    Node* tail = (*head)->prev;
    Node* toDelete = *head;
    if (*head == tail) {
        *head = NULL;
    } else {
        *head = toDelete->next;
        tail->next = *head;
        (*head)->prev = tail;
    }
    free(toDelete);
}

// Function to delete a node from the end
void deleteFromEnd(Node** head) {
    if (*head == NULL) return;
    Node* tail = (*head)->prev;
    Node* toDelete = tail;
    if (*head == tail) {
        *head = NULL;
    } else {
        Node* newTail = tail->prev;
        newTail->next = *head;
        (*head)->prev = newTail;
    }
    free(toDelete);
}

// Function to delete a specific node
void deleteNode(Node** head, Node* delNode) {
    if (*head == NULL || delNode == NULL) return;
    if (*head == delNode) {
        deleteFromBeginning(head);
        return;
    }
    Node* prevNode = delNode->prev;
    Node* nextNode = delNode->next;
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
    free(delNode);
}

// Function to print the list
void printList(Node* head) {
    if (head == NULL) return;
    Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    Node* head = NULL;

    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtEnd(&head, 30);
    insertAfter(head->next, 25);

    printf("List after insertions: ");
    printList(head);

    deleteFromBeginning(&head);
    printf("List after deleting from beginning: ");
    printList(head);

    deleteFromEnd(&head);
    printf("List after deleting from end: ");
    printList(head);

    deleteNode(&head, head->next);
    printf("List after deleting a specific node: ");
    printList(head);

    return 0;
}

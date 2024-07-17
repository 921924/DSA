#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void Push(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void countElements(struct Node* head) {
    struct Node* temp = head;
    struct Node* inner;
    int counts[100] = {0};  // Assuming elements are in the range 0-99
    int uniqueElements[100];
    int uniqueCount = 0;

    while (temp != NULL) {
        int found = 0;
        for (int i = 0; i < uniqueCount; i++) {
            if (uniqueElements[i] == temp->data) {
                found = 1;
                break;
            }
        }
        if (!found) {
            uniqueElements[uniqueCount++] = temp->data;
        }
        counts[temp->data]++;
        temp = temp->next;
    }

    for (int i = 0; i < uniqueCount; i++) {
        printf("Element: %d, Count: %d\n", uniqueElements[i], counts[uniqueElements[i]]);
    }
}

int main() {
    struct Node* head = NULL;
    int elements[] = {10, 20, 30, 40, 10, 20, 60, 50};
    int n = sizeof(elements) / sizeof(elements[0]);

    for (int i = 0; i < n; i++) {
        Push(&head, elements[i]);
    }

    countElements(head);
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}
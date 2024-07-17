#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    int sum;
    struct node* next;
} node;

typedef struct LL {
    node* head;
    int totalSum;
    node* kthNode;
    int kthNodeIndex;
} LL;

node* createNode(int data, int sum) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->sum = sum;
    newNode->next = NULL;
    return newNode;
}

void initializeList(LL* list) {
    list->head = NULL;
    list->totalSum = 0;
    list->kthNode = NULL;
    list->kthNodeIndex = 0;
}

void add(LL* list, int data, int k) {
    list->totalSum += data;
    if (list->head == NULL) {
        list->head = createNode(data, list->totalSum);
        if (k == 1) {
            list->kthNode = list->head;
            list->kthNodeIndex = 1;
        }
    } else {
        node* current = list->head;
        int index = 1;
        while (current->next != NULL) {
            current = current->next;
            index++;
        }
        current->next = createNode(data, list->totalSum);
        index++;
        if (index == k) {
            list->kthNode = current->next;
            list->kthNodeIndex = index;
        }
    }
}

int sum(LL* list, int k) {
    if (list->kthNode != NULL && list->kthNodeIndex == k) {
        return list->kthNode->sum;
    } else {
        printf("Node does not exist or was not tracked.\n");
        exit(1);
    }
}

void display(LL* list) {
    node* current = list->head;
    while (current != NULL) {
        printf("data: %d, Sum: %d\n", current->data, current->sum);
        current = current->next;
    }
}

int main() {
    LL list;
    initializeList(&list);
    add(&list, 1, 2);
    add(&list, 2, 2);
    add(&list, 3, 2);

    display(&list);

    printf("Sum of 2nd node: %d\n", sum(&list, 2));

    return 0;
}
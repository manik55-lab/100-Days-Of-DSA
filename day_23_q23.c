#include <stdio.h>
#include <stdlib.h>

// Define structure for linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at end
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;

    return head;
}

// Function to merge two sorted linked lists
struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    struct Node* result = NULL;
    struct Node* tail = NULL;

    while (l1 != NULL && l2 != NULL) {
        struct Node* temp = NULL;

        if (l1->data <= l2->data) {
            temp = l1;
            l1 = l1->next;
        } else {
            temp = l2;
            l2 = l2->next;
        }

        if (result == NULL) {
            result = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    // Attach remaining nodes
    if (l1 != NULL)
        tail->next = l1;
    if (l2 != NULL)
        tail->next = l2;

    return result;
}

// Function to print linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, m, value;
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // Input first list
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        list1 = insertEnd(list1, value);
    }

    // Input second list
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        list2 = insertEnd(list2, value);
    }

    // Merge lists
    struct Node* merged = mergeLists(list1, list2);

    // Print merged list
    printList(merged);

    return 0;
}
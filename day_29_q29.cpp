#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, k, value, i;

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    // Input number of nodes
    scanf("%d", &n);

    if (n <= 0) {
        return 0;
    }

    // Create linked list
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Input k
    scanf("%d", &k);

    // If only one node or no rotation needed
    if (n == 1 || k == 0) {
        temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        return 0;
    }

    // Make list circular
    temp->next = head;

    // Reduce k if greater than n
    k = k % n;

    // Find (n - k)th node
    int steps = n - k;
    struct Node* current = head;

    for (i = 1; i < steps; i++) {
        current = current->next;
    }

    // New head
    head = current->next;

    // Break circular link
    current->next = NULL;

    // Print rotated list
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
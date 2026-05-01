#include <stdio.h>
#include <stdlib.h>

// Node for linked list (bucket)
typedef struct Node {
    float value;
    struct Node* next;
} Node;

// Insert in sorted order (Insertion sort in bucket)
Node* insertSorted(Node* head, float value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    // Insert at beginning or empty
    if (head == NULL || head->value >= value) {
        newNode->next = head;
        return newNode;
    }

    Node* curr = head;
    while (curr->next != NULL && curr->next->value < value) {
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;

    return head;
}

// Bucket Sort
void bucketSort(float arr[], int n) {
    // 1. Create buckets
    Node** buckets = (Node**)malloc(n * sizeof(Node*));

    for (int i = 0; i < n; i++) {
        buckets[i] = NULL;
    }

    // 2. Insert elements into buckets
    for (int i = 0; i < n; i++) {
        int index = (int)(arr[i] * n); // bucket index
        buckets[index] = insertSorted(buckets[index], arr[i]);
    }

    // 3. Concatenate buckets
    int k = 0;
    for (int i = 0; i < n; i++) {
        Node* curr = buckets[i];
        while (curr != NULL) {
            arr[k++] = curr->value;
            curr = curr->next;
        }
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        Node* curr = buckets[i];
        while (curr != NULL) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(buckets);
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    bucketSort(arr, n);

    // Print sorted array
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}
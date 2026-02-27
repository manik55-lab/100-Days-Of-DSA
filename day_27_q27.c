#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create list from array
struct Node* createList(int arr[], int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;

    for(int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = arr[i];
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// Function to calculate length
int getLength(struct Node* head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Function to find intersection
struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;

    // Move pointer of longer list ahead
    if(len1 > len2) {
        for(int i = 0; i < diff; i++)
            ptr1 = ptr1->next;
    } else {
        for(int i = 0; i < diff; i++)
            ptr2 = ptr2->next;
    }

    // Traverse together
    while(ptr1 != NULL && ptr2 != NULL) {
        if(ptr1 == ptr2)
            return ptr1;

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return NULL;
}

int main() {
    int n, m;

    scanf("%d", &n);
    int arr1[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr1[i]);

    scanf("%d", &m);
    int arr2[m];
    for(int i = 0; i < m; i++)
        scanf("%d", &arr2[i]);

    struct Node* head1 = createList(arr1, n);
    struct Node* head2 = createList(arr2, m);

    // ---- For demonstration ----
    // Connect second list to node with value 30 in first list
    struct Node* temp1 = head1;
    while(temp1 != NULL && temp1->data != 30)
        temp1 = temp1->next;

    if(temp1 != NULL) {
        struct Node* temp2 = head2;
        while(temp2->next != NULL)
            temp2 = temp2->next;
        temp2->next = temp1;  // Creating actual intersection
    }
    // ----------------------------

    struct Node* intersection = findIntersection(head1, head2);

    if(intersection != NULL)
        printf("%d\n", intersection->data);
    else
        printf("No Intersection\n");

    return 0;
}
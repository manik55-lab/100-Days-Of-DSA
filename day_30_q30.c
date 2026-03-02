#include <stdio.h>
#include <stdlib.h>

// Structure for polynomial node
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

int main() {
    int n, i;
    int coefficient, exponent;

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    // Input number of terms
    scanf("%d", &n);

    if (n <= 0) {
        return 0;
    }

    // Create polynomial linked list
    for (i = 0; i < n; i++) {
        scanf("%d %d", &coefficient, &exponent);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->coeff = coefficient;
        newNode->exp = exponent;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Display polynomial
    temp = head;
    while (temp != NULL) {
        if (temp->exp > 1) {
            printf("%dx^%d", temp->coeff, temp->exp);
        }
        else if (temp->exp == 1) {
            printf("%dx", temp->coeff);
        }
        else {
            printf("%d", temp->coeff);
        }

        if (temp->next != NULL) {
            printf(" + ");
        }

        temp = temp->next;
    }

    return 0;
}
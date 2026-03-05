#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push Operation
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

// Pop Operation
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("%d\n", stack[top--]);
}

// Display Operation
void display() {
    if (top == -1) {
        printf("Stack is Empty\n");
        return;
    }

    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        int choice, value;

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            default:
                printf("Invalid Operation\n");
        }
    }

    return 0;
}
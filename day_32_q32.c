#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    top--;
}

int main() {
    int n, m;

    // Number of elements to push
    scanf("%d", &n);

    // Push elements
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        push(value);
    }

    // Number of pops
    scanf("%d", &m);

    // Perform pop operations
    for (int i = 0; i < m; i++) {
        pop();
    }

    // Display remaining stack (top to bottom)
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}
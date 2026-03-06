#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node {
    int data;
    struct node* next;
};

struct node* top = NULL;

// Push function
void push(int x) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

// Pop function
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int main() {
    int a, b, result;
    char postfix[100];

    printf("Enter postfix expression: ");
    fgets(postfix, sizeof(postfix), stdin);

    int i = 0;
    while (postfix[i] != '\0') {

        // Skip spaces
        if (postfix[i] == ' ') {
            i++;
            continue;
        }

        // If digit push to stack
        if (isdigit(postfix[i])) {
            push(postfix[i] - '0');
        }

        // If operator
        else {
            b = pop();
            a = pop();

            switch(postfix[i]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }

            push(result);
        }

        i++;
    }

    printf("%d\n", pop());

    return 0;
}
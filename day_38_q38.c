#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int deque[MAX];
int front = -1;
int rear = -1;

int isEmpty() {
    return (front == -1);
}

int size() {
    if (isEmpty())
        return 0;
    return rear - front + 1;
}

void push_front(int value) {
    if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        printf("Overflow\n");
        return;
    } else {
        front--;
    }
    deque[front] = value;
}

void push_back(int value) {
    if (rear == MAX - 1) {
        printf("Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;

    deque[++rear] = value;
}

void pop_front() {
    if (isEmpty()) {
        printf("Underflow\n");
        return;
    }

    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

void pop_back() {
    if (isEmpty()) {
        printf("Underflow\n");
        return;
    }

    if (front == rear) {
        front = rear = -1;
    } else {
        rear--;
    }
}

int getFront() {
    if (isEmpty())
        return -1;
    return deque[front];
}

int getBack() {
    if (isEmpty())
        return -1;
    return deque[rear];
}

void display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }

    for (int i = front; i <= rear; i++) {
        printf("%d ", deque[i]);
    }
    printf("\n");
}

int main() {

    push_back(10);
    push_back(20);
    push_front(5);
    push_back(30);

    printf("Deque elements: ");
    display();

    printf("Front: %d\n", getFront());
    printf("Back: %d\n", getBack());

    pop_front();
    pop_back();

    printf("After deletions: ");
    display();

    printf("Size: %d\n", size());

    return 0;
}
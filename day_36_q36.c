#include <stdio.h>

#define SIZE 100

int queue[SIZE];
int front = 0, rear = -1, count = 0;

void enqueue(int value) {
    if(count == SIZE) {
        printf("Queue Overflow\n");
        return;
    }

    rear = (rear + 1) % SIZE;
    queue[rear] = value;
    count++;
}

void dequeue() {
    if(count == 0) {
        printf("Queue Underflow\n");
        return;
    }

    front = (front + 1) % SIZE;
    count--;
}

void display() {
    int i;
    for(i = 0; i < count; i++) {
        printf("%d ", queue[(front + i) % SIZE]);
    }
}

int main() {
    int n, m, x;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    scanf("%d", &m);

    for(int i = 0; i < m; i++) {
        dequeue();
    }

    display();

    return 0;
}
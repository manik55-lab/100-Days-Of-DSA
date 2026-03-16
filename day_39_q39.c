#include <stdio.h>
#include <string.h>

#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(int i) {
    while(i > 0) {
        int parent = (i - 1) / 2;
        if(heap[parent] <= heap[i])
            break;

        swap(&heap[parent], &heap[i]);
        i = parent;
    }
}

void heapifyDown(int i) {
    while(1) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest = i;

        if(left < size && heap[left] < heap[smallest])
            smallest = left;

        if(right < size && heap[right] < heap[smallest])
            smallest = right;

        if(smallest == i)
            break;

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
}

void insert(int x) {
    if(size == MAX) {
        return;
    }

    heap[size] = x;
    heapifyUp(size);
    size++;
}

void extractMin() {
    if(size == 0) {
        printf("-1\n");
        return;
    }

    printf("%d\n", heap[0]);

    heap[0] = heap[size - 1];
    size--;

    heapifyDown(0);
}

void peek() {
    if(size == 0) {
        printf("-1\n");
        return;
    }

    printf("%d\n", heap[0]);
}

int main() {
    int N;
    char op[20];
    int x;

    scanf("%d", &N);

    for(int i = 0; i < N; i++) {

        scanf("%s", op);

        if(strcmp(op, "insert") == 0) {
            scanf("%d", &x);
            insert(x);
        }
        else if(strcmp(op, "extractMin") == 0) {
            extractMin();
        }
        else if(strcmp(op, "peek") == 0) {
            peek();
        }
    }

    return 0;
}
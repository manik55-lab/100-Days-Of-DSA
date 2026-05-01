#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Meeting;

// Compare meetings by start time
int cmp(const void *a, const void *b) {
    return ((Meeting*)a)->start - ((Meeting*)b)->start;
}

// Min Heap functions
void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

void heapifyUp(int heap[], int i) {
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(int heap[], int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}

// Insert into heap
void push(int heap[], int *size, int value) {
    heap[*size] = value;
    heapifyUp(heap, *size);
    (*size)++;
}

// Remove min (root)
void pop(int heap[], int *size) {
    heap[0] = heap[*size - 1];
    (*size)--;
    heapifyDown(heap, *size, 0);
}

int main() {
    int n;
    scanf("%d", &n);

    Meeting arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    // Step 1: Sort by start time
    qsort(arr, n, sizeof(Meeting), cmp);

    int heap[n];
    int size = 0;

    // Add first meeting
    push(heap, &size, arr[0].end);

    // Process remaining meetings
    for (int i = 1; i < n; i++) {
        // If room is free
        if (arr[i].start >= heap[0]) {
            pop(heap, &size);
        }

        push(heap, &size, arr[i].end);
    }

    printf("%d\n", size);

    return 0;
}
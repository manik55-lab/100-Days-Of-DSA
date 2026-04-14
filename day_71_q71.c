#include <stdio.h>
#include <string.h>

#define SIZE 100

int table[SIZE];
int m;

// Initialize table
void init() {
    for (int i = 0; i < m; i++) {
        table[i] = -1; // -1 means empty
    }
}

// Insert using quadratic probing
void insert(int key) {
    int h = key % m;

    for (int i = 0; i < m; i++) {
        int idx = (h + i * i) % m;

        if (table[idx] == -1) {
            table[idx] = key;
            return;
        }
    }
    // Table full (optional handling)
}

// Search using quadratic probing
void search(int key) {
    int h = key % m;

    for (int i = 0; i < m; i++) {
        int idx = (h + i * i) % m;

        if (table[idx] == key) {
            printf("FOUND\n");
            return;
        }

        if (table[idx] == -1) {
            break; // stop if empty slot found
        }
    }
    printf("NOT FOUND\n");
}

// Driver
int main() {
    int q;
    scanf("%d", &m); // table size
    scanf("%d", &q); // number of operations

    init();

    while (q--) {
        char op[10];
        int key;

        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key);
        } else if (strcmp(op, "SEARCH") == 0) {
            search(key);
        }
    }

    return 0;
}
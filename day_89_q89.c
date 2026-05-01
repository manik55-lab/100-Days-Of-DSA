#include <stdio.h>

// Function to check if allocation is possible
int isPossible(int books[], int n, int m, int maxPages) {
    int students = 1;
    int pages = 0;

    for (int i = 0; i < n; i++) {
        // If a single book exceeds maxPages → impossible
        if (books[i] > maxPages)
            return 0;

        if (pages + books[i] <= maxPages) {
            pages += books[i];
        } else {
            students++;
            pages = books[i];
        }

        if (students > m)
            return 0;
    }

    return 1;
}

// Function to find minimum possible maximum pages
int allocateBooks(int books[], int n, int m) {
    int sum = 0, max = 0;

    for (int i = 0; i < n; i++) {
        sum += books[i];
        if (books[i] > max)
            max = books[i];
    }

    int low = max;
    int high = sum;
    int result = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(books, n, m, mid)) {
            result = mid;
            high = mid - 1; // try smaller value
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    int books[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &books[i]);
    }

    printf("%d\n", allocateBooks(books, n, m));

    return 0;
}
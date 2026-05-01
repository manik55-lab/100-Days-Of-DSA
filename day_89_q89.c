#include <stdio.h>
#include <stdlib.h>

// Comparator for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to check if we can place k cows with at least 'dist' distance
int canPlace(int stalls[], int n, int k, int dist) {
    int count = 1; // first cow placed at first stall
    int last_pos = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - last_pos >= dist) {
            count++;
            last_pos = stalls[i];
        }
        if (count >= k)
            return 1; // true
    }
    return 0; // false
}

// Main function to find maximum minimum distance
int aggressiveCows(int stalls[], int n, int k) {
    qsort(stalls, n, sizeof(int), compare);

    int low = 0;
    int high = stalls[n - 1] - stalls[0];
    int ans = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canPlace(stalls, n, k, mid)) {
            ans = mid;
            low = mid + 1; // try larger distance
        } else {
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    int n, k;

    scanf("%d %d", &n, &k);

    int stalls[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }

    int result = aggressiveCows(stalls, n, k);
    printf("%d\n", result);

    return 0;
}
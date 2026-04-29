#include <stdio.h>
#include <stdlib.h>

// Comparator for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to check if cows can be placed
int canPlaceCows(int stalls[], int n, int k, int minDist) {
    int count = 1;  // first cow at first stall
    int lastPos = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastPos >= minDist) {
            count++;
            lastPos = stalls[i];
        }
        if (count >= k)
            return 1;  // possible
    }
    return 0;  // not possible
}

int aggressiveCows(int stalls[], int n, int k) {
    // Sort stalls
    qsort(stalls, n, sizeof(int), compare);

    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int ans = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canPlaceCows(stalls, n, k, mid)) {
            ans = mid;
            low = mid + 1;  // try bigger distance
        } else {
            high = mid - 1; // reduce distance
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
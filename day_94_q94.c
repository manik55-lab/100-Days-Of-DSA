#include <stdio.h>
#include <stdlib.h>

// Counting Sort (stable, for non-negative integers)
void countingSort(int arr[], int n) {
    // 1. Find maximum value
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    // 2. Create frequency array
    int *count = (int *)calloc(max + 1, sizeof(int));

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // 3. Compute prefix sums
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // 4. Build output array (IMPORTANT: traverse from right for stability)
    int *output = (int *)malloc(n * sizeof(int));

    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // 5. Copy back to original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(count);
    free(output);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    countingSort(arr, n);

    // Print sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
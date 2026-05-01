#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Interval;

// Sort by start time
int cmp(const void *a, const void *b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

int main() {
    int n;
    scanf("%d", &n);

    Interval arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    // Step 1: Sort intervals
    qsort(arr, n, sizeof(Interval), cmp);

    // Step 2: Merge intervals
    Interval result[n];
    int index = 0;

    result[0] = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i].start <= result[index].end) {
            // Merge
            if (arr[i].end > result[index].end) {
                result[index].end = arr[i].end;
            }
        } else {
            // No overlap → new interval
            index++;
            result[index] = arr[i];
        }
    }

    // Step 3: Print result
    for (int i = 0; i <= index; i++) {
        printf("%d %d\n", result[i].start, result[i].end);
    }

    return 0;
}
#include <stdio.h>

// Check if we can paint within maxTime using k painters
int isPossible(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int time = 0;

    for (int i = 0; i < n; i++) {
        // If a single board is larger than maxTime → impossible
        if (boards[i] > maxTime)
            return 0;

        if (time + boards[i] <= maxTime) {
            time += boards[i];
        } else {
            painters++;
            time = boards[i];
        }

        if (painters > k)
            return 0;
    }

    return 1;
}

// Function to find minimum time
int minTime(int boards[], int n, int k) {
    int sum = 0, max = 0;

    for (int i = 0; i < n; i++) {
        sum += boards[i];
        if (boards[i] > max)
            max = boards[i];
    }

    int low = max;
    int high = sum;
    int result = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(boards, n, k, mid)) {
            result = mid;
            high = mid - 1; // try smaller time
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    int n, k;

    scanf("%d %d", &n, &k);

    int boards[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
    }

    printf("%d\n", minTime(boards, n, k));

    return 0;
}
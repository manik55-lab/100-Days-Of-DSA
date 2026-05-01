#include <stdio.h>
#include <stdlib.h>

// Merge function with inversion count
long long merge(int arr[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    int size = right - left + 1;

    int temp[size];
    long long inv_count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1); // key step
        }
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    // Copy back
    for (i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }

    return inv_count;
}

// Merge Sort with inversion count
long long mergeSort(int arr[], int left, int right) {
    long long inv_count = 0;

    if (left < right) {
        int mid = (left + right) / 2;

        inv_count += mergeSort(arr, left, mid);
        inv_count += mergeSort(arr, mid + 1, right);
        inv_count += merge(arr, left, mid, right);
    }

    return inv_count;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long inversions = mergeSort(arr, 0, n - 1);

    printf("%lld\n", inversions);

    return 0;
}
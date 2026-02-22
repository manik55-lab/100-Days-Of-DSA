#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    long long prefix = 0;
    long long count = 0;

    // Using large range for hashing (since constraints not given)
    int size = 200001;
    long long *freq = (long long*)calloc(size, sizeof(long long));

    // Shift index to handle negative sums
    int offset = 100000;

    freq[offset] = 1;  // prefix sum 0 occurs once initially

    for(int i = 0; i < n; i++) {
        prefix += arr[i];

        if(prefix + offset >= 0 && prefix + offset < size) {
            count += freq[prefix + offset];
            freq[prefix + offset]++;
        }
    }

    printf("%lld", count);

    free(freq);
    return 0;
}

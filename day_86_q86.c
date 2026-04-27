#include <stdio.h>

int intSqrt(int n) {
    if (n == 0 || n == 1) return n;

    int left = 0, right = n, ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Use long long to avoid overflow
        long long sq = (long long)mid * mid;

        if (sq == n) {
            return mid;        // perfect square
        }
        else if (sq < n) {
            ans = mid;         // store possible answer
            left = mid + 1;    // search right
        }
        else {
            right = mid - 1;   // search left
        }
    }

    return ans; // floor(sqrt(n))
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d\n", intSqrt(n));
    return 0;
}
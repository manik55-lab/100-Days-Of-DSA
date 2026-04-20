#include <iostream>
#include <unordered_map>
using namespace std;

int longestZeroSumSubarray(int arr[], int n) {
    unordered_map<int, int> mp;

    int prefixSum = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // Case 1: sum = 0 from start
        if (prefixSum == 0) {
            maxLen = i + 1;
        }

        // Case 2: prefix sum seen before
        if (mp.find(prefixSum) != mp.end()) {
            maxLen = max(maxLen, i - mp[prefixSum]);
        } else {
            mp[prefixSum] = i; // store first occurrence
        }
    }

    return maxLen;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << longestZeroSumSubarray(arr, n) << endl;

    return 0;
}
#include <stdio.h>

// Finds the maximum sum of a subarray of size k
int max_sum(int arr[], int n, int k) {
    // n must be greater than k
    if (n < k) {
        printf("Invalid operation\n");
        return -1;
    }

    // Compute sum of first window of size k
    int window_sum = 0;
    for (int i = 0; i < k; i++)
        window_sum += arr[i];

    // Compute sums of remaining windows by removing first element of previous
    // window and adding last element of the current window.
    int max_sum = window_sum;
    for (int i = k; i < n; i++) {
        window_sum += arr[i] - arr[i - k];
        max_sum = max_sum > window_sum ? max_sum : window_sum;
    }

    return max_sum;
}

// Driver code
int main() {
    int arr[] = {1, 4, 2, 10, 2, 3, 1, 0, 20};
    int k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Maximum sum of a subarray of size %d is %d\n", k, max_sum(arr, n, k));
    return 0;
}

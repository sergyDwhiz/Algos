#include <stdio.h>

// Use the Two pointer concept to find
// two elements in the array that add up to the target.
void two_sum(int numbers[], int length, int target) {
    int left = 0, right = length - 1;
    while (left < right) {
        int current_sum = numbers[left] + numbers[right];
        if (current_sum < target) {
            left++;
        } else if (current_sum > target) {
            right--;
        } else {
            printf("Indices: %d, %d\n", left + 1, right + 1);
            return;
        }
    }
    printf("No two sum solution\n"); // Null status
}

// Driver code
int main() {
    int numbers[] = {2, 7, 11, 15};
    int target = 9;
    int length = sizeof(numbers) / sizeof(numbers[0]);
    two_sum(numbers, length, target);
    return 0;
}
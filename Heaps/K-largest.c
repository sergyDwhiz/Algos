// Find the Kth largest element in an array
#include<stdio.h>
#include<stdlib.h>

// Comparison function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);  // Sort in descending order
}

// Find the kth largest element in an array
int findKthLargest(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), compare);  // Sort the array in descending order
    return nums[k-1];
}

int main() {
    int nums[] = {3,2,1,5,6,4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);  // Calculate the size of the array
    int k = 2;  // Define k
    printf("%d\n", findKthLargest(nums, numsSize, k));  // Print the kth largest element

    return 0;
}
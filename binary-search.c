// Binary search implementation 
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int binary_search(int arr[], int target, int left, int right);
void sort_list(int arr[], int arr_size);
void swap(int *a, int *b);
int main(void)
{
    int target;
    int arr[]= {3, 9, 16, 7, 8, 12, 6, 4, 2, 15};
    int arr_size= sizeof(arr)/sizeof(arr[0]);
    printf("Enter the target element\n");
    scanf("%d", &target);   // Element to be found
    sort_list(arr, arr_size);
   int result = binary_search(arr, target, 0, arr_size-1);
   (result == -1) ? printf("Target element not found") : printf("Target found, at position %d\n", result);
return 0;
}
int binary_search(int arr[], int target, int left, int right)
{
    if(left<=right)
    {

    int middle = (left +(right-left))/2;    // Split the array into two... famous recursive technique
    if(target == arr[middle])
    return middle;
    
    if(target > arr[middle])  // Search upper part of the array 
    return binary_search(arr,target, middle+1, right );
    
    if(target<arr[middle])  // Search lower part of the array 
    return binary_search(arr,target, left, middle-1);
    
    }
    return -1; // Target element not found in the array 
}
void sort_list(int arr[], int arr_size) // Sorting the unsorted list using the bubble sort sort approach
                                        // Binary sort works only on a sorted list. 
{
    int i, j;
    for(i=0;i<arr_size-1;i++)
    {
        for(j=0;j<arr_size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }       
        }
    }
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


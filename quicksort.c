// Quicksorting based on Divide and Conquer Strategy. 
#include<stdio.h>
#include<stdlib.h>
void quicksort(int arr[], int low, int high);
void print_array(int arr[], int arr_size);
int partition(int arr[], int low, int high);
void swpa(int* a, int* b);
int main(void)
{
    int arr[]={3, 7, 9, 0, 12, 15, 5};
    int i;
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    printf("Initial list: \n");
    for(i=0;i<arr_size;i++)
    {
        printf("%d\n", arr[i]);
    }
    printf("Sorted List: \n");
    quicksort(arr, 0, arr_size-1);
    print_array(arr, arr_size);
return 0;
}
void print_array(int arr[], int arr_size)
{
    int i;
    for(i=0;i<arr_size;i++)
    {
        printf("%d\n", arr[i]);
    }
}
void quicksort(int arr[], int low, int high)
{
   if(low < high)
   {
    int P = partition(arr, low, high);
    quicksort(arr, low, P-1);
    quicksort(arr, P+1, high);
   }

}
int partition(int arr[], int low, int high)
{
    int i=low-1;
    int j=low;
    int pivot=arr[high];   // pivot =last element in array
    for(j=low;j<=high-1;j++)
    {
        if(arr[j]<pivot)    // Comparing each smaller element to pivot. 
        {
            i++;
            swap(&arr[i], &arr[j]); 
        }
        swap(&arr[i+1], &arr[high]);
    }
    return (i+1);
}
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp; 
}
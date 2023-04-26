#include<stdio.h>
#include<stdlib.h>
void merge_sort(int arr[], int left, int right);
void print_array(int arr[], int array_size);
void print_array(int arr[], int array_size);
void merge(int arr[],int left, int mid, int right)
{
    int first_half = mid-left+1;
    int second_half = right-mid;
    int temp_Left[first_half],temp_right[second_half];
    int i, j, k;
    // Copy whole array into 2 separate arrays
    // Begining with Left side. 
    for(i=0;i<first_half;i++)
    {
        temp_Left[i]=arr[i+left];
    }
    // Then Right Side
    for(j=0;j<second_half;j++)
    {
        temp_right[j]= arr[mid+1+right];
    }
    k=left; // Initial index of Merged sorted array... starts merging
         // and copying from the left.
    // Now let's merge the Two separate arrays whilst sorting; 
    // Back into the original arr[left....right]

    i=0,j=0;
    while(i<first_half && j<second_half)
    {
        if(temp_Left[i]<=temp_right[j])
        {
        arr[k]=temp_Left[i];
        i++;
        }
        else 
        {
        arr[k]=temp_right[j];
        j++;
        }
     k++;
    }   
    // Copying the remaining elements of temp_Left[], if any. 
    // Begining with the First Half
    while(i<first_half)
    {
        arr[k]=temp_Left[i];
        i++;
        k++;
    }
    // Then second half
    while(j<second_half)
    {
        arr[k]=temp_right[j];
        j++;
        k++;
    }
}
int main(void)
{
    int i;
    int arr[]={4,7,2,9,3,6};
    int array_size = (sizeof(arr)/sizeof(arr[0]));
    printf("Unsorted list:\n");
    for(i=0;i<array_size;i++)
    {
        printf("%d\n", arr[i]);
    }
    merge_sort(arr, 0, array_size-1);
    printf("Sorted list: \n");
    print_array(arr, array_size);
return 0;
}
void merge_sort(int arr[], int left, int right)
{
    if(left<right)
    {
    int mid = (left +(right-1)/2);
    merge_sort(arr, left, mid);
    merge_sort(arr,mid+1, right);
    merge(arr, left, mid, right);

    }
}
void print_array(int arr[], int array_size)
{
    int i; 
    for(i=0;i<array_size;i++)
    {
        printf("%d", arr[i]);
        printf("\n");
    }
}

 
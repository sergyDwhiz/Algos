// Merge 2 arrays in sorted order
#include<stdio.h>
#include<stdlib.h>
// Merges two arrays into a third array
void merge_two(int A[], int size_one, int B[], int size_two);
// Sorts the merged array in chosen order
void sort_merge(int C[], int final_size)                   
// Swap value funtion.  
void swap(int a, int b)  
 int main(void)
{
    int i,j; 
    int size_one, size_two, final_size; 
    printf("Enter the size of the first array: \n");
    scanf("%d", &size_one);
    int A[size_one];
    printf("Enter the elements of the first array: \n");
    for(i=0;i<size_one;i++)
    {
        scanf("%d", &A[i]);
    }
    printf("Enter the size of the second array: \n");
    scanf("%d", &size_two);
    int B[size_two];
    printf("Enter the elements of the second array: \n");
    for(j=0;j<size_two;j++);
    {
        scanf("%d", &B[j]);
    }
    final_size = size_one + size_two;   

    printf("The merged array: \n");
    merge_two(A, size_one, B, size_two );
    printf("In sorted order:\n");
    sort_merge(C, final_size);
return 0;
}
void merge_two(int A[], int size_one, int B[], int size_two);
{
    int i,j;
    int C[final_size]= size_one +size_two;

    // Copying elements from First array into FINAL array: 
    for(i=0;i<size_one;i++)
    {
        C[i]= A[i];
    }
    // Copying elements from Second array to FINAL array: 
    for(i=0, j=size_one; i < size_two, j < final_size; i++, j++)
    {
        C[j]= B[i];
    }
    // Merging complete: 
    // Printing array: 
    for(i=0;i<final_size;i++)
    {
        printf("%d", C[i]);
        printf("\n");
    }
}

/*************************************** 
 *Sorting the merged array;            *
 * Preferably Selection sort technique.*
 ***************************************/

void sort_merge(int C[], int final_size);
{
    char command;
    printf("How do you want the array to be sorted?\n");
    printf("Press 1 for Ascending order
    ---     Press 2 for Descending order\n");
    scanf("%c", &command);
    int i,j;
   if(command == '1');
   {
    for(i=0; i<final_size; i++)
    {
    min=i;   
     /***********************************************************
      *Assign the least value initially to the first            *
      *position of the array; (min=A[0], since i starts from 0)*
      ***********************************************************/
    for(j=i+1; j<final_size; j++)
    {
        if(C[j]<C[min])    // Comparing in ascending order. 
        {
           min=j;
           swap(C[min], C[i]);
        }  
    }
    printf("%d", C[i]);
    printf("\n");
    }
}
if(command == '2');
    {
     for(i=0; i<final_size; i++)
    {
    min=i;
    for(j=i+1; j<final_size; j++);
    {
        if(C[j]>C[min])        // Comparing in descending order. 
        {
           min=j;
           swap(C[min], C[i]);
        }  
    }
    printf("%d", C[i]);
    printf("\n");
    }
    }
}

void swap(int a, int b);
{
    int temp=a;
    a=b;
    b=temp;
}


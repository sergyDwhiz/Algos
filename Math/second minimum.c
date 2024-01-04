// Takes an array arr and its size and returns the second minimum in the given array.
#include<stdio.h>

int SecondMininimum(int arr[], int size){
    int min, secondmin = 214748364; // Largest interger value
    for(int i = 0;i < size; i++ ){
    if(arr[i] < min){
        min = arr[i];
    }
    else if(arr[i] < secondmin)
    {
        secondmin = arr[i];
    }
    } 
return secondmin;
}

int main(){
    int arr[] = {1, 5, 7, 8, 5, 7, 9};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Second Min value: ", SecondMininimum(arr, size));
return 0;
}

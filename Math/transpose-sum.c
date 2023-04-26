// Sums the rows and columns in an array 
#include<stdio.h>
#define M 3
#define N 3

void sum_row(int A[M][N]);
void sum_col(int A[M][N]);
void populate (int A[M][N]);
void display(int A[M][N]);
int main()
{
    int A[M][N];
    populate(A);
    printf("Sum of rows: ");
    sum_row(A);
    printf("\nSum of columns: ");
    sum_col(A);
    return 0;    
}
void populate(int A[M][N])
{
    int i,j;
    for(i=0;i<N;i++)
    {
        printf(" Enter the values of the array");
        for(i=0;i<N;i++)
        {
            for(j=0;j<M;j++)
            {
                scanf("%d", &A[i][j]);
            }
        } 
    }
}
void sum_row(int A[M][N])
{
    int i,j, sum;
    for(i=0;i<N;i++)
    {
        sum=0;
        for(j=0;j<M;j++)
        {
            sum+= A[i][j];
        }
        printf("%d ", sum);
    }
}

void sum_col(int A[M][N])
{
    int i,j, sum;
    for(j=0;j<N;j++)
    {
        sum=0;
        for(i=0;i<M;i++)
        {
            sum+= A[i][j];
        }
        printf("%d ", sum);
    }
}


// This algorithm is used to avoid deadlock in a system by ensuring that a process can only get a
// resource if it leads to a safe state. A state is considered safe if there is at least one sequence of
// all processes that avoids deadlock.

#include <stdio.h>
#define MAX 10

int main()
{
    // Declare the matrices and arrays for allocation, maximum, available, need, flag and safe sequence
    int alloc[MAX][MAX], max[MAX][MAX], avail[MAX], need[MAX][MAX], flag[MAX], ss[MAX];
    int p, r, i, j, count=0;

    // Get the number of processes from the user
    printf("Enter the number of processes: ");
    scanf("%d", &p);

    // Get the number of resources from the user
    printf("Enter the number of resources: ");
    scanf("%d", &r);

    // Get the allocation matrix from the user
    printf("Enter allocation matrix\n");
    for(i=0; i<p; i++)
    {
        flag[i] = 0;
        for(j=0; j<r; j++)
            scanf("%d", &alloc[i][j]);
    }

    // Get the max matrix from the user
    printf("Enter max matrix\n");
    for(i=0; i<p; i++)
    {
        for(j=0; j<r; j++)
            scanf("%d", &max[i][j]);
    }

    // Get the available matrix from the user
    printf("Enter available matrix\n");
    for(i=0; i<r; i++)
        scanf("%d", &avail[i]);

    // Calculate the need matrix
    printf("Enter need matrix\n");
    for(i=0; i<p; i++)
    {
        for(j=0; j<r; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }

    // Main loop to find the safe sequence
    while(count < p)
    {
        for(i=0; i<p; i++)
        {
            if(flag[i] == 0)
            {
                int c=0;
                for(j=0; j<r; j++)
                {
                    // Check if need is less than or equal to available
                    if(need[i][j] <= avail[j])
                    {
                        c++;
                    }
                    // If need is less than or equal to available for all resources, allocate them
                    if(c == r)
                    {
                        for(j=0; j<r; j++)
                            avail[j] += alloc[i][j];
                        printf("\nProcess %d has been allocated resources", i);
                        ss[count++] = i;
                        flag[i] = 1;
                    }
                }
            }
        }
    }

    // Print the safe sequence
    printf("\nThe safe sequence is - ");
    for(i=0; i<p; i++)
        printf("\tP%d", ss[i]);

    return 0;
}


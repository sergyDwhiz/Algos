// Sums a range of number inclusive (1, N). 
#include<stdio.h>
#include<stdlib.h>
int 
Sumrange(int start, int end )
{
    int i;
    int sum = 0; 
    for(i=start; i<end; i++){
    sum+= i;
    }
   return sum; 
}
int 
main(int argc, char ** argv)
{
    int start;   // Initial value in range
    int end;    //One past value in range
if(argc !=3)
{
    fprintf(stderr, "Usage: %s\n start end ", argv[0] );
    return 1;
}
// Converts start and end positions from string to int .... from <stdlib>.. 
start = atoi(argv[1]);
end = atoi(argv[2]);
  /* Finally prints the Start, end value, and Sum Range*/
  printf("SumRange(%d, %d) = %d\n", start, end, Sumrange(start, end));
  return 0;
}  
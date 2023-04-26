//Computes the gcd of 2 numbers using the Euclidean algorithm.
#include<stdio.h>
int main()
{
    int a, b,i,gcd;
    printf("Enter any 2 intergers of your choice."\n);
    scanf("%d ,%d", &a,&b);
    for(i=1;i<=a;i++)
    if(i%a==0&&i%b==0){
        gcd=i;
        printf("the gcd of %d and %d is %d", a, b, gcd);
    }
    return 0;
}
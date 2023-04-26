#include<stdio.h>
int power(int num, int pow)
{
    if(num==0)
    {
        return "Invalid, please input another number";
    }
    else if (pow == 0)
    {
        return 1;    // n^0 ==1 
        
    }
    else if(pow ==1)
    {
        return num;
    }
    else if(pow%2==0)      // For all even numbers. 
    {
        int i = power(num, pow/2);   
        return i*i;                   // Return (x^2)^2... Exponential rule in Indices hahaha
    }
    else 
    return num* power(num, pow-1);
}
int main(void)
{
    int pow,num; 
    printf("Enter the number and it's power\n");
    scanf("%d %d", &num ,&pow);
    printf("%d to the power %d = %d\n", num, pow, power(num, pow));
    return 0;
}

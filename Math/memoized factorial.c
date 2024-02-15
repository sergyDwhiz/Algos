#include<stdio.h>
#define MAX 100
long long memo[MAX];

long long memo_facto(int n){
    if(n < 2) return 1;
    if (memo[n] != 0) return memo[n]; //Returns Stored result   
    return memo[n] = n * memo_facto(n-1); //Store result in memo array
}

int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Factorial of %d is %lld\n", n, memo_facto(n));
    return 0;
}


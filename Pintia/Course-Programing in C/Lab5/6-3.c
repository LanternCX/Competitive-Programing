#include <stdio.h>

int fib( int n );

int main()
{
    int n;

    scanf("%d", &n);
    printf("%d\n", fib(n));

    return 0;
}

int fib(int n){
    if(n <= 2) return 1;
    int dp[n + 1];
    dp[1] = dp[2] = 1;
    for(int i = 3; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
// int fib( int n ){
//     return n > 2 ? fib(n - 1) + fib(n - 2) : 1;
// }

/**
 * 我不能接受O(2^n)会TLE
 * dp[n] = dp[n-1] + dp[n-2]
 */
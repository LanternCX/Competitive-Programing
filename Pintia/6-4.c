#include <stdio.h>

int fib( int n );
void PrintFN( int m, int n );
    
int main()
{
    int m, n, t;

    scanf("%d %d %d", &m, &n, &t);
    printf("fib(%d) = %d\n", t, fib(t));
    PrintFN(m, n);

    return 0;
}

int fib( int n ){ return n > 2 ? fib(n - 1) + fib(n - 2) : 1; }

void PrintFN( int m, int n ){
    int tag = 0, tab[23] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, -1};
    for(int i = 0; i < 23; i++) if(tab[i] >= m && tab[i] <= n){ printf("%d%c", tab[i], tab[i + 1] >= m && tab[i + 1] <= n ? ' ' : '\n'); tag = 1;} else if (!tag && i == 22) printf("No Fibonacci number");
}
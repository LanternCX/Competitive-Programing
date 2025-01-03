#include <stdio.h>
#include <math.h>

int prime( int p );
int PrimeSum( int m, int n );
    
int main()
{
    int m, n, p;

    scanf("%d %d", &m, &n);
    printf("Sum of ( ");
    for( p=m; p<=n; p++ ) {
        if( prime(p) != 0 )
            printf("%d ", p);
    }
    printf(") = %d\n", PrimeSum(m, n));

    return 0;
}

const int N = 1e3;
int ps[(int) 1e3 + 5];
int tag = 0;
void ai(){
    for(int i = 0; i < N; i++){
        ps[i] = 1;
    }
    ps[0] = ps[1] = 0;
    for(int i = 2; i * i < N; i++){
        if(ps[i]){
            for(int j = i * i; j < N; j += i){
                ps[j] = 0;
            }
        }
    }
}
int prime(int p){
    if (p < 0) return 0;
    if(tag == 0){
        ai();
        tag = 1;
    }
    return ps[p];
}

int PrimeSum( int m, int n ){
    int res = 0;
    for(int i = m; i <= n; i++){
        if (prime(i)) {
            res += i;
        }
    }
    return res;
}
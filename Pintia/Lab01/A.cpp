#include <stdio.h>

int  fun( int a[],int n );
int main()
{
int a[10],i,n;
 scanf("%d",&n);
 for(i=0;i<n;i++)
 scanf("%d",&a[i]);
printf("%d",fun(a,n));
  return 0;

}
const int N = 1e6;
int  fun(int a[], int n){
    int cnt[N];
    for(int i = 0; i < N; i++){
        cnt[i] = 0;
    }
    for(int i = 0; i < n; i++){
        cnt[a[i]]++;
    }
    int idx = 0;
    for(int i = 0; i < N; i++){
        idx = cnt[idx] > cnt[i] ? idx : i;
    }
    return idx;
}
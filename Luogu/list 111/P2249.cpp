#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> arr(n + 2);
    arr[0] = arr[n + 1] = -1;
    for(int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
    }
    for(int i = 1; i <= m; i++){
        int q;
        scanf("%d", &q);
        int begin = 1;
        int end = n;
        int mid;
        while(begin < end){
            mid = begin + ((end - begin) / 2);
            if(arr[mid] >= q){
                end = mid;
            }else{
                begin = mid + 1;
            }
        }

        if(arr[begin] == q){
            printf("%d ", begin);
        }else {
            printf("-1 ");
        }
    }
    return 0;
}
/**
 * 1 3 3 3 5 7 9 11 13 15 15
 */
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "include/debug.cpp"
#else
#define debug(...) (void)(0)
#endif
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
void sol(){
    int n, k;
    cin >> n >> k;
    if(n == 1){
        cout << 1;
    }
    vector<int> arr(n);
    if(k % 2 == 1){
        for(int i = 0; i < n - 2; i++){
            cout << n << ' ';
        }
    }else{
        for(int i = 0; i < n - 2; i++){
            cout << n - 1 << ' ';
        }
    }
    cout << n << ' ';
    cout << n - 1;
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--){
        sol();
    }
    return 0;
}
/**
 * 首先肯定是每个点递增地传送最优
 * 因为每次传送距离都在缩短
 * 有点类似于二分？
 * 跳到每个二分点上可以趋近终点
 * 
 * 类似于树状数组
 * 
 * 
 */
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
    int n;
    cin >> n;
    vector<int> arr(n);
    int cnt = 0;
    ll sum = 0;
    for(auto &x : arr){
        cin >> x;
        cnt += x % 2 == 1;
        sum += x;
    }
    if(cnt == 0 || cnt == n){
        cout << *max_element(arr.begin(), arr.end());
    }else{
        cout << sum - cnt + 1;
    }
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
 * odd + even = odd
 * odd + odd = even
 * odd + odd + odd = odd
 * 
 * 4 3 
 * 
 * 操作会导致奇偶性转换
 * 
 * 4 3
 * 
 * 5 2
 * 
 * 6 1
 * 
 * 只要有一个偶数 
 * 所有奇数都可以操作到 1
 * 
 * 所以只需要剩下一个偶数
 * 也就是说直接先把偶数和奇数相加这样就剩下一个奇数
 * 
 * 然后处理奇数
 * 操作完就剩下偶数和 1
 * 
 * 偶数加上 1 变成奇数
 * 然后可以继续操作
 */
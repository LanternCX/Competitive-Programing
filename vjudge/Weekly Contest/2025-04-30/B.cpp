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
    vector<int> a(n);
    vector<int> cnt(2);
    for(auto &x : a){
        cin >> x;
        cnt[x % 2]++;
    }
    int ans = 0;
    for(int i = 1; i <= cnt[1]; i += 2){
        if(i > k){
            break;
        }
        if(k - i <= cnt[0]){
            ans = 1;
        }
    }
    cout << (ans ? "Yes\n" : "No\n");
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
 * 奇数个奇数和任意偶数
 * 
 * 先全部选偶数
 * 剩下最少的奇数个位置 看是否能全部填入奇数
 */
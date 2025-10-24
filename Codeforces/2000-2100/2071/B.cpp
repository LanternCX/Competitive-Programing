#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "include/debug.cpp"
#else
#define debug(...) (void)(0)
#endif
using ll = long long;
using ull = unsigned long long;
void sol(){
    ull n;
    cin >> n;
    auto is = [&](ull x){
        ull sq = sqrtl(x);
        if(sq * sq == x){
            return 1;
        }
        return 0;
    };
    if(is((1 + n) * n / 2)){
        cout << -1 << '\n';
        return;
    }
    vector<int> ans(n);
    ull sum = 0;
    for(int i = 0; i < n; i++){
        ans[i] = i + 1;
    }
    vector<int> temp = ans;
    for(int i = 0; i < n; i++){
        sum += ans[i];
        if(is(sum)){
            debug(i, sum);
            swap(temp[i], temp[i + 1]);
        }
    }
    // sum = 0;
    // for(int i = 0; i < n; i++){
    //     sum += temp[i];
    //     if(is(sum)){
    //         debug(1111);
    //     }
    // }
    for(auto x : temp){
        cout << x << ' ';
    }
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    // init();
    while (t--){
        sol();
    }
    return 0;
}
/**
 * 首先完全平方数可以枚举
 * 
 * 什么情况下不存在？
 * 
 * (1 + n) * n / 2
 */
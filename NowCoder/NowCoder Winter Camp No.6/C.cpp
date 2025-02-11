#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using pii = pair<ull, ull>;
vector<ull> pow2;
void init(){
    ull temp = 2;
    for(ull i = 1; i < 100; i++){
        temp <<= 1;
        pow2.push_back(temp);
        if(temp >= 1e18){
            break;
        }
    }
    // cout << pow2.size();
}
void sol(){
    ull k;
    cin >> k;
    auto it = upper_bound(pow2.begin(), pow2.end(), k * 2);
    ull cnt = it - pow2.begin();
    ull ans = (k + cnt) * 2;
    if(upper_bound(pow2.begin(), pow2.end(), ans) - pow2.begin() > cnt){
        ans += 2;
    }
    cout << ans << '\n';
}
int main(){
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    int t = 1;
    cin >> t;
    while(t--){
        sol();
    }
    return 0;
}
/**
 * 2 4 6 10 12 14
 * 
 * 如果是长度为1，那么所有偶数都会出现
 * 所以只需要剔除不会出现的偶数就好了
 * 
 * 什么情况下这些偶数不会出现？
 * 
 * 满足2^n的数不会出现
 */
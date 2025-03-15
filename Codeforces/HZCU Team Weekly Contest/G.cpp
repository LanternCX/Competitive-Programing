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
    vector<int> arr(n + 1);
    map<int, priority_queue<int>> mp;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        mp[arr[i] - i].push(arr[i]);
    }
    ll sum = 0;
    for(auto [w, idx] : mp){
        auto temp = idx;
        while(temp.size() >= 2){
            auto a = temp.top();
            temp.pop();
            auto b = temp.top();
            temp.pop();
            sum += max(a + b, 0);
        }
    }
    cout << sum << '\n'; 
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
 * i - j = a[i] - a[j]
 * i - a[i] = j - a[j]
 * 
 * 也就是说对于每一个 i 
 * i - a[i] 相等的点都可以存在边
 * 
 * 然后贪心就好了
 */
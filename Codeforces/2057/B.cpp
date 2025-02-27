#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
void sol(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    map<int, int> mp;
    set<int> st;
    for(auto &x : arr){
        cin >> x;
        mp[x]++;
        st.insert(x);
    }
    int ans = st.size();
    vector<int> cnt;
    for(auto [_, x] : mp){
        cnt.push_back(x);
    }
    sort(cnt.begin(), cnt.end());
    for(auto x : cnt){
        if(x <= k){
            ans--;
            k -= x;
        }
    }
    cout << max(ans, 1) << '\n';
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
 * 也就是说
 * 
 * 对于一段有着重复min的单调数组
 * f(1 1 1 2 3) = f(1 1 1) + f(2) + f(3)
 * 所以说 f(arr) 就是 to set 的 size
 * 
 * 那么替换的最优方案是什么？
 * 出现次数小的合并到次数多的里面
 * 
 */
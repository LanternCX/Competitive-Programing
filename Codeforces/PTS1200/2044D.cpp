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
const int N = 2e5;
void sol(){
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> cnt;
    vector<int> ans;
    for(auto &x : a){
        cin >> x;
        if(cnt[x] == 0){
            cnt[x]++;
            ans.push_back(x);
        }
    }
    for(auto x : ans){
        cout << x << ' ';
    }
    int mx = *max_element(a.begin(), a.end()) + 1;
    for(int i = 1; i <= n; i++){
        if(cnt[i] == 0){
            cout << i << ' ';
        }
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
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
#define int long long
struct Sieve{
    int n;
    vector<bool> p;

    Sieve(int n): n(n), p(n){
        for(int i = 0; i < n; i++){
            p[i] = true;
        }
        p[0] = p[1] = false;
        for(int i = 2; i * i < n; i++){
            if(p[i]){
                for(int j = i * i; j < n; j += i){
                    p[j] = false;
                }
            }
        }
    };
};
vector<int> p;
vector<int> pre;
void sol(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x : a){
        cin >> x;
    }
    sort(a.begin(), a.end(), greater<int>());
    for(int i = 1; i < n; i++){
        a[i] += a[i - 1];
    }

    int ans = n;
    for(int i = 1; i < n; i++){
        if(a[i] >= pre[i]){
            ans = min(ans, n - i);
        }
    }
    cout << ans - 1 << '\n';
}
void init(){
    const int N = 1e7;
    Sieve sieve(N);
    for(int i = 0; i < N; i++){
        if(sieve.p[i]){
            p.push_back(i);
        }
    }
    pre.resize(p.size());
    pre[0] = p[0];
    for(int i = 1; i < p.size(); i++){
        pre[i] = pre[i - 1] + p[i];
    }
}
signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    init();
    while (t--){
        sol();
    }
    return 0;
}
/**
 * 构造质数序列
 * 
 * 用前缀和搜索
 */
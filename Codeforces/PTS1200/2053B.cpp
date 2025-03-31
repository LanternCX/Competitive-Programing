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
    vector<pii> arr(n);
    int mx = 0;
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        arr[i] = {l, r};
        mx = max(mx, r);
    }
    mx *= 2;
    vector<int> cnt(mx);
    vector<int> idx(mx);
    vector<int> ans(n);
    for(int i = 0; i < n; i++){
        auto [l, r] = arr[i];
        if(l == r && cnt[l] == 0){
            cnt[l] = 1;
            ans[i] = 1;
            idx[l] = i;
        }else if(l == r && cnt[l] == 1){
            ans[i] = 0;
            ans[idx[l]] = 0;
        }
    }

    for(int i = 1; i <= mx / 2; i++){
        cnt[i] += cnt[i - 1];
    }

    for(int i = 0; i < n; i++){
        auto [l, r] = arr[i];
        if(r - l + 1 > cnt[r] - cnt[l - 1]){
            ans[i] = 1;
        }
    }
    for(auto x : ans){
        cout << x;
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
 * 1 3
 * 意味着这个位置可以有 3 的宽容度
 * 是不是如果这个区间长度为 2 实际上就一定存在
 * 如果这个区间长度为 1 就进行特判
 * 好像不对
 * 
 * 好像确实
 */
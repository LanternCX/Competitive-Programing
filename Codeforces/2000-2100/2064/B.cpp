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
    vector<ll> arr(n);
    map<int, int> mp;
    for(auto &x : arr){
        cin >> x;
        mp[x]++;
    }
    for(auto &x : arr){
        x = mp[x];
    }
    debug(arr);
    pii ans = {0, 0};
    vector<int> cnt(n);
    cnt[0] = arr[0] == 1;
    for(int i = 1; i < n; i++){
        if(arr[i] == 1){
            cnt[i] = cnt[i - 1] + 1;
        }
    }
    int mx = *max_element(cnt.begin(), cnt.end());

    if(mx == 0){
        cout << "0\n";
        return;
    }

    for(int i = 0; i < n; i++){
        if(cnt[i] == mx){
            cout << i - mx + 2 << ' ' << i + 1 << "\n";
            return;
        }
    }
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
 * sc = size - num
 * sum[l , r] = sum[r] - sum[l - 1];
 */
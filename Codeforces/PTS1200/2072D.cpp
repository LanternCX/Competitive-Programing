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

void sol(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &x : arr){
        cin >> x;
    }

    pii ans = {0, 0};
    int mx = 0;
    for(int l = 0; l < n; l++){
        vector<int> cnt(2);
        for(int r = l + 1; r < n; r++){
            if(arr[l] == arr[r]){
                continue;
            }
            cnt[arr[l] > arr[r]]++;
            int det = cnt[1 > 0] - cnt[1 < 0];
            if(det > mx){
                ans = {l, r};
                mx = det;
            }
        }
    }
    cout << ans.first + 1 << ' ' << ans.second + 1 << '\n';
}
signed main(){
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--){ 
        sol();
    }
    return 0;
}
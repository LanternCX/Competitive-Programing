#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<ll> arr(n + 1);
    ll l = 0, r = 0;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        arr[i] *= 1e4;
        r = max(arr[i], r);
    }
    while(l < r){
        int mid = (l + r) / 2;
        
        vector<ll> pre(n + 1);
        for(int i = 1; i <= n; i++){
            pre[i] = pre[i - 1] + (arr[i] - mid);
        }
        ll mn = LONG_LONG_MAX;
        bool is = 0;
        for(int i = m; i <= n; i++){
            mn = min(mn, pre[i - m]);
            if(pre[i] >= mn){
                is = 1;
            }
        }

        if(is){
            l = mid + 1;
        }else {
            r = mid - 1;
        }
    }
    cout << (l + r) / 2 / 10;
    return 0;
}
/**
 * sum(l, r) = pre[r] - pre[l - 1];
 * avg(l, r) = sum(l, r) / n;
 * mid ? 
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> arr(n);
    ll sum = 0;
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    if(sum != n * (n + 1) / 2){
        cout << -1;
        return 0;
    }
    sort(arr.begin(), arr.end());
    ll cnt = 0;
    for(ll i = 0; i < n; i++){
        cnt += abs(arr[i] - (i + 1));
    }
    cout << cnt / 2;
    // vector<int> temp(n);
    // for(int i = 0; i < n; i++){
    //     temp[i] = i + 1;
    // }
    // vector<int> vis(n + 1);
    // vector<int> from;
    // for(int i = 0; i < n; i++){
    //     auto it = lower_bound(temp.begin(), temp.end(), arr[i]);
    //     if(it != temp.end() && *it == arr[i] && vis[arr[i]] == 0){
    //        vis[arr[i]] = 1;
    //     } else {
    //         from.push_back(arr[i]);
    //     }
    // }
    // vector<int> to;
    // for(int i = 1; i <= n; i++){
    //     if(!vis[i]){
    //         to.push_back(i);
    //     }
    // }
    // ll de = 0, in = 0;
    // for(int i = 0; i < from.size(); i++){
    //     if(from[i] < to[i]){
    //         de += abs(from[i] - to[i]);
    //     }else {
    //         in += abs(from[i] - to[i]);
    //     }
    // }
    // cout << max(de, in);
    return 0;
}
/**
 * 1 + 2 + ... + n = (1 + n) * n / 2
 * 
 * 0 3 4 3
 * 1 2 3 4
 * 
 * 0 2 4 4
 * 1 2 3 4
 * 
 * 10 0 0 0
 * 1 2 3 4
 * 
 * 4
 * 0 0 5 5
 * 1 2 3 4
 * 3
 * 
 * 2 3 4 5
 */
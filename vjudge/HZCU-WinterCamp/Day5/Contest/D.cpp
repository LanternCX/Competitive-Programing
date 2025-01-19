#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// ll f(ll x){
//     if(x == 0){
//         return x;
//     }
//     if(x % 2 == 0){
//         return f(x / 2);
//     }
//     if(x % 2 == 1){
//         return f(x / 2) + 1;
//     }
//     return 0;
// }
ll f(ll x){
    ll cnt = 0;
    while(x > 0){
        cnt += x % 2;
        x >>= 1;
    }
    return cnt;
}
int main(){
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<ll> ans(1e4);
    for(ll i = 0; i < n; i++){
        ans[f(arr[i])]++;
    }
    ll cnt = 0;
    for(ll x : ans){
        if(x > 0){
            cnt += x * (x - 1) / 2;
        }
    }
    cout << cnt;
    // vector<int> arr1(50);
    // int cnt = 0;
    // for(ll i = 0; i < 30; i++){
    //     arr1[i] = f(i);
    // }
    // vector<int> arr2(50);
    // for(int i = 0; i < 30; i++){
    //     int cnt = 0;
    //     int temp = i;
    //     while(temp > 0){
    //         cnt += temp % 2;
    //         temp >>= 1;
    //     }
    //     arr2[i] = cnt;
    // }
    // for(int i = 0; i < 30; i++){
    //     cout << arr1[i] << ' ' << arr2[i] << '\n';
    // }

    return 0;
}
/**
 * C2n = n! / (n - 2)! (2!) = n! / (n - 2)! * 2 = (n * n - 1) / 2
 */
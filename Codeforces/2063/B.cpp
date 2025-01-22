#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void sol(){
    ll n, l, r;
    cin >> n >> l >> r;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
    }
    ll sum = 0;
    vector<ll> temp(arr.begin(), arr.begin() + r);
    sort(temp.begin(), temp.end());
    for(ll i = 0; i <= r - l; i++){
        sum += temp[i];
    }
    ll sum1 = 0;
    vector<ll> temp1(arr.begin() + l - 1, arr.end());
    sort(temp1.begin(), temp1.end());
    for(ll i = 0; i <= r - l; i++){
        sum1 += temp1[i];
    }
    cout << min(sum, sum1) << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        sol();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int is(ll n){
    ll temp = n;
    vector<int> arr(n);
    while(n != 0){
        arr.push_back(n % 10);
        n /= 10;
    }
    ll sum = 0;
    for(int i : arr){
        sum += pow(i, 3);
    }
    if(sum == temp) cout << sum << ' ';
    return sum == temp;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll l, r;
    cin >> l >> r;
    ll ans = r - l + 1;
    for(ll i = l; i <= min(r, ll(1000)); i++){
        if(i == 1 || i == 153 || i == 370 || i == 371 || i == 407){
            ans--;
        }
    }
    cout << ans;
    return 0;
}
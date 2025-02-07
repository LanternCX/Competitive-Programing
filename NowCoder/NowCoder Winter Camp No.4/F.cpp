#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void sol(){
    ll n, p, k;
    cin >> n >> p >> k;
    vector<ll> arr(n);
    for(auto& x : arr){
        cin >> x;
        x %= p;
    }
    auto f = [&](ll i, ll j) -> ll {
      return (arr[i] + arr[j]) % p;
    };
    sort(arr.begin(), arr.end());

    auto work = [&](ll x) -> ll {
        ll res = 0;
        for(ll i = 0, j = n - 1; i < n; i++){
            while(j >= 0 && arr[i] + arr[j] >= x){
                j--;
            }
            if(j > i){
                res += n - 1 - j;
            }else{
                res += n - 1 - i;
            }
        }
        return res;
    };
    ll l = 0, r = p - 1;
    while(l <= r){
        ll mid = (l + r) / 2;
        ll temp = work(mid) - work(p) + work(p + mid);
        if(temp >= k){
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }

    vector<ll> ans;
    for(ll i = 0, temp1 = n - 1, temp2 = n - 1; i < n; i ++){
        while(temp1 >= 0 && arr[i] + arr[temp1] >= l){
            temp1--;
        }
        while(temp2 >= 0 && arr[i] + arr[temp2] >= l + p){ 
            temp2--;
        }

        for(ll j = max(i, temp1) + 1; j < n; j++){
            if(arr[i] + arr[j] >= p){
                break;
            }
            ans.push_back(f(i, j));
        }
        for(ll j = max(i, temp2) + 1; j < n; j++){
            ans.push_back(f(i, j));
        }
    }
     
    while(ans.size() < k){
        ans.push_back(r);
    }
    sort(ans.begin(), ans.end(),greater<ll>());

    for(auto x : ans){
        cout << x << ' ';
    }
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    while(t--){
        sol();
    }
    return 0;
}
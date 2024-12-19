#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void sol(){
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    ll s = 0;
    for(int i = 0; i < n; i++){
        s ^= arr[i];
    }

    if(n % 2 == 0){
        if(k % 2 == 0){
            for(ll i : arr){
                cout << i << ' ';
            }
        }
        if(k % 2 == 1){
            for(ll i : arr){
                cout << (i ^ s) << ' ';
            }
        }
    }

    if(n % 2 == 1){
        for(ll i : arr){
            cout << (i ^ s) << ' ';
        }
    }
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        sol();
    }
    return 0;
}
/**
 * 
 * // even
 * 1 2 3 4
 * 
 * 1 ^ 2 ^ 3 ^ 4 = 4
 * 
 * 4 ^ 1 = 5
 * 4 ^ 2 = 6 
 * 4 ^ 3 = 7
 * 4 ^ 4 = 0
 * 
 * 5 ^ 6 ^ 7 ^ 0 = 4 ^ 1 ^ 4 ^ 2 ^ 4 ^ 3 ^ 4 ^ 4 = 1 ^ 2 ^ 3 ^ 4 = 4
 * 
 * // odd
 * 2 3 4
 * 2 ^ 3 ^ 4 = 5
 * 
 * 5 ^ 2 ^ 5 ^ 3 ^ 5 ^ 4 = 5 ^ 5 = 0
 */
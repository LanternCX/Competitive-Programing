#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
void sol(map<ll, int> mp){
    ll n, m;
    cin >> n >> m;
    int ans = 1;
    if(m == 1 && n != 0){
        cout << "Yes\n";
        return;
    }
    if(m == n){
        cout << "Yes\n";
        return;
    }
    if(n == 0){
        cout << "No\n";
        return;
    }
    if(mp[m]){
        ans = 0;
    }
    cout << (ans ? "Yes\n" : "No\n");
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    map<ll, int> mp;
    ll temp = 1;
    while(temp <= 1e9){
        mp[temp - 1]++;
        temp *= 2;
    }
    int t = 1;
    cin >> t;
    while(t--){
        sol(mp);
    }
    return 0;
}
/**
 * x * x
 * 
 * 
 * 
 * 
 */
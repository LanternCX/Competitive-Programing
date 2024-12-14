#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool isLoop(string s){
    ll res = 1;
    ll len = s.length();
    for(ll i = 0; i < len; i++){
        if(s[i] != s[len - i - 1]){
            res = 0;
        }
    }
    return res;
}
void sol(){
    ll n;
    cin >> n;
    vector<ll> c(n);
    for(ll i = 0; i < n; i++){
        cin >> c[i];
    }
    string s;
    cin >> s;
    ll t = 0;
    for(ll i = 1; i <= n; i++){
        string temp = s.substr(0, i);
        if(isLoop(temp)){
            t++;
        }
    }
    ll d1 = (abs(1 - n) - t) * (abs(1 - n) - t);
    ll d2 = c[n - 1] + 2 * t * n;
    cout << d2 + d1 + 1 << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    while(n--){
        sol();
    }
    // cout << isLoop("1");
    return 0;
}
/**
 * 1 2
 * 5 2
 * z y
 * dis = 1
 * (dis - Tu) ^ 2 = 0
 * Cv + 2 ∗ Tu ∗ v = 2 + 2 * 1 * 2 = 6
 * Tu = 1
 * 
 * 1 2
 * 5 2
 * z z
 * dis = 1
 * (dis - Tu) ^ 2 = 1
 * Cv + 2 ∗ Tu ∗ v = 2 + 2 * 2 * 2 = 11
 * Tu = 2
 */
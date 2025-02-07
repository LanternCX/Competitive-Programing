#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int p = 1e9 + 7;
const int N = 2e5;
array<ll, N + 1> pow2 = {1};
void sol(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    if(n == 1){
        if(s[0]=='?'){
            cout << 2 << '\n';
        }else {
            cout << 1 << '\n';
        }
        return;
    }
    
    
    int cnt = 0;
    for(auto ch : s){
        cnt += ch == '?';
    }
    cnt -= s[0] == '?';
    cnt -= s[n - 1] == '?';

    array<int, 2> arr = {0, 0};

    if(s[0] == '?' || s[n - 1] == '?'){
        if(s[0] == '?' && s[n - 1] == '?'){
            arr[0] = 2, arr[1] = 2;
        }else {
            arr[0] = 1, arr[1] = 1;
        }
    }else if(s[0] == s[n - 1]){
        arr[0] = 1, arr[1] = 0;
    }else{
        arr[0] = 0, arr[1] = 1;
    }

    ll ans = 0;
    ans += (pow2[cnt] * (n - 2) * arr[0]) % p;
    ans += (pow2[cnt] * 2 * arr[1]) % p;
    ans %= p;
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    
    for(int i = 1; i <= N; i++){
        pow2[i] = pow2[i - 1] * 2 % p;
    }
    while(t--){
        sol();
    }
    return 0;
}
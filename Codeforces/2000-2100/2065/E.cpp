#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int gcd(int a, int b){return a % b == 0 ? b : gcd(b, a % b);}
void sol(){
    int n, m, k;
    cin >> n >> m >> k;
    // string s;
    // cin >> s;
    // auto val = [&](string s){
    //     vector<ll> cnt(2);
    //     for(auto ch : s){
    //         cnt[ch - '0']++;
    //     }
    //     return abs(cnt[0] - cnt[1]);
    // };

    // auto work = [&](string s) {
    //     ll res = 0;
    //     for(int i = 0; i < s.length(); i++){
    //         for(int j = 1; j <= s.length() - i; j++){
    //             string temp = s.substr(i, j);
    //             cout << temp << '\n';
    //             res = max(res, val(temp));
    //         }
    //     }
    //     return res;
    // };
    int tag = 1;
    if(n < m){
        tag = 0;
        swap(n, m);
    }
    // case 1
    string ans(k, '0');
    int a = n, b = m;
    a -= k;
    if(a < 0){
        cout << -1;
        return;
    }
    int g = gcd(a, b);
    while(a > 0 && b > 0){
        ans += string(b / g, '1');
        ans += string(a / g, '0');
        b -= b / g;
        a -= a / g;
        // cout << a << ' ' << b << '\n';
    }
    if(a != 0 || b != 0){
        cout << -1;
    }else {
        if(!tag){
            for(auto& ch : ans){
                if(ch == '0'){
                    ch = '1';
                }else {
                    ch = '0';
                }
            }
        }
        cout << ans << '\n';
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        sol();
    }
    return 0;
}
/**
 * 
 * 
 * x - y = -(y - x)
 * 
 * max(x - y, y - x) == abs(x - y)
 * 0 和 1 的个数的差值
 * 
 * 4 3 2 
 * 
 * 
 * 
 */
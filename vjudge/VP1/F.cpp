#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, t;
    cin >> n >> t;
    string s;
    cin >> s;
    auto work = [&](string s){
        string res;
        res.push_back(s[0]);
        for(int i = 1; i < s.length(); i++){
            res.push_back(((s[i] - '0') ^ (s[i - 1] - '0')) + '0');
        }
        return res;
    };
    string ans = s;
    vector<string> arr;
    ll p = 1;
    while(p < n){
        p <<= 1;
    }
    t %= p;
    for(int i = 0; i < t; i++){
        ans = work(ans);
    }
    cout << ans;
    return 0;
}
/**
 * 2 ^ n ?
 * 
 * 11010
10110
11101
10011
11010
10111
11100
10010
11011
10110
11101
10011
11010
10111
11100
10010
11011
10110
11101
10011
11010
10111
11100
10010
11011
10110
11101
10011
11010
10111
11100
10010
10010
 * 
 */
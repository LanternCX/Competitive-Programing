#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "include/debug.cpp"
#else
#define debug(...) (void)(0)
#endif
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
void sol(){
    string a, b;
    cin >> a >> b;
    set<string> mp;
    vector<string> pre = {"k", "g", "s", "z", "t", "n", "h", "b", "p", "m", "r"};
    vector<string> suf = {"a", "i", "u", "e", "o", "ya", "yu", "yo"};
    for(auto x : pre){
        for(auto y : suf){
            mp.insert(x + y);
        }
    }
    vector<string> ext = {"da", "de", "do", "wa", "nn"};
    for(auto s : ext){
        mp.insert(s);
    }
    for(auto s : suf){
        mp.insert(s);
    }

    auto work = [&](string s){
        int ans = 0;
        int n = s.length();
        int idx = 0;
        while(idx < n){
            string temp = s.substr(idx, 2);
            if(temp == "pp" || temp == "tt" || temp == "kk" || temp == "ss"){
                ans++;
                idx++;
                continue;
            }
            for(int len = 3; len>= 1; len--){
                if(mp.count(s.substr(idx, len))){
                    idx += len;
                    ans++;
                    break;
                }
            }
        }
        return ans;
    };
    cout << work(a) << ' ' << work(b) << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--){
        debug(t);
        sol();
    }
    return 0;
}
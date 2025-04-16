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
#define int long long
void sol(){
    string s;
    cin >> s;
    int sum = 0;
    vector<int> cnt(10);
    for(auto ch : s){
        sum += ch - '0';
        cnt[ch - '0']++;
    }
    if(sum % 9 == 0){
        cout << "YES\n";
        return;
    }
    cnt[2] = min(cnt[2], 10LL);
    cnt[3] = min(cnt[3], 10LL);
    for(int i = 0; i <= cnt[2]; i++){
        for(int j = 0; j <= cnt[3]; j++){
            if((sum + i * 2 + j * 6) % 9 == 0){
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}
signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--){
        sol();
    }
    return 0;
}
/**
 * 2 -> 4
 * 3 -> 9
 */
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
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vector<vector<int>> cnt(2, vector<int>(2));
    for(int i = 0; i < n; i += 2){
        cnt[0][0] += a[i] == '0';
        cnt[1][0] += b[i] == '0'; 
    }
    for(int i = 1; i < n; i += 2){
        cnt[0][1] += a[i] == '0';
        cnt[1][1] += b[i] == '0';
    }
    debug(cnt);
    if(cnt[0][0] + cnt[1][1] >= (n + 1) / 2 && cnt[0][1] + cnt[1][0] >= n / 2){
        cout << "YES\n";
    }else {
        cout << "NO\n";
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--){
        sol();
    }
    return 0;
}
/**
 * 
 */
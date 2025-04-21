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
    string s;
    cin >> s;
    int n = s.length();
    for(int i = 0; i < n; i++){
        int idx = i;
        for(int j = i + 1; j < min(i + 10, n); j++){
            if(s[j] - '0' - j > s[idx] - '0' - idx){
                idx = j;
            }
        }
        while(idx > i){
            s[idx]--;
            swap(s[idx], s[idx - 1]);
            idx--;
        }
    }
    cout << s << '\n';
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
 * 等于说右移一位就会消耗 1 代价
 * 
 * 51476
 * 55431
 * 
 * 
 */
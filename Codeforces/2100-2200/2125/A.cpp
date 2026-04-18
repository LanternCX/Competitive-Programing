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
    int tag = 0;
    for (int i = 0; i < s.length(); i++) {
        string temp = s.substr(i, 3);
        if (temp == "FFT" || temp == "NTT") {
            tag = 1;
        }
    }
    if (tag) {
        sort(s.begin(), s.end(), greater<char>());
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
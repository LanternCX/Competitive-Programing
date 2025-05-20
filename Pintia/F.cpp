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
    if (a.length() != b.length()) {
        cout << "bull pay\n";
        return;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<map<char, int>> cnt(2);
    auto work = [&](char ch) {
        if (ch >= 'A' && ch <= 'Z') {
            ch = 'a' + ch - 'A';
        }
        return ch;
    };
    for (auto &ch : a) {
        ch = work(ch);
        cnt[0][ch]++;
    }
    for (auto &ch : b) {
        ch = work(ch);
        cnt[1][ch]++;
    }
    int n = a.length();
    int res = 0;
    for (int i = 0; i < n; i++) {
        res += cnt[1][a[i]] > 0;
        cnt[1][a[i]]--;
    }
    debug(res);
    cout << (res >= 4 ? "how pay" : "bull pay") << '\n';
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
 * LuRenJia 
 * GuonnXiA
 * GuoAnXin
 */
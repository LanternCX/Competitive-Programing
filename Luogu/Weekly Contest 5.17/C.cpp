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
int vectoi(const vector<int>& digits) {
    int res = 0;
    for (int d : digits) {
        res = res * 10 + d;
    }
    return res;
}
void sol(){
   string s;
    int A, B;
    cin >> s >> A >> B;

    vector<int> hex;
    for (char c : s) hex.push_back(c - '0');

    int n = hex.size();
    int ans = 0;

    for (int bit = 0; bit < (1 << n); bit++) {
       	auto dfs = [&](auto &&dfs, int idx, int a, int b, vector<int> cur) {
            if (idx == n) {
                if (a <= A && b <= B) {
                    ans = max(ans, vectoi(cur));
                }
                return;
            }

            if ((bit >> idx) % 2 == 1) {
                for (int i = 0; i <= A - a; i++) {
                    vector<int> temp = cur;
                    temp[idx] = (hex[idx] + i) % 10;
                    dfs(dfs, idx + 1, a + i, b, temp);
                }
            } else {
                for (int j = 0; j <= B - b; j++) {
                    vector<int> temp = cur;
                    temp[idx] = (hex[idx] - j + 10) % 10;
                    dfs(dfs, idx + 1, a, b + j, temp);
                }
            }
        };

        dfs(dfs, 0, 0, 0, hex);
    }

    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--){
        sol();
    }
    return 0;
}
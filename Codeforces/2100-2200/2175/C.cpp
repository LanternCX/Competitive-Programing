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
void sol() {
    string s, t;
    cin >> s >> t;
    vector<int> cnt(26, 0), need(26, 0);
    for (auto c : t) {
        cnt[c - 'a']++;
    }
    for (auto c : s) {
        need[c - 'a']++;
    }

    int ok = 1;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] < need[i]) {
            ok = 0;
            break;
        }
    }
    if (!ok) {
        cout << "Impossible\n";
        return;
    }

    int n = t.size();
    string res;
    int pos = 0;

    for (int i = 0; i < n; i++) {
        int ok = 0;
        for (int c = 0; c < 26; c++) {
            if (cnt[c] == 0)
                continue;
            cnt[c]--;
            int flg = (pos < s.size() && c == s[pos] - 'a');
            int good = 1;

            if (flg) {
                for (int k = 0; k < 26; k++) {
                    int req = need[k] - (k == c ? 1 : 0);
                    if (req < 0)
                        req = 0;
                    if (cnt[k] < req) {
                        good = 0;
                        break;
                    }
                }
            } else {
                for (int k = 0; k < 26; k++) {
                    if (cnt[k] < need[k]) {
                        good = 0;
                        break;
                    }
                }
            }

            if (good) {
                res.push_back('a' + c);
                if (flg) {
                    need[c]--;
                    pos++;
                }
                ok = 1;
                break;
            } else {
                cnt[c]++;
            }
        }
        if (!ok) {
            cout << "Impossible\n";
            return;
        }
    }

    cout << res << '\n';
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}
/**
 * abcdcbeef
 * dcbe
 *
 * babadab
 * babadabaaaaabcc
 * aaaaabababccdab
 * aaaaabababccdab
 */
#include <bits/stdc++.h>
using namespace std;

int calc(int idx, const string &s) {
    int count = 0;
    for (int i = max(0, idx - 3); i <= min((int)s.size() - 4, idx); i++) {
        if (s.substr(i, 4) == "1100") {
            count++;
        }
    }
    return count;
}

void solve() {
    string s;
    cin >> s;
    int q;
    cin >> q;

    int count = 0;
    for (int i = 0; i <= (int)s.size() - 4; i++) {
        if (s.substr(i, 4) == "1100") {
            count++;
        }
    }

    while (q--) {
        int i, v;
        cin >> i >> v;
        i--;
        if (s[i] != (char)(v + '0')) {
            int before = calc(i, s);
            s[i] = (char)(v + '0');
            int after = calc(i, s);
            count += (after - before);
        }
        if (count > 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

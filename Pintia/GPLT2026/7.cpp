#include <bits/stdc++.h>

using namespace std;

void sol() {
    string ans;
    for (int i = 0; i < 11; i++) {
        string s;
        getline(cin, s);
        ans.append(to_string(s.length()));
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}
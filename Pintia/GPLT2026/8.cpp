#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void sol() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    while (n--) {
        int op;
        cin >> op;
        if (op == 1) {
            string tag;
            cin >> tag;
            int cnt = 0;
            vector<int> ans;
            for (int i = 0; i < s.length(); i++) {
                if (s.substr(i, tag.length()) == tag) {
                    ans.push_back(i);
                    if (ans.size() == 3) {
                        break;
                    }
                }
            }
            if (ans.size() == 0) {
                cout << -1 << '\n';;
                continue;
            }
            for (int i = 0; i < ans.size(); i++) {
                cout << ans[i] << " \n"[i == ans.size() - 1];
            }
        }

        if(op == 2) {
            int p;
            string tag;
            cin >> p >> tag;
            s = s.substr(0, p) + tag + s.substr(p, s.length());
            cout << s << '\n';
        }

        if (op == 3) {
            int l, r;
            cin >> l >> r;
            reverse(s.begin() + l, s.begin() + r + 1);
            cout << s << '\n';
        }
    }
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
/**
 * 0 2 4
0 2
-1
Xababa
XababaY
XabMabaY
XaabaMbY
XaabaMbY
1
YbMabaaX

0 2 4
0 2
-1
Xababa
XababaY
XabMabaY
XaaMbbaY
XaaMbbaY
1
bbMaaXaY


 */
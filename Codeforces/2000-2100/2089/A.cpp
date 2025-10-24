#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
void sol(){
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    auto work = [&](const string &str) -> bool {
        string re = str;
        reverse(re.begin(), re.end());
        return str < re;
    };
    if (work(s)) {
        cout << "YES\n";
        return;
    }

    if (k == 0) {
        cout << "NO\n";
        return;
    }

    string tmep = s;
    sort(tmep.begin(), tmep.end());
    if (work(tmep)) {
        cout << "YES\n";
    } else {
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
 * rev
 * ver
 */
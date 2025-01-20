#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n - 1; i++){
        int det = min(a[i], a[i + 1]);
        a[i] -= det;
        a[i + 1] -= det;
    }
    int ans = 1;
    for(int i = 0; i < n - 1; i++){
        if(a[i] != 0){
            ans = 0;
            break;
        }
    }
    cout << (ans ? "YES\n" : "NO\n");
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

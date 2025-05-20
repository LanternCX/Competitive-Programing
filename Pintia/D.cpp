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
    int n;
    cin >> n;
    int cnt = 3;
    vector<int> ans = {5, 2, 0};
    while (cnt < n) {
        int sum = 0;
        for (int i = cnt - 1; i >= cnt - 3; i--) {
            sum += ans[i];
        }
        ans.push_back(sum % 10);
        cnt++;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i];
    }
    cout << '\n';
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
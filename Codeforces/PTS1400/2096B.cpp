#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
void sol(){
    int n, k;
    cin >> n >> k;
    vector<int> l(n), r(n);
    for(auto &x : l){
        cin >> x;
    }
    for(auto &x : r){
        cin >> x;
    }
    vector<int> a(n), b(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        a[i] = max(l[i], r[i]);
        b[i] = min(l[i], r[i]);
        sum += a[i];
    }

    sort(b.begin(), b.end(), greater<>());
    for (int i = 0; i < k - 1; i++) {
        sum += b[i];
    }

    cout << sum + 1 << '\n';
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
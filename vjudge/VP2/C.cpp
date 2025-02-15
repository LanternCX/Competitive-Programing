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
const int maxN = 1e5 + 10;
const int mod = 1e9 + 7;
void sol(){
    int N;
    cin >> N;

    int lenA, lenB;
    vector<int> a(maxN, 0), b(maxN, 0);

    cin >> lenA;
    for (int i = lenA - 1; i >= 0; --i) {
        cin >> a[i];
    }
    cin >> lenB;
    for (int i = lenB - 1; i >= 0; --i) {
        cin >> b[i];
    }
    
    ll ans = 0;
    int maxL = max(lenA, lenB);

    for (int i = maxL - 1; i >= 0; --i) {
        ans *= max(2, max(2, max(a[i], b[i]) + 1));
        ans = (ans + a[i] - b[i] + mod) % mod;
    }
    
    cout << ans << '\n';
    return;
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
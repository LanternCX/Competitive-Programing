#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void sol(){
    int n, k;
    cin >> n >> k;
    map<int, int> a; 
    for (int i = 0; i < k; ++i) {
        int b, c;
        cin >> b >> c;
        a[b] += c;
    }
    vector<pair<int, int>> b(a.begin(), a.end());
    sort(b.begin(), b.end(), [](pair<int, int> a, pair<int, int> b) -> int {
        return a.second > b.second;
    });
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(i >= b.size()){
            break;
        }
        ans += b[i].second;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}

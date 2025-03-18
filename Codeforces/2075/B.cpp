#include <bits/stdc++.h>
using namespace std;
using ll =  long long;
void sol() {
    int t;
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(auto &x : arr){
        cin >> x;
    }
    ll ans = 0;

    if(k == 1){
        for(int i = 0; i < n; i++){
            ll temp = arr[i];
            int mx = 0;
            if(i > 0){
                mx = max(mx, arr[0]);
            }
            if (i + 1 < n){
                mx = max(mx, arr[n - 1]);
            }
            temp += mx;
            ans = max(ans, temp);
        }
        cout << ans << '\n';
        return;
    }

    sort(arr.begin(), arr.end(), greater<int>());
    for(int i = 0; i < k + 1; i++){
        ans += arr[i];
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--){
        sol();
    }
    return 0;
}
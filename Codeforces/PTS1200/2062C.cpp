#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
ll mx = LLONG_MIN;
void sol(){
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(auto &x : arr){
        cin >> x;
    }
    int now = n - 1;
    ll ans = LLONG_MIN;
    for(int i = 0; i < n; i++){
        ll sum = 0;
        for(int i = 0; i <= now; i++){
            sum += arr[i];
        }

        if (i == 0){
            ans = max(ans, sum);
        }else {
            ans = max(ans, abs(sum));
        }

        for (int i = 0; i < now; i++){
            arr[i] = arr[i + 1] - arr[i];
        }

        now--;
    }
    cout << ans << '\n';
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
 * 1 2 3 4 5
 * 2-1 3-2 4-3 5-4 
 */
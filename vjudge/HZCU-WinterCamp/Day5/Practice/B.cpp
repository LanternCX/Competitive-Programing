#include <bits/stdc++.h>
using namespace std;
const int p = 1e9 + 7;
using ll = long long;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    ll ans = 1;
    for(int i = 0; i < n; i++){
        ans *= arr[i] - i;
        ans %= p;
    }
    cout << ans;
    return 0;
}
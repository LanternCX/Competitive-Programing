#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void slove(){
    int n;
    cin >> n;
    vector<ll> arr(n);
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    cout << sum - 2 * arr[n - 2] << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<ll> ans;
    while (n--) {
       slove();
    }
    return 0;
}

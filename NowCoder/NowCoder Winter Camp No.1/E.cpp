#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void sol(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    int mid = n / 2;

    int l = arr[mid / 2], r = arr[mid + mid / 2];

    ll ans = LONG_LONG_MAX;

    for(int lx : {l, l - 1}){
        for(int rx : {r, r + 1}){
            if(rx == lx){
                continue;
            }

            ll temp = 0;
            for(int i = 0; i < mid; i++){
                temp += abs(arr[i] - lx);
                temp += abs(arr[mid + i] - rx);
            }
            ans = min(ans, temp);
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        sol();
    }
    return 0;
}
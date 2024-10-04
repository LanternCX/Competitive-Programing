#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    vector<int> diff(n);
    for(int i = 1; i < n; i++){
        diff[i] = arr[i] - arr[i - 1];
    }
    sort(diff.begin(), diff.end());
    int ans = 0;
    for(int i = 1; i <= k; i++){
        ans += diff[i];
    }
    cout << ans;
    return 0;
}
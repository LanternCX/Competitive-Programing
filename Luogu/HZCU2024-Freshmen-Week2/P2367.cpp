#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, p;
    cin >> n >> p;
    vector<int> diff(n + 1);
    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        diff[i] = arr[i] - arr[i - 1];
    }
    for(int i = 1; i <= p; i++){
        int x, y, z;
        cin >> x >> y >> z;
        diff[x] += z;
        diff[y + 1] -= z;
    }
    vector<int> a(n + 1);
    int ans = 1e7;
    for(int i = 1; i <= n; i++){
        a[i] = a[i - 1] + diff[i];
        ans = min(ans, a[i]);
    }
    cout << ans << '\n';
    return 0;
}
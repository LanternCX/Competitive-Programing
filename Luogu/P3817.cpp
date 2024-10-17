#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    ll ans = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(i > 0 && arr[i - 1] + arr[i] > x){
            int temp = (arr[i - 1] + arr[i]) - x;
            ans += temp;
            arr[i] = arr[i] - temp <= 0 ? 0 : arr[i] - temp;
        }
    }
    cout << ans;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int ans = INT_MAX;
    for(int i = 0; i < n; i++){
        int mn, mx;
        if(i == 0){
            mn = min(arr[i] * 2, arr[1]);
            mx = max(arr[i] * 2, arr[n - 1]);
        }else {
            mn = min(arr[i] * 2, arr[0]);
            mx = max(arr[i] * 2, arr[n - 1]);
        }

        ans = min(ans, mx- mn);
    }
    cout << ans;
    return 0;
}
/**
 * 1 2 3 4 5 6 7
 * 
 */
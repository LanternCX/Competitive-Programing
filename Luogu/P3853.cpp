#include <bits/stdc++.h>
using namespace std;
int main(){
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int len, n, k;
    cin >> len >> n >> k;
    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    arr.push_back(len);
    int l = 0, r = len;
    while(l < r){
        int mid = (l + r + 1) / 2;
        int now = 0;
        int cnt = 0;
        for(int i = 0; i <= len; i += mid){
            if(arr[now + 1] > i){
                cnt++;
            }else {
                now++;
                i = arr[now];
            }
        }
        // cout << l << ' ' << r << '\n';
        if(cnt <= k){
            r = mid - 1;
        } else {
            l = mid;
        }
    }
    cout << r + 1;
    return 0;
}
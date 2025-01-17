#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    int l = 0, r = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        r = max(r, arr[i]);
    }
    while(l < r){
        int mid = (l + r) / 2;
        if(mid == 0){
            cout << 0; 
            return 0;
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            cnt += arr[i] / mid;
        }
        if(cnt >= k){
            l = mid + 1;
        }else{
            r = mid;
        }
    }
    cout << l - 1;
    return 0;
}
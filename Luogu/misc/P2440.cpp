#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    int l = 0, r = 1e8;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        r = max(arr[i], r);
    }

    while(l < r){
        int mid = (l + r) / 2;
        // cout << l << ' ' << r << '\n';
        int sum = 0;
        if(mid != 0){
            for(int x : arr){
                sum += x / mid;
            }
        }

        if(sum >= k){
            l = mid + 1;
        }else{
            r = mid;
        }
    }
    if(l - 1 <= 0){
        cout << 0;
    }else {
        cout << l - 1;
    }
    return 0;
}
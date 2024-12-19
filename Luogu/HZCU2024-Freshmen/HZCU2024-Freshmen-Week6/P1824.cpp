#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, c;
    cin >> n >> c;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int l = 1, r = arr[n - 1] - arr[0];
    int ans = -1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        // cout << l << ' ' << r << ' ' << mid << '\n';

        int temp = c - 1;
        int idx = 0;
        for(int i = 1; i < n; i++){
            if(arr[i] - arr[idx] >= mid){
                temp--;
                idx = i;
            }
        }
        // cout << "temp: " << temp << '\n';
        if(temp <= 0){
            l = mid + 1;
        }else{
            r = mid;
        }
    }
    cout << l - 1;
    return 0;
}
/**
 * 
 * 1 2 8 4 9
 * 1 2 4 8 9
 */
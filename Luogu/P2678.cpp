#include <bits/stdc++.h>
using namespace std;
struct node{
    int idx, val, diff;
};
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int len, n, m;
    cin >> len >> n >> m;
    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    arr.push_back(len);
    int l = 0, r = len;
    while(l < r){
        int mid = (l + r) / 2;
        int cnt = 0;
        int now = 0;
        for(int i = 1; i <= n + 1; i++){
            if(arr[i] - arr[now] < mid){
                cnt++;
            }else {
                // cout << arr[now] << ' ';
                now = i;
            }
        }
        // cout << '\n';
        // cout << l << ' ' << r << ' ' << mid <<  '\n';
        if(cnt > m){
            r = mid;
        }else {
            l = mid + 1;
        }
    }
    if(l == len){
        cout << l;
    }else {
        cout << l - 1;
    }
    return 0;
}
/**
 * 2 11 14 17 21
 * 
 */
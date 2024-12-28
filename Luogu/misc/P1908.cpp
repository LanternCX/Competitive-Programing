#include <bits/stdc++.h>
using namespace std;
using ll = long long;   
ll ans = 0;
vector<int> msort(vector<int> arr){
    if(arr.size() == 1){
        return arr;
    }
    int mid = arr.size() / 2;
    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());
    left = msort(left);
    right = msort(right);
    // cout << "l: ";
    // for(int x : left){
    //     cout << x << ' ';
    // }
    // cout << "\nr: ";
    // for(int x : right){
    //     cout << x << ' ';
    // }
    // cout << endl;
    for(int x : left){
        auto it = lower_bound(right.begin(), right.end(), x);
        int det = it - right.begin();
        ans += det;
    }
    vector<int> res(left.size() + right.size());
    merge(left.begin(), left.end(), right.begin(), right.end(), res.begin());
    return res;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    msort(arr);
    cout << ans;
    return 0;
}
/**
 * 5 4 2 6 3 1
 * 
 */
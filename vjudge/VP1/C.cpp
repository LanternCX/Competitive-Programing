#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<int> diff;
    for(int i = 1; i < n; i++){
        diff.push_back(a[i] - a[i - 1]);
    }
    sort(diff.begin(), diff.end(), greater<int>());
    int mx = diff[0];
    int l = 1, r = mx;
    auto check = [&](int mid){
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            cnt += ceil(1.0 * (a[i] - a[i - 1]) / mid) - 1;
        }
        return cnt <= m + 1;
    };
    while(l < r){
        int mid = (l + r) / 2;
        // cout << l << ' ' << r << '\n';
        if(check(mid)){
            r = mid;
        }else {
            l = mid + 1;
        }
    }
    cout << l;
    return 0;
}
/**
 * 1) 2l > max
 * 2) l > a[i] - a[i - 1]
 */
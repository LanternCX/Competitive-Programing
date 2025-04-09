#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "include/debug.cpp"
#else
#define debug(...) (void)(0)
#endif
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
void sol(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    auto check = [&](int mid){
        int cnt = 0;
        unordered_set<int> s;
        for(int num : a){
            if(num < mid){
                s.insert(num);
            }
            if((int)s.size() == mid){
                cnt++;
                s.clear();
            }
        }
        return cnt >= k;
    };
    int l = 0, r = n, ans = 0;
    while (l <= r){
        int mid = (l + r) / 2;
        if (check(mid)){
            ans = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--){
        sol();
    }
    return 0;
}
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
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &x : arr){
        cin >> x;
    }
    vector<pii> ans;
    auto mex = [&](int i, int j){
        int a = i;
        int b = j;
        if(a > b){
            swap(a, b);
        }
        if(a == 0 && b == 1){
            return 2;
        }
        if(a == 0){
            return 1;
        }
        return 0;
    };
    auto work = [&](int i, int j){
        ans.push_back({i, j});
        arr[i] = mex(arr[i], arr[j]);
        arr.erase(arr.begin() + j);
        n--;
    };
    int idx = 0;
    while(idx < n - 1){
        while(arr[idx] == 0){
            work(idx, idx + 1);
            debug(arr);
        }
        idx++;
    }
    if(arr[n - 1] == 0){
        work(n - 2, n - 1);
        debug(arr);
    }
    debug('\n');
    cout << ans.size() + 1 << '\n';
    for(auto [i, j] : ans){
        cout << i + 1 << ' ' << j + 1 << '\n';
    }
    cout << 1 << ' ' << arr.size() << '\n';
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
/**
 * 0 0 0 0
 * 1 1
 * 0
 * 
 */
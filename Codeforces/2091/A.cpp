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
    map<int, int> mp;
    auto work = [&](){
        if(mp[0] >= 3 && mp[2] >= 2 && mp[1] >= 1 && mp[3] >= 1 && mp[5] >= 1){
            return 1;
        }
        return 0;
    };
    for(int i = 0; i < n; i++){
        mp[arr[i]]++;
        if(work()){
            cout << i + 1 << '\n';
            return;
        }
    }
    cout << 0 << '\n';
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
 * 1 - 12
 * 3x 2x 1x 0x
 */
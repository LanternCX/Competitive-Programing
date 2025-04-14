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
    int ans = 0;
    auto work = [&](int i){
        string s = to_string(i);
        vector<int> pre;
        int sum = 0;
        for(int i = 0; i < s.length(); i++){
            pre.push_back(s[i] - '0');
            sum += pre[i];
        }
        pre.push_back(sum);
        int idx = 0;
        int res = 0;
        while(pre[pre.size() - 1] <= i){
            pre.push_back(pre[pre.size() - 1] * 2 - pre[idx++]);
            if(pre[pre.size() - 1] == i){
                res = 1;
                break;
            }
        }

        // for(auto x : pre){
        //     cout << x << ' ';
        // }
        return res;
    };
    for(int i = 1e7; i > 0; i--){
        if(work(i)){
            cout << i << ' ';
            return;
        }
    }
}
void ans(){
    cout << "7913837\n";
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--){
        ans();
    }
    return 0;
}
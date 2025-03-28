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
    int p, n, k;
    cin >> p >> n >> k;
    vector<vector<double>> arr(2);
    for(int i = 0; i < n; i++){
        double t, px;
        cin >> t >> px;
        if(t){
            arr[t].push_back(px);
        }else {
            arr[t].push_back(px / 10);
        }
    }
    sort(arr[0].begin(), arr[0].end(), less<double>());
    sort(arr[1].begin(), arr[1].end(), greater<double>());
    auto pre = arr;
    array<int, 2> len = {(int) pre[0].size() - 1, (int) pre[1].size() - 1};
    for(int i = 1; i <= len[0]; i++){
        pre[0][i] *= pre[0][i - 1];
    }
    for(int i = 1; i <= len[1]; i++){
        pre[1][i] += pre[1][i - 1];
    }
    debug(pre[0]);
    debug(pre[1]);
    double ans = 1e9;
    for(int i = 0; i <= k; i++){
        double res;
        if(i == 0){
            res = p - pre[1][min(len[1], k - 1)];
        }else if(i == k){
            res = p * pre[0][min(len[0], k - 1)];
        }else{
            res = p * pre[0][min(len[0], i - 1)] - pre[1][max(0, min(len[1], k - i - 1))];
        }
        debug(i - 1, k - i - 1);
        debug(i, res);
        ans = min(ans, res);
    }
    cout << max(ans, (double)0) << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(2);
    int t = 1;
    cin >> t;
    while (t--){
        sol();
    }
    return 0;
}
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

#define int ll

const ll N = 202420242024;

void sol(){
    int l = 0, r = 24 * 20 * N;
    int res = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        int cnt = 0;
        cnt += mid / 24;
        cnt += mid / 20;
        cnt -= mid / (120);
        cout << l << ' ' << r << '\n';
        if(cnt < 202420242024){
            l = mid + 1;
        }else if(cnt > 202420242024){
            r = mid - 1;
        }else{
            res = mid;
            break;
        }
    }
    for(int i = 0; i <= 24; i++){
        if((res - i) % 20 == 0 || (res - i) % 24 == 0){
            cout << res - i << '\n';
            cout << (res - i) / 24 + (res - i) / 20 - (res - i) / 120 << '\n';
            return;
        }
    }
}
void ans(){
    cout << "2429042904288" << '\n';
}
signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--){
        ans();
    }
    return 0;
}
/**
 * 假设全都是 20 的倍数
 * 那么答案很简单就是 20 * 202420242024
 * 但是中间有 24 的倍数
 * 实际上我们需要找到 20 * 202420242024 之内有多少个 24 的倍数
 * 也就是说 20 * 202420242024 / 24
 * 
 * 二分？
 * 如果这个数是 20 或者 24 的倍数
 * 并且这个数内 20 或者 24 的倍数的数字加起来有 202420242024 个那么就是答案
 * 
 * 这告诉我们如果数学题不会可以直接二分
 * 
 * 但是 如果同时是 20 或者 24 的倍数就不好统计
 * 
 * 所以我们需要减去 同时是 20 和 24 的倍数的数字
 * 
 * 20 40 60
 */
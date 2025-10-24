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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.rbegin(), a.rend());

    int count = 0, teams = 0;
    for (int skill : a) {
        count++;
        if (count * skill >= x) {
            teams++;
            count = 0;
        }
    }
    cout << teams << '\n';
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
 * x <=  min(sub) * len(sub)
 * 
 * len(sub) >= x / min(sub)
 * 
 * min(sub) >=  x / len(sub)
 * 
 * 也就是说
 * 对于一个值 如果他是最小的 那么他的人数必须满足 x / min(sub)
 * 可以从前向后遍历数组
 */
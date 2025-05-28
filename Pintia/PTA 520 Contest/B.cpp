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
    int l, r;
    cin >> l >> r;
    int mn = min(l, r);
    cout << min(l, r) << '\n';
    if (0 < mn && 20 >= mn) {
        cout << "XianHua\n";
    }
    
    if (20 < mn && 40 >= mn) {
        cout << "XiangXun\n";
    }

    
    if (40 < mn && 60 >= mn) {
        cout << "BaoWenBei\n";
    }

    
    if (60 < mn && 200 >= mn) {
        cout << "HunShaZhao\n";
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--){
        sol();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m, n;
    cin >> m >> n;
    vector<int> sc(m);
    vector<int> stu(n);
    for(int i = 0; i < m; i++){
        cin >> sc[i];
    }
    for(int i = 0; i < n; i++){
        cin >> stu[i];
    }
    sort(stu.begin(), stu.end());
    sort(sc.begin(), sc.end());
    ll ans = 0;
    for(int x : stu){
        auto r = lower_bound(sc.begin(), sc.end(), x);
        if(r == sc.begin()){
            ans += abs(*r - x);
            continue;
        }
        if (r == sc.end()) {
            ans += abs(x - *(r - 1));
            continue;
        }
        auto l = r - 1;
        // cout << x << ' ' << *l << ' ' << *r << '\n';
        ans += min(abs(x - *l), abs(*r - x));
    }
    cout << ans;
    return 0;
}

/**
 * 
    513 598 567
    500 600 550
    13
\
3 3
513 598 567
500 600 550
 */
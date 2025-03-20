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
    string s;
    int n;
    cin >> n >> s;
    int tag = 0;
    map<char, int> cnt;
    for(int i = 0; i < n; i++){
        cnt[s[i]]++;
        if(s[i] == 'p'){
            tag = 1;
        }
        if(s[i] == 's' && tag){
            cout << "NO\n";
            return;
        }
    }

    if(s[0] == 's' && cnt['s'] == 1 || s[n - 1] == 'p' && cnt['p'] == 1 || cnt['s'] == 0 || cnt['p'] == 0){
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
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
 * pss..s
 * 
 * .sp.
 * 
 * psss....
 * 
 * pspspsps
 * 
 * ..p...s..一定是NO
 * 
 * 那么需要讨论 ..s..p.. 的情况
 * 为什么
 * sp YES
 * .sp. NO
 * 3123
 * 两个长度一样但是不完全重合的排列
 * s.spp
 */
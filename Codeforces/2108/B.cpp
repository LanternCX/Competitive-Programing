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
    vector<int> a(n);
    for(auto &x : a){
        cin >> x;
        x = abs(x);
    }
    vector<int> cnt = {0, 0};
    for(int i = 1; i < n; i++){
        if(a[i] > a[0]){
            cnt[0]++;
        }else{
            cnt[1]++;
        }        
    }
    if(n % 2 == 0){
        if(cnt[1] > cnt[0] + 1){
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    if(n % 2 == 1){
        if(cnt[1] > cnt[0]){
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
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
 * 4 -2 0 5
 * 
 * -4 2 0 -5
 * -5 -4 0 2
 */
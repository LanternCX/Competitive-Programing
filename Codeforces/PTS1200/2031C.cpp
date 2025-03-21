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
    if(n % 2 == 1 && n <= 25){
        cout << -1 << '\n';
        return;
    }
    if(n % 2 == 0){
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            ans[i] = i - i % 2 + 1;
        }
        for(auto x : ans){
            cout << x << ' ';
        }
        cout << '\n';
    }
    if(n % 2 == 1){
        vector<int> ans(n);
        ans[0] = 1;
        ans[9] = 1;
        ans[25] = 1;

        ans[10] = 2;
        ans[26] = 2;

        for(int i = 0; i < 9; i++){
            ans[i] = i + i % 2 + 1;
        }
        for(int i = 10 + 1; i < 25; i++){
            ans[i] = i + i % 2 + 1;
        }
        for(int i = 26 + 1; i < n; i++){
            ans[i] = i + i % 2 + 1;
        }
        for(auto x : ans){
            cout << x << ' ';
        }
        cout << '\n';
    }
    // map<int, int> sq;
    // for(int i = 0; i * i < 10000; i++){
    //     sq[i * i] = 1;
    // }
    // for(int i = 0; i < 10000; i++){
    //     for(int j = i + 1; j < 10000; j++){
    //         for(int k = j + 1; k < 10000; k++){
    //             if(sq[abs(i - j)] && sq[abs(i - k)] && sq[abs(k - j)]){
    //                 cout << i << ' ' << j << ' ' << k << '\n';
    //                 return;
    //             }
    //         }
    //     }
    // }
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
 * 4 9 16 25 36 49 64 
 * 
 * 1 2 3 4 5 6
 * 1 1 0 0 0 1
 */
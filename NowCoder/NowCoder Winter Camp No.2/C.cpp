#include <bits/stdc++.h>
using namespace std;
void sol(){
    int m, n;
    cin >> n >> m;
    if(n == m || n - m > 26){
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
    string ans(n, 'a');
    int t = m * 2 > n ? n - m - 1 : m;
    for(int i = 0; i < t; i++){
        ans[i] = 'z' - i;
        ans[n - 1 - i] = 'z' - i;
    }
    if(m * 2 <= n){
        for(int i = m; i < n - m; i++){
            ans[i] = 'z' - i;
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        sol();
    }
    return 0;
}
/**
 * 29 3
 * abcc
 * aaaabcdefghijklmnopqrstuvwxyz 26 + 3
 * abccde = 3
 * 6 5
 * aabcde
 * aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
 * abcda
 */
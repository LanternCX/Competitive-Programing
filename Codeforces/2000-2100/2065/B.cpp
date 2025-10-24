#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void sol(){
    string s;
    cin >> s;
    if(s.length() == 1){
        cout << 1 << '\n';
        return;
    }
    int ans = s.length();
    for(int i = 0; i < s.length() - 1; i++){
        if(s[i] == s[i + 1]){
            ans = 1;
            break;
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        sol();
    }
    return 0;
}
/**
 * acc
 */
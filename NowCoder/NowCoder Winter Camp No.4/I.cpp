#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void sol(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    string tag = "uwawauwa";
    ll cnt = 0;
    ll ans = 0;
    for(int i = 1; i < n; i++){
        if(s[i - 1] == 'u'){
            cnt++;
        }
        if(s.substr(i + 1, tag.length()) == tag){
            ans += cnt;
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
#include <bits/stdc++.h>
using namespace std;
void slove(){
    string s;
    cin >> s;
    string tag = "codeforces";
    int ans = 0;
    for(int i = 0; i < s.length(); i++){
        if(tag[i] != s[i]){
            ans++;
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    while (n--) {
        slove();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
void slove(){
    string s;
    cin >> s;
    int a = 0, b = 0;
    for(int i = 0; i <= 2; i++){
        a += s[i] - '0';
    }
    for(int i = 3; i <= 5; i++){
        b += s[i] - '0';
    }
    string ans = a == b ? "YES" : "NO";
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
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void sol(){
    string s;
    cin >> s;
    cout << s.substr(0, s.length() - 2) << 'i' << '\n';
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
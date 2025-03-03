#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void sol(){
	string str;
	cin >> str;
    ll len = str.length();

	vector<ll> y(len), ye(len), yes(len), n(len), no(len);
    y[0] = str[0] == 'Y';
    n[0] = str[0] == 'N';
    for(ll i = 1; i < len; i++){
        // pre YES
        y[i] = (str[i] == 'Y') + y[i - 1];
        ye[i] = y[i - 1] * (str[i] == 'E') + ye[i - 1];
        yes[i] = ye[i - 1] * (str[i] == 'S') + yes[i - 1];
        
        // pre NO
        n[i] = (str[i] == 'N') + n[i - 1];
        no[i] = (str[i] == 'O') * n[i - 1] + no[i - 1];
    }
    
    cout << yes[len - 1] << ' ' << no[len - 1] << '\n';

    array<ll, 2> ans = {yes[len - 1], no[len - 1]};
    if(ans[0] == ans[1]){
        cout << "DUI DUI DUIMA" << '\n';
        return;
    }

    vector<ll> o(len), s(len), es(len);
    s[len - 1] = str[len - 1] == 'S';
    o[len - 1] = str[len - 1] == 'O';
    for(ll i = len - 2; i >= 0; i--){
        // suf YES
        s[i] = (str[i] == 'S') + s[i + 1];
        es[i] = (str[i] == 'E') * s[i + 1] + es[i + 1];

        // suf NO
        o[i] = (str[i] == 'O') + o[i + 1];
    }

    if(ans[0] > ans[1]){
        for(int i = 0; i < len; i++){
            if(ans[0] - max({es[i], ye[i], y[i] * s[i]}) < ans[1] + max(o[i], n[i])){
                cout << "O BUDUI BUDUI\n";
                return;
            }
        }
        cout << "DUI DE\n";
        return;
    }

    if(ans[0] < ans[1]){
        for(int i = 0; i < len; i++){
            if(ans[0] + max({es[i], ye[i], y[i] * s[i]}) > ans[1] - max(o[i], n[i])){
                cout << "O DUI DE\n";
                return;
            }
        }
        cout << "BUDUI BUDUI\n";
        return;
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--){
        sol();
    }
    return 0;
}
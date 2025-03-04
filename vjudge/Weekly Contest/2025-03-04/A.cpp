#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void sol(){
	string s;
	cin >> s;
	for(int i = 0; i < s.length() - 1; i += 2){
		swap(s[i], s[i + 1]);
	}
	cout << s;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
//    cin >> t;
    while (t--){
        sol();
    }
    return 0;
}
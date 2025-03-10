#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
void sol(){
	int n;
	cin >> n;
    string tag;
    cin >> tag;
    int ans = -1;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		if(s == tag){
			ans = i + 1;
		}
	} 
	cout << ans << '\n';
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
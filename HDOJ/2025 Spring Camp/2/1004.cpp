#include<bits/stdc++.h>

using namespace std;
using ll = long long;
void sol(){
	string tag;
	cin >> tag;
	string temp;
	cin >> temp;
	ll k;
	if(temp.length() > 3){
		k = 100;
	}else{
		k = stoi(temp);
	}
	string s;
	for(int i = 0; i < min(30LL, k); i++){
		s += tag;
	}
	int n = s.length();
	vector<int> dp(n + 1, 1);
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j >= 0; j--){
            if(s[j] < s[i]){
                dp[i] = max(dp[j] + 1, dp[i]);
            }
            ans = max(dp[i], ans);
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
abc
*/
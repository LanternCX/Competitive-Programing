#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int n;
	cin>>n;
    int mx = 0;
    map<int, int> cnt;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
        mx = max(mx, x);
		cnt[x]++;
	}
	for(int i = 1; i <= mx; i++){
        if(cnt[i] == 1){
            cout << "No\n";
            return;
        }
        if(cnt[i] >= 2){
			cnt[i + 1] += cnt[i] - 2;
        }
	}
	cout<<"Yes\n";
}
int main(){
    ll t;
	cin>>t;
	while(t--){
		solve();
	}
    return 0;
}
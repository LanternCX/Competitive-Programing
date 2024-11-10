#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;
	cin >> s;
	int cnt1 = 0, cnt2 = 0;
	int ans = 0;
	for(char ch : s){
		if(ch == 'Q'){
			cnt1++;
		}else if (ch == 'A'){
			cnt2++;
		}
	}
//	cout << cnt1 << ' ' << cnt2 << '\n';
	if(cnt1 >= 2 && cnt2 >= 1){
		cnt1 -= 2;
		cnt2 -= 1;
		ans += min(cnt1,  cnt2) + 1;
	}
	cout << ans << '\n';
}
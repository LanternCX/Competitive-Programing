#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int cnt[6];
int main(){
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;
	getline(cin, s);
	int ans = 0;
	for(char ch : s){
		if(ch >= 'a' && ch <= 'e'){
			cnt[ch - 'a']++;
		}
	}
	printf("a(%d)b(%d)c(%d)d(%d)e(%d)", cnt[0], cnt[1], cnt[2], cnt[3], cnt[4]);
}
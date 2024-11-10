#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int cnt[6];
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;
	cin >> s;
	if(s.length() == 6){
		cout << s.substr(0, 4);
		cout << '-';
		cout << s.substr(4, 2);
	}
	if(s.length() == 4){
		string y = s.substr(0, 2);
		int n = (y[0] - '0') * 10 + (y[1] - '0');
		if(n < 22){
			n = 2000 + n;
		}else{
			n = 1900 + n;
		}
		cout << n << '-' << s.substr(2, 2);
	}
}
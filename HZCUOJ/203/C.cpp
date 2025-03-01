#include <bits/stdc++.h> 

using namespace std;
void sol(){
	string s;
	cin >> s;
	string in;
	string temp;
	while(cin >> temp){
		in += temp;
		in += ' ';
	}
	auto work = [&](char ch) -> char {
		if(ch >= 'a' && ch <= 'z'){
			return s[ch - 'a'];
		}
		if(ch >= 'A' && ch <= 'Z'){
			char temp = s[ch - 'A'] - 'a';
			return (char(s[ch - 'A'] - 'a' ) + 'A');
		}
		return ch;
	};
	for(int i = 0; i < in.size() - 1; i++){
		cout << work(in[i]);
	}
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
//	cin >> t;
	while(t--){
		sol();
	}
	return 0;
} 
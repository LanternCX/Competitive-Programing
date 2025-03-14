#include<bits/stdc++.h>

using namespace std;
void sol(){
	vector<string> dica = {"jia", "yi", "bing", "ding", "wu", "ji", "geng", "xin", "ren", "gui"}; 
	vector<string> dicb = {"zi", "chou", "yin", "mao", "chen", "si", "wu", "wei", "shen", "you", "xu", "hai"};
	string s;
	cin >> s;
	int ans = 0;
	int a = 0, b = 0;
	for(int i = 0; i < 60; i++){
		if(dica[a] + dicb[b] == s){
			cout << 1984 + ans << '\n';
			return;
		}
		a++, b++;
		a %= 10;
		b %= 12;
		ans++;
	}
}

int main(){
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--){
		sol();
	}
	return 0;
}
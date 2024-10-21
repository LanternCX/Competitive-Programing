#include<bits/stdc++.h>
using namespace std;
void slove(){
	string s;
	getline(cin, s);	
	for(int i = s.length() - 1; i >= 0; i--){
		cout << s[i];
	}
	cout << '\n';
}
int main(){
	// ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	getchar();
	while(n--){
		slove();
	}
	return 0;
}
/**
2
ab
hello world
*/ 
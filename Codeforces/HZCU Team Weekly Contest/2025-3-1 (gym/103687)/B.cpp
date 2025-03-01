#include<bits/stdc++.h> 

using namespace std;

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;
	cin >>s;
	int n = s.length(); 
	for(int i = 0; i < 2; i++){
		cout << s[i];
	} 
	for(int i = 2; i < n; i++){
		cout << s[i];
		if(s.substr(i - 2, 3) == "cjb"){
			cout << ','; 
		} 
	}
	return 0;
}
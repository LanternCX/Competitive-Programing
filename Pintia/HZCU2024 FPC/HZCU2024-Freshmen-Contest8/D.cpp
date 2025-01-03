#include<bits/stdc++.h>
using namespace std;

int main(){
//	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string s;
	string in;
	while(cin >> s){
		in += s;
	}
	int sum = 0;
	for(char ch : in){
		if(ch == 'I' || ch == 'l'){
			sum++;
		}
	}
	for(int i = 0; i < sum; i++){
		cout << '\\';
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;
	getline(cin, s);
	int cnt = 0;

	for(char ch : s){
		if(ch == '6'){
			cnt++;
		}else{
			if(cnt > 3 && cnt <= 9){
				cout << 9;
			}else if(cnt > 9){
				cout << 27 ;
			}else if (cnt <= 3 && cnt > 0){
				for(int i =0; i < cnt; i++){
					cout << '6';
				}
			}
			cout << ch;
			cnt = 0;
		}
	}
	if(cnt > 3 && cnt <= 9){
		cout << 9;
	}else if(cnt > 9){
		cout << 27;
	}else if (cnt <= 3 && cnt > 0){
		for(int i =0; i < cnt; i++){
			cout << '6';
		}
	}
	cnt = 0;
	cout << '\n';
}
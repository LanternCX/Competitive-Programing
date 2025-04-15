#include<bits/stdc++.h>

using namespace std;

void sol(int t){
	string s;
	while(cin >> s){
		stack<char> st;
		int tag = 0;
		for(auto ch : s){
			if(ch == '('){
				st.push(ch);
			}
			if(ch == ')'){
				if(st.empty()){
					cout << "NO\n";
					tag = 1;
					break;
				}
				st.pop();
			}
		}
		if(tag){
			continue;
		}
		if(!st.empty()){
			cout << "NO\n";
		}else{
			cout << "YES\n";
		}
	}
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
//	cin >> t;
	while(t--){
		sol(t);
	}
	return 0; 
} 
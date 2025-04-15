#include<bits/stdc++.h>

using namespace std;

void sol(int t){
	string s;
	cin >> s; 
	stack<char> st;
	int tag = 0;
	for(auto ch : s){
		if(ch == '(' || ch == '[' || ch == '{'){
			st.push(ch);
		}
		if(ch == ')'){
			if(st.empty() || st.top() != '('){
				cout << "No\n";
				tag = 1;
				return;
			}
			st.pop();
		}
		if(ch == ']'){
			if(st.empty() || st.top() != '['){
				cout << "No\n";
				tag = 1;
				return;
			}
			st.pop();
		}
		if(ch == '}'){
			if(st.empty() || st.top() != '{'){
				cout << "No\n";
				return;
			}
			st.pop();
		}
	}
	if(!st.empty()){
		cout << "No\n";
	}else{
		cout << "Yes\n";
	}

}

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--){
		sol(t);
	}
	return 0; 
} 
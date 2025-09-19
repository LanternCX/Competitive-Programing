#include<bits/stdc++.h>

using namespace std;
void sol(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(auto &x : arr){
		cin >> x;
	}
	int mx = INT_MIN;
	stack<int> st;
	for(int i = n - 1; i >= 0; i--){
		if(arr[i] > mx){
			st.push(arr[i]);
		}
		mx = max(mx, arr[i]);
	}
	while(!st.empty()){
		cout << st.top() << ' ';
		st.pop();
	}
}

int main(){
	int t = 1;
//	cin >> t;
	while(t--){
		sol();
	}
	return 0;
}
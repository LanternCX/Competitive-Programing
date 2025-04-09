#include<bits/stdc++.h>

using namespace std;
void sol(){
	int n;
	cin >> n;
	queue<int> q;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if(x == 0){
			if(q.empty()){
				cout << "EMPTY ";
				continue;
			}
			cout << q.front() << ' ';
			q.pop();
			continue;
		}
		if(q.size() >= 9){
			cout << "FULL ";
			continue;
		}
		q.push(x);
	}
	cout << '\n';
	while(!q.empty()){
		cout << q.front() << ' ';
		q.pop();
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
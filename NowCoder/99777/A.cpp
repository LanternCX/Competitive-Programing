#include <bits/stdc++.h>

using namespace std;

int a[10][10];

int main(){
	map<int, int> mp;
	int ans = 1;
	for(int i = 0; i < 9; i++){
		int x;
		cin >> x;
		mp[x]++;
	}
	for(pair<int,int> p : mp){
		if(p.second != 3){
			ans = 0;
		}
	}
	
	cout << (ans ? "Yes" : "No");
	return 0;
}
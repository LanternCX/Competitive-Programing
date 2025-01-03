#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	set<int> arr;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		arr.insert(x);
	}
	cout << arr.size() << '\n';
	for(int i : arr){
		cout << i << ' ';
	}
	return 0;
} 
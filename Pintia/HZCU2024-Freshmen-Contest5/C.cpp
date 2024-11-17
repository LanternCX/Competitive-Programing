#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int sum;
	cin >> sum;
	for(int i = 1; i < n; i++){
		int x;
		cin >> x ;
		sum ^= x;
	}
	cout << sum;
	return 0;
}
/**
5
1 1 1 2 3

*/
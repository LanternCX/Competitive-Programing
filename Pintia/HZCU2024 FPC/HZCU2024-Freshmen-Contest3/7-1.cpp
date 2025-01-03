#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> a = {1, 2, 4, 6, 8, 9, 12, 15, 149, 156};
	a.push_back(n);
	sort(a.begin(), a.end());
	for(int i : a){
		printf("%5d", i);
	}
}
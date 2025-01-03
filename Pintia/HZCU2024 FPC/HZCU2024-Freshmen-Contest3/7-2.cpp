#include<bits/stdc++.h>
using namespace std;
int cmp(pair<int, int> x, pair<int, int> y){
	return x.second > y.second;
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	map<int, int> a;
	int n;
	while(cin >> n){
		a[n]++;
	}
	vector<pair<int, int> > b(a.begin(), a.end());
	sort(b.begin(), b.end(), cmp);
//	sort(a.begin(), a.end(), greater<int>());
	cout << b[0].first;
}
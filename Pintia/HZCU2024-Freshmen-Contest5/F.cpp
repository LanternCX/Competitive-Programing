#include<bits/stdc++.h>
using namespace std;
//struct Cmp{
//	bool operator()(int a, int b) const{
//		return
//	}
//};
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, q;
	cin >> n >> q;
	multiset<int, greater<int>> s;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		s.insert(x);
	}
	int sum = 0;
	for(int i = 0; i < q; i++){
		int op;
		cin >> op;
		if(op == 1){
			int w;
			cin >> w;
			s.insert(w);
		}
		if(op == 2){
			int w;
			cin >> w; 
			s.erase(s.lower_bound(w));
		}
		if(op == 3){
			int ans = 0;
			for(int i : s){
				ans = i;
				break;
			}
			s.erase(s.begin());
			cout << ans << '\n';
			sum += ans;
		}
	}
	cout << sum;
	return 0;
}
/**
3 3
5 5 5
3
3
3
*/
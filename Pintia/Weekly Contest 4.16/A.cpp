#include<bits/stdc++.h>

using namespace std;

void sol(){
	int n;
	cin >> n;
	queue<int> a, b;
	for(int i = 1; i <= n; i++){
		a.push(i);
	} 
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		b.push(x);
	}
	int cnt = 1;
	int ans = 0;
	while(!a.empty()){
		if(a.front() != b.front()){
			b.push(b.front());
			b.pop(); 
		}else{
			b.pop();
			a.pop();
			ans += cnt;
//			cout << cnt << '\n';
		}
		cnt++; 
	}
	cout << cnt - 1 << ' ';
	printf("%.1f\n", ans * 1.0 / n);
}

int main(){
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
//	cin >> t;
	while(t--){
		sol();
	}
	return 0; 
} 
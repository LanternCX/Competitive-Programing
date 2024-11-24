#include <bits/stdc++.h>
using namespace std;

int main(){
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	cin >> a[0];
	for(int i = 1; i < n; i++){
		int x;
		cin >> x;
		if(x <= a[i - 1]){
			cout << "Invalid Value";
			return 0;
		}
//		if(lower_bound(a.begin(), a.end(), x) != a.end()){
//			cout << "Invalid Value";
//			return 0;
//		}
		a[i] = x;
	}
	int l = 0, r = n - 1;
	int mid;
	int tag = 0;
	while(l <= r){
		mid = (l + r) / 2;
		printf("[%d,%d][%d]\n", l, r, mid);
		if(x == a[mid]){
			break;
		}
		if(x < a[mid]){
			r = mid - 1;
		}else if(x > a[mid]){
			l = mid + 1;
		}
	}
	if(l > r){
		cout << "Not Found";
	}else{
		cout << mid;
	}
	return 0; 
}
/**
5 5
39 60 80 100 80
*/
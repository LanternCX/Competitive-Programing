#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> arr(n);
	int maxn = INT_MIN;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		maxn = max(maxn, arr[i]);
	}
	int idx = 0;
	for(int i = 0; i < n; i++){
		if(arr[i] == maxn){
			idx = i;
			break;
		}
	}
	cout << maxn << ' ' << idx;
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

int a[10][10];

void sol(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		arr[i] = s[i] - '0';
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		int idx = i;
		for(int j = i + 1; j < n; j++){
			if(arr[j] > arr[idx]){
				idx = j;
			}
		}
		if(idx != i){
			ans = idx;
			break;
		}
	}
	if(ans == 0){
		cout << s << '\n';
		return;
	}
	int flag = 0;
	for(int j = n - 1; j >= ans; j--){
		if(arr[j] == arr[ans]){
			ans = j;
			break;
		}
	}
	int idx0 = 0;
	for(int i = 0; i < n; i++){
		if(arr[ans] > arr[i]){
			idx0 = i;
			break;
		}
	}
	swap(arr[idx0], arr[ans]);
	for(int x : arr){
		cout << x; 
	}
	cout << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
		sol();
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, tag;
	cin >> n >> tag;
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	} 
	int l, r;
	l = lower_bound(arr.begin(), arr.end(), tag) - arr.begin();
	r = l;
	for(int i = l + 1; i < arr.size(); i++){
		if(arr[i] == tag){
			r++;
		}
	}
	printf("[%d, %d]", l, r); 
	return 0; 
}
/**
5 5
39 60 80 100 80
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	while(cin >> n){
		vector<string> arr(n);
		for(int i = 0; i < n; i++){
			cin >> arr[i];
			arr[i] = arr[i].substr(2, arr[i].length() - 2);
		}
//		for(int i = 0; i < n; i++){
//			cout << arr[i] << ' ';
//		}
		sort(arr.begin(), arr.end(), [](string a, string b) -> int {
			string s = "0.";
			return stof(s + a + b) < stof(s + b + a);
		});
		string ans = "0.";
		for(string s : arr){
			ans += s;
		}
		cout << ans << '\n';
	}
	
	return 0;
} 
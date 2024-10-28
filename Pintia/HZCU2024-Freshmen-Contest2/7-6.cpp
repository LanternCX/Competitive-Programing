#include<bits/stdc++.h>
using namespace std;
int strtoint(string s){
	int digit = 1;
	int res = 0;
	for(int i = 0; i < s.size(); i++){
		res *= 10;
		res += s[i] - '0';
	}
	return res;
}
int cmp(string a, string b){
	if(strtoint(a + b) > strtoint(b + a)){
		return 1;
	}
	return 0;
}
void slove(int n){
	vector<string> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end(), cmp);
	string s;
	for(int i = 0; i < arr.size(); i++){
		s += arr[i];
	}
	cout << s << '\n';
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	while(cin >> n){
		slove(n);
	}
	return 0;
}
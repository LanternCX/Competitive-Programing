#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
    cin >> n;
    vector<string> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end(), [](string a, string b) -> int {
        return stoll(a + b) > stoll(b + a);
    });
	string s;
	for(int i = 0; i < arr.size(); i++){
		s += arr[i];
	}
	cout << s << '\n';
	return 0;
}
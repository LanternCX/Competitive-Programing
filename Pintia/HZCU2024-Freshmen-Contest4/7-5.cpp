#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct stu{
	string name;
	int sc;
};
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	vector<stu> arr;
	for(int i = 0; i < 10; i++){
		stu s;
		cin >> s.name;
		arr.push_back(s);
	}
	for(int i = 0; i < 10; i++){
		cin >> arr[i].sc;
	}
	sort(arr.begin(), arr.end(), [](stu a, stu b) -> int {
		return a.name < b.name;
	});
	for(stu s : arr){
		cout << s.name << ',' << s.sc << '\n';
	}
	return 0;
}
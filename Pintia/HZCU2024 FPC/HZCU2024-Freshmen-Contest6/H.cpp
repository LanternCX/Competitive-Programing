#include <bits/stdc++.h>
using namespace std;
int main(){
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a, b;
	cin >> a >> b;
	map<int, string> dict;
	dict[0] = "ling";
	dict[1] = "yi";
	dict[2] = "er";
	dict[3] = "san";
	dict[4] = "si";
	dict[5] = "wu";
	dict[6] = "liu";
	dict[7] = "qi";
	dict[8] = "ba";
	dict[9] = "jiu";
	cout << dict[a] << ' ' << dict[b] << '\n';
	return 0; 
}
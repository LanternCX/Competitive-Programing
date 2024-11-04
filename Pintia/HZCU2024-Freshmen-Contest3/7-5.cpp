#include<bits/stdc++.h>
using namespace std;
struct num{
	int n;
	int is;
}; 
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> a; 
	vector<num> b; 
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if(x > 0){
			a.push_back(x);
		}else{
			num temp;
			temp.n = x;
			temp.is = 0;
			b.push_back(temp);
		}
	}
	
	sort(a.begin(), a.end());
	int ans = 0;
	
	for(int i = 0; i < a.size(); i++){
		for(int j = 0; j < b.size(); j++){
			if(a[i] == -b[j].n && !b[j].is){
				b[j].is = 1;
				ans++;
				break;
			}
		}
	}
	cout << ans;
}
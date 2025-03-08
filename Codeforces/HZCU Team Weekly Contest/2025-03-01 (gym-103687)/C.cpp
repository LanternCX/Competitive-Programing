#include<bits/stdc++.h> 

using namespace std;
using ll = long long;
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); 
	int n, m, x;
	cin >> n >> m >>x;
	vector<int> a(n), b(m);
	ll cnt = 0;
	for(auto &num : a){
		cin >>num;
		 if(num >= x){
		 	cnt++;
		 }
	}
	for(auto &num : b){
		cin >>num;
		 if(num <= x){
		 	cnt++;
		 }
	}
	
	cout <<cnt;
	return 0;
}
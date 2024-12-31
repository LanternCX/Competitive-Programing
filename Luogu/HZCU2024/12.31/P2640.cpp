#include <bits/stdc++.h>
using namespace std;
int isP(int n){
	for(int i = 2; i < n; i++){
		if(n % i == 0){
			return 0;
		}
	}
	return 1;
}
int main(){
	int n, k;
	cin >> n >> k;
	int is = 0;
	for(int i = 2; i <= n; i++){
		if(isP(i) && isP(i + k) && i + k <= n){
			cout << i << ' ' << i + k << '\n';
			is = 1;
		}
	}
	if(!is){
		cout << "empty\n";
	}
	return 0; 
} 
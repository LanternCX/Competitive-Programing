#include <bits/stdc++.h>
using namespace std;
void sol(double x){
//	cout << x << '\n';
	double sum = 0;
	double a = 2;
	while(1){
		sum += 1.0 / a;
//		cout << sum << '\n';
		if(sum >= x){
			break;
		}
		a++;
	}
	cout << a - 1 << " card(s)\n"; 
//	printf("%d card(s)\n", (a - 1));
}
int main(){
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	vector<double> arr;
	double x;
	while(cin >> x){
		if(x == 0){
			break;
		}
		sol(x);
	}
	return 0; 
}
/**
5 5
39 60 80 100 80
*/
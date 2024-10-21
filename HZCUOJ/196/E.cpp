#include <bits/stdc++.h>
using namespace std;

void slove(){
	int a, b, c;
	cin >> a >> b >> c;
	char ans;
	if(a + b == c){
		ans = '+';
	}else{
		ans = '-';
	}
	cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	while(n--){
		slove();
	}
} 

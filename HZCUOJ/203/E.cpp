#include <bits/stdc++.h> 

using namespace std;
const int N = 10000 + 10;

bool p[N];
void ai(){
    for(int i = 0; i < N; i++){
        p[i] = true;
    }
    p[0] = p[1] = false;
    for(int i = 2; i * i < N; i++){
        if(p[i]){
            for(int j = i * i; j < N; j += i){
                p[j] = false;
            }
        }
    }
}
vector<int> pr;
using ll = long long;
void sol(){
	while(1){
		ll n;
		cin >> n;
		if(n == 0){
			return;
		}
		ll ans = 0;
		for(auto x : pr){
//			cerr << x << ' ';
			if(x > n){
				break;
			}
			if(p[n - x]){
				ans++;
			}
		}
		cout << ans / 2 << '\n';
	}
	
}
void init(){
	for(int i = 0; i < N; i++){
		if(p[i]){
//			cerr << i << ' ';
			pr.push_back(i);
		}
	}
} 

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	ai();
	init();
//	cin >> t;
	while(t--){
		sol();
	}
	return 0;
} 
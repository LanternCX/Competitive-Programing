#include <bits/stdc++.h>
using namespace std;
const int N = 998244353;
using ll = long long;
ll binpow(ll a, ll b){
    if(b == 0){
        return 1;
    }
    if(b % 2 == 0){
        ll temp = binpow(a, b / 2) % N;
        return temp * temp;
    }else{
        ll temp = binpow(a, b - 1) % N;
        return ( a % N )* temp;
    }
}
int main(){
	ll n, k;
	cin >> n >> k;
	cout << binpow(binpow(2, k) - 1, n) % N;
	return 0; 
}
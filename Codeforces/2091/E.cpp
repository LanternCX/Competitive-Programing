#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "include/debug.cpp"
#else
#define debug(...) (void)(0)
#endif
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
struct Sieve{
    int n;
    vector<bool> p;

    Sieve(int n): n(n), p(n){
        for(int i = 0; i < n; i++){
            p[i] = true;
        }
        p[0] = p[1] = false;
        for(int i = 2; i * i < n; i++){
            if(p[i]){
                for(int j = i * i; j < n; j += i){
                    p[j] = false;
                }
            }
        }
    };
};
vector<int> p;
void init(){
    Sieve s(1e7);
    for(int i = 0; i < 1e7; i++){
        if(s.p[i]){
            p.push_back(i);
        }
    }
}
int gcd(int a, int b){return b == 0 ? a : gcd(b, a % b);}
int lcm(int a, int b){return (a * b) / gcd(a, b);}
void sol(){
    int n;
    cin >> n;
    ll cnt = 0;
    for (int p : p) {
        if (p > n) break;
        cnt += (n / p);
    }
    cout << cnt << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    init();
    while (t--){
        sol();
    }
    return 0;
}
/**
 * lcm(a, b) / gcd(a, b) = p
 * 
 * (a * b) = p * gcd(a, b) * gcd(a, b)
 * 
 * 
 * lcm(a, b) * gcd(a, b) = a * b
 * 
 * lcm(a, b) = (a * b) / gcd(a, b)
 */;
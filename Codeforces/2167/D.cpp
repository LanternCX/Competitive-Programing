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
int gcd(int a, int b){return a % b == 0 ? b : gcd(b, a % b);}
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

void init() {
    Sieve sieve(1000);
    for (int i = 2; i < 1e3; i++) {
        if (sieve.p[i]) {
            p.push_back(i);
        }
    }
 }

void sol() {
    int n;
    cin >> n;
    ll mx = 0;
    vector<ll> arr(n);
    for (auto &x : arr) {
        cin >> x;
        mx = max(mx, x);
    }

    auto check = [&](ll p) {
        for (auto x : arr) {
            if (gcd(x, p) == 1) {
                return 1;
            }
        }
        return 0;
    };

    for (auto x : p) {
        if (check(x)) {
            cout << x << '\n';
            return;
        }
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    init();
    while (t--){
        sol();
    }
    return 0;
}
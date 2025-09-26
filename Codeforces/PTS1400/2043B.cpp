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
void sol(){
    int d, n;
    std::cin >> n >> d;
    std::cout << 1 << ' ';
    if (n >= 3 || d % 3 == 0) {
        std::cout << 3 << ' ';
    }
    if (d == 5) {
        std::cout << 5 << ' ';
    }
    if (n >= 3 || d % 7 == 0) {
        std::cout << 7 << ' ';
    }
    if (n >= 6 || d % 9 == 0 || (n >= 3 && d % 3 == 0)) {
        std::cout << 9 << ' ';
    }
    std::cout << '\n';
}
void test() {
    // for (int i = 1; i <= 9; i++) {
    //     string s;
    //     for (int j = 0; j < 18; j++) {
    //         s.push_back('0' + i);
    //         ll x = stoll(s);
    //         debug(x);
    //         if (x % 9 == 0) {
    //             std::cout << x << '\n';
    //         }
    //     }
    // }
    ll res = 1;
    for (int i = 1; i <= 9; i++) {
        res *= i;
        debug(res % 9, i);
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--){
        sol();
    }
    return 0;
}
/**
 * 1 3 5 7 9
 * 
 * 1 * 2 * 3
 */
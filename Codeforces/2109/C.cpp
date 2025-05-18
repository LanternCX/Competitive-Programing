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
    ll n;
    cin >> n;
    int _;
    for (int i = 0; i < 3; i++) {
        cout << "digit\n";
        cout.flush();
        cin >> _;
    }
    cout << "mul 9\n";
    cout.flush();
    cin >> _;
    cout << "digit\n";
    cout.flush();
	cin >> _;
    cout << "div 9\n";
    cout.flush();
    cin >> _;
    cout << "mul " << n << '\n';
    cout.flush();
    cin >> _;
    cout << "!\n";
    cout.flush(); 
    cin >> _;
}
int main(){
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--){
        sol();
    }
    return 0;
}
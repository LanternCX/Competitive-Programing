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
const int N = 1e6;
void sol(){
    int n;
    cin >> n;
    vector<int> a(n);

    vector<int> p(N, 1);
    auto ai = [&]{
        p[0] = 0;
        p[1] = 0;
        for(int i = 2; i * i < N; i++){
            if(p[i]){
                for(int j = i * i; j < N; j += i){
                    p[j] = 0;
                }
            }
        }
    };
    ai();
    
    for(auto &x : a){
        cin >> x;
        if(p[x]){
            cout << x << ' ';
        }
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--){
        sol();
    }
    return 0;
}
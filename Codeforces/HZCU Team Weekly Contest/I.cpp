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
    int A, B;
    cin >> A >> B;
    auto work = [&](int a, int b, int c){
        int res = 0;
        if(a == 4 || a == 1){
            res += a;
        }
        if(b == 4 || b == 1){
            res += b;
        }
        if(c == 4 || c == 1){
            res += c;
        }
        return res;
    };
    for(int i = 1; i <= 6; i++){
        for(int j = 1; j <= 6; j++){
            for(int k = 1; k <= 6; k++){
                int a = work(i, j, k);
                int b = i + j + k - a;
                if(a == A && b == B){
                    cout << "Yes\n";
                    return;
                }
            }
        }
    }
    cout << "No\n";
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
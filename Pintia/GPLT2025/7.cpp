#include <bits/stdc++.h>
using namespace std;
#define int long long
int binpow(int a, int n){
    if(n == 0){
        return 1;
    }
    if(n == 1){
        return a;
    }
    if(n % 2 == 0){
        int res = binpow(a, n / 2);
        return res * res;
    }
    if(n % 2 == 1){
        int res = binpow(a, n - 1);
        return res * a;
    }
    return -1;
}
void sol(){
    int n;
    cin >> n;
    auto work = [&](int x){
        int sum = 0;
        for(int i = x; (1LL << i) <= n; i++){
            sum = 0;
            for(int j = 1; j < 1e5; j++){
                int det = binpow(j, i);
                sum += det;
                if(sum == n){
                    return pair<int, int>(i, j);
                }else if(sum > n){
                    break;
                }
            }
        }
        return pair<int, int>(-1, -1);
    };
    int x = 1;
    auto [a, b] = work(x);
    while(a != -1 && b != -1){
        auto [ax, bx] = work(++x);
        if(ax != -1 && bx != -1){
            a = ax, b = bx;
        }else{
            break;
        }
    }
    if(a == -1 || b == -1){
        cout << "Impossible for " << n << ".\n";
    }else{
        for(int i = 1; i <= b; i++){
            cout << i << '^' << a << "+\n"[i == b];
        }
    }
}
void test(){
    int n = 1LL << 31;
    int sum = 0;
    for(int i = 1; (1LL << i) <= n; i++){
        cout << i << ' ';
    }
}
signed main(){
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        sol();
        // test();
    }
}

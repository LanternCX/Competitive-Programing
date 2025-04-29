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
int gcd(int a, int b){return b == 0 ? a : gcd(b, a % b);}
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
void sol(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x : a){
        cin >> x;
    }

}
void init(){
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
 * 如果所有元素互质那么就满足
 * 
 * 也就是说构造一个质数序列
 * 
 * 实际上就是在判断能否将原数列转换为一个质数数列
 * 
 * 数组的 sum 只能减少不能增加
 */
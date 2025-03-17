#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
void sol(){
    ll n;
    cin >> n;
    cout << (n / 15) * 3 + min(n % 15 + 1, 3LL) << '\n';
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
 * a * 3 + x = b * 5 + x = n
 * 
 * n - x = a * 3
 * n - x = b * 5
 * 
 * 也就是说 n - x 是十五的倍数
 * x 可以取 0 1 2
 * 
 * 也就是说求出
 * 0 ~ n 有多少个 15 的倍数
 * 然后对末尾进行判断
 */
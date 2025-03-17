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
    int n;
    cin >> n;
    cout << ((n - 1) % 3 ? "NO\n" : "YES\n");
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
 * 1 2 3 4 5
 * 0 1 0 1 0
 * 0 1 1 0 1
 * 
 * 实际上是一个 0 1 串
 * 
 * 0 后面必须接 1 
 * 1 1 1 后面必须接 0
 * 
 * 0 在哪个位置不可能出现?
 * 
 * 所以有分片
 * 0 1 0
 * 0 1 1 0
 * 0 1 1 1 0
 * 
 * 
 * 0 1 0 1 0 1 0 1 0 
 * 1 1 0
 * 1 1 1 0 
 * 
 * n - 1 == 2 * a + 3 * b + 4 * c
 * 问是否存在合法的 a b c 成立
 */
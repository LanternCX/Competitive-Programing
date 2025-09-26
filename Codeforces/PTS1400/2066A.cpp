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
    vector<int> a(n);
    set<int> s;
    for(auto &x : a){
        cin >> x;
        s.insert(x);
    }
    if(s.size() == n){
        int x, y;
        for(int i = 0; i < n; i++){
            if(a[i] == 1){
                x = i;
            }
            if(a[i] == n){
                y = i;
            }
        }
        x++, y++;
        cout << "? " << x << ' ' << y << '\n';
        int d1, d2;;
        cin >> d1;
        cout << "? " << y << ' ' << x << '\n';
        cin >> d2;
        if(d1 == d2 && d1 >= n - 1){
            cout << "! B\n"; 
        }else {
            cout << "! A\n";
        }
        return;
    }else{
        for(int i = 1; i <= n; i++){
            if(!s.count(i)){
                cout << "? " << i << ' ' << ((i == 1) ? 2 : 1) << '\n';
                int d;
                cin >> d;
                if(d == 0){
                    cout << "! A\n";
                }else{
                    cout << "! B\n";
                }
                return;
            }
        }
    }
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
/**
 * 曼哈顿距离是
 * |xi−xj| + |yi−yj|
 * 至少是
 * |xi−xj|
 * 
 * 如果查询 i j 的返回小于 |xi−xj| 就一定是 A
 * 
 * 对于 A 查询 i j 最大是 n 如果大于 n 一定是 B 
 * 
 * 首先构造一个查询
 * ? 1 2
 * 返回 x 
 * 判断
 * 
 * 为什么是两次？ 
 */
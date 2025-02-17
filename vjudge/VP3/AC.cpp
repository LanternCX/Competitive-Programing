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
void sol(){
    vector<pii> arr;
    for(int i = 1; i <= 20; i++){
        for(int j = 1; j <= 21; j++){
            arr.push_back({i, j});
        }
    }
    set<pair<int, pii>> s;
    for(int i = 0; i < arr.size(); i++){
        for(int j = i + 1; j < arr.size(); j++){
            int x1 = arr[i].first, y1 = arr[i].second;
            int x2 = arr[j].first, y2 = arr[j].second;
            
            int a = x2 - x1, b = y2 - y1, c = x1 * y2 - x2 * y1;

            int g = gcd(a, gcd(b, c));
            s.insert({(a + g) / g, {(b + g) / g, (c + g) / g}});
        }
    }
    cout << s.size();
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
/**
 * 过 A(x1, y1) B(x2, y2) 的点的解析式
 * (y - y1) / (y2 - y1) = (x - x1) / (x2 - x1)
 * -> (x - x1) * (y2 - y1) = (y - y1) * (x2 - x1)
 * -> x * (y2 - y1) - x1 * (y2 - y1) = y * (x2 - x1) - y1 * (x2 - x1)
 * -> {(y2 - y1), (x2 - x1), x1 * (y2 - y1) - y1 * (x2 - x1)} 三项约分后直线唯一
 *  x1 * (y2 - y1) - y1 * (x2 - x1) = x1 * y2 - x1 * y1 - y1 * x2 + x1 * y1 = x1 * y2 - x2 * y1
 * 所以只需要对 {(y2 - y1), (x2 - x1), (x1 * y2 - x2 * y1)} 三项去重
 */
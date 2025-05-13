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
struct node {
    double x, y;
};
void sol(){
    int N;
    cin >> N;
    vector<node> p(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> p[i].x >> p[i].y;
    }

    double s = 0.0;
    double x = 0.0, y = 0.0;

    for (int i = 0; i < N; ++i) {
        int j = (i + 1) % N;
        double temp = p[i].x * p[j].y - p[j].x * p[i].y;
        s += temp;
        x += (p[i].x + p[j].x) * temp;
        y += (p[i].y + p[j].y) * temp;
    }

    s *= 0.5;
    x /= (6 * s);
    y /= (6 * s);

    cout << x << " " << y << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(2);
    int t = 1;
    cin >> t;
    while (t--){
        sol();
    }
    return 0;
}
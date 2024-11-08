#include <bits/stdc++.h>
using namespace std;
struct point{
    int x;
    int y;
    int z;
};
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<point> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].x >> a[i].y >> a[i].z;
    }
    sort(a.begin(), a.end(), [](point a, point b) -> int {
        return a.z < b.z;
    });
    double ans = 0;
    for(int i = 0; i < n - 1; i++){
        ans += sqrt(pow(a[i].x - a[i + 1].x, 2) + pow(a[i].y - a[i + 1].y, 2) + pow(a[i].z - a[i + 1].z, 2));
    }
    printf("%.3lf", ans);
    return 0;
}
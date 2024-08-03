#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int a[2], b[2], c[2];
    cin >> n;
    cin >> a[0] >> a[1] >> b[0] >> b[1] >> c[0] >> c[1];
    int p1 = ceil(n / (a[0] * 1.0)) * a[1];
    int p2 = ceil(n / (b[0] * 1.0)) * b[1];
    int p3 = ceil(n / (c[0] * 1.0)) * c[1];
    int p[3] = {p1, p2, p3};
    sort(p, p + 3);
    cout << p[0];
    return 0;
}
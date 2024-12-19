#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){return a % b == 0 ? b : gcd(b, a % b);}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a1, a2;
    int b1, b2;
    string s1, s2;
    scanf("%d/%d", &a1, &b1);
    scanf("%d/%d", &a2, &b2);
    // cin >> a1 >> b1 >> a2 >> b2;
    int a = a1 * a2;
    int b = b1 * b2;
    int n = gcd(a, b);
    cout << b / n << ' ' << a / n;
    return 0;
}
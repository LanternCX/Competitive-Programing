#include <bits/stdc++.h>
using namespace std;
double a, b, c, d;
const double eps = 0.00001;
const double inf = 1e3;
double f(double x){
    return a * x * x * x + b * x * x + c * x + d; 
}
double calc(double l, double r){
    double mid;
    while(abs(r - l) >= eps){
        mid = (l + r) / 2;
        // cout << l << ' ' << r << endl;
        if(f(mid) == 0){
            return mid;
        }
        if(f(mid) * f(r) <= 0){
            l = mid;
        }else{
            r = mid;
        }
    }

    mid = (l + r) / 2;
    return mid;
}
void sol(){
    cin >> a >> b >> c >> d;
    if(a == 0){
        cout << "No\n";
        return;
    }else{
        cout << "Yes\n";
    }
    double db = 2 * b, da = 3 * a, dc = c;
    double det = db * db - 4 * da * dc;
    double temp1 = (-db - sqrt(det)) / (2 * da);
    double temp2 = (-db + sqrt(det)) / (2 * da);
    double x1 = min(temp1, temp2);
    double x2 = max(temp1, temp2);
    // cout << det << ' ' << x1 << ' ' << x2 << endl;
    double l, r, mid;

    l = -inf, r = inf;
    if(det < 0){
        l = -inf, r = inf;
    }else{
        if(f(l) * f(x1) < 0){
            l = -inf, r = x1;
        }else if(f(x1) * f(x2) < 0){
            l = x1, r = x2;
        }else{
            l = x2, r = inf;
        }
    }
    printf("%.4lf\n", calc(l, r));
}
int main(){
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        sol();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
double a, b, c ,d;
const double eps = 0.001;
double f(double x){
    return a * x * x * x + b * x * x + c * x + d;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> a >> b >> c >> d;

    vector<int> ans;
    for(int i = -100; i <= 100; i++){
        double l = i;
        double r = i + 1;
        if(f(l) == 0){
            printf("%.2lf ", l);
        }
        if(f(l) * f(r) < 0){
            while (r - l > eps) {
                double mid = (l + r) / 2;
                if(f(l) * f(mid) <= 0){
                    r = mid;
                }else {
                    l = mid;
                }
            }
            printf("%.2lf ", l);
        }
    }

    return 0;
}
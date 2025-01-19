#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    double s, a, b;
    cin >> s >> a >> b;
    double l = 0, r = s;
    double ans = 0;
    while(abs(l - r) > 1e-8){
        double mid = (l + r) / 2;
        double t1 = mid / b;
        double t2 = (mid - t1 * a) / (a + b);
        double t3 = t1 + (s - mid) / a;
        double t4 = t1 + t2 + (s - (t1 + t2) * a) / b;
        ans = t3;
        if(t3 < t4){
            r = mid;
        }else if(t3 > t4){
            l = mid;
        }else if(abs(t3 - t4) < 1e-8){
            break;
        }
    }
    printf("%.6lf", ans);
    return 0;
}
/**
 * v = w1v1 + w2v2
 * 
 */
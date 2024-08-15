#include <bits/stdc++.h>
using namespace std;
double getD(double x1, double y1, double x2, double y2){
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
int main(){
    double x[3], y[3];
    double ans = 0;
    for(int i = 0; i < 3; i++){
        cin >> x[i] >> y[i];

    }
    ans += getD(x[0], y[0], x[1], y[1]);
    ans += getD(x[0], y[0], x[2], y[2]);
    ans += getD(x[1], y[1], x[2], y[2]);
    cout << fixed << setprecision(2) << ans;
    return 0;
}
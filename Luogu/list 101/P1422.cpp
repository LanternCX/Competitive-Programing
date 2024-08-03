#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    double ans;
    cin >> n;
    if(n <= 150){
        ans = n * 0.4463; 
    }else if(n > 150 && n <= 400){
        ans = 150 * 0.4463 + (n - 150) * 0.4663;
    }else if(n > 400){
        ans = 150 * 0.4463 + (400 - 150) * 0.4663 + (n - 400) * 0.5663;
    }
    cout << fixed << setprecision(1) << ans;
    return 0;
}
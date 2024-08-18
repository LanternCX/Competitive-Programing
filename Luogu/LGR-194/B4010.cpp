#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    double max = -114514;
    int num = 114514;
    int ans = -1;
    for(int i = 1; i <= n; i++){
        double a, b;
        cin >> a >> b;
        double w = b / a;
        if(max < w || abs(max - w) <= 1e-10 && a <= num){
            max = w;
            num = a;
            ans = i;
        }
    }
    cout << ans;
    return 0;
}
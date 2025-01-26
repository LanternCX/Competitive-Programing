#include <bits/stdc++.h>
using namespace std;
void sol(){
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int ans = 0;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(c - i - j >= 0 && -b - c + n + i >= 0 && a + b - n + j >= 0 && -a + n - i - j >= 0){
                ans = 1;
                break;
            }
        }
    }
    cout << (ans ? "Yes" : "No") << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        sol();
    }
    return 0;
}
/**
 * x1 + x2 + x3 = a
 * x1 + x6 + x5 = c
 * x3 + x4 + x5 = b
 * x1 + x2 + x3 + x4 + x5 + x6 = n
 * 
 * x1 = c - t1 -t2
 * x2 = -b - c + n + t1
 * x3 = a + b - n + t2
 * x4 = -a + n - x5 - x6
 * 
 */
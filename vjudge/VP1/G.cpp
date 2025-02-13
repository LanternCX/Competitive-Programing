#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a, b;
    cin >> a >> b;
    int n;
    cin >> n;
    auto work = [&](int a, int b, int n){
        string res;
        a -= (a / b) * b;
        while(a < b){
            a *= 10;
            res.push_back((a / b) + '0');
            a -= (a / b) * b;
            // cout << a << ' ' << b << '\n';
            if(res.size() > n + 3){
                break;
            }
        }
        return res;
    };
    cout << work(a, b, n).substr(n - 1, 3);
    return 0;
}
/**
 * 31 / 3
 * 3 / 3 = 1
 * 1 / 3
 */
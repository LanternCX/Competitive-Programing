#include <bits/stdc++.h>
using namespace std;
void slove(){
    int n;
    cin >> n;
    int max = n / 2;
    int min = n / 4 + n % 4 / 2;
    if(n % 2 == 1){
        max = min = 0;
    }
    cout << min << ' ' << max << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    while (n--) {
        slove();
    }
    return 0;
}
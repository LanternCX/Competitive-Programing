#include <bits/stdc++.h>
using namespace std;
void slove(){
    int n;
    cin >> n;
    int sum1 = 0, sum2 = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x % 2 == 0){
            sum1 += x;
        }else {
            sum2 += x;
        }
    }
    if(sum1 > sum2){
        cout << "YES" << '\n';
    }else {
        cout << "NO" << '\n';
    }
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
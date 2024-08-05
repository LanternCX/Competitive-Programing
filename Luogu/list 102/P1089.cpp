#include <bits/stdc++.h>
using namespace std;
int main(){
    int leave = 0;
    int bank = 0;
    double ans = 0;
    for(int i = 1; i <= 12; i++){
        int need = 0;
        cin >> need;

        // 共有
        int hand = leave + 300;

        // 存
        bank += (hand - need) / 100 * 100;
        hand -= (hand - need) / 100 * 100;

        // 结算
        leave = hand - need;
        if(leave < 0 && ans >= 0){
            ans = -1 * i;
        }
    }
    ans = ans == 0 ? bank * 1.2 + leave : ans;
    cout << ans;
    return 0;
}
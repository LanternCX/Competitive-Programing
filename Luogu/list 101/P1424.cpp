#include <bits/stdc++.h>
using namespace std;
int main(){
    int x,n,ans;
    cin >> x >> n;
    int work = 0;
    for (int i = 0; i <  n % 7 ; i++){
        if(x + i == 6 || x + i == 7){
            continue;
        }
        work += 1;
    }
    ans = (work + 5 * (n / 7)) * 250;
    cout << ans;
    return 0;
}
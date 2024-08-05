#include <bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin >> k;
    int an = 1, ans = 0;
    while( k >= an){
        k -= an;
        ans += an * an;
        an += 1;
    }
    ans += an * k;
    cout << ans;
    return 0;
}
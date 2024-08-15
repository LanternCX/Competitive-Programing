#include <bits/stdc++.h>
using namespace std;
int ans = 1;
void mul(int n){
    ans *= n;
    if(n > 1){
        mul(n - 1);
    }
}
int main(){
    int n;
    cin >> n;
    mul(n);
    cout << ans;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int count = 1;
    int ans = 1;
    int a1,a2;
    cin >> n;
    cin >> a1;
    for(int i = 0; i < n - 1; i++){
        cin >> a2;
        if(a1 == a2 - 1){
            count += 1;
            ans = ans > count ? ans : count;
        }else if(count != 1){
            count = 1;
        }
        a1 = a2;
    }
    cout << ans;
    return 0;
}
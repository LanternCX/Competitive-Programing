#include <bits/stdc++.h>
using namespace std;
void sol(){
    int n;
    cin >> n;
    if(n % 33 == 0){
        cout << "YES";
    }else {
        cout << "NO";
    }
    cout << '\n';
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
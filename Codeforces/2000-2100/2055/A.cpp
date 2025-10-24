#include <bits/stdc++.h>
using namespace std;
void sol(){
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    if(abs(b - c) % 2 == 0){
        ans = 1;
    }else{
        ans = 0;
    }
    cout << (ans ? "YES\n" : "NO\n");
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
// 1 2
// 1 2

// 1 2 3
// 1   2

// 1 2 3 4
//   2 3

// 1 2 3 4 5 
//   2   4

// 1 2 3 4 5 6 7
// 

// 1 2 3 4 5
// 1       4
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
void sol(){
    int n; 
    cin >> n;

    if(n <= 3){
        cout << 0 << '\n';
        return;
    }

    if(n <= 5){
        cout << "1\n2 3 4\n";
        return;
    }

    int p = n / 3;
    cout << p << '\n';
    if(p % 2 == 0){
        for(int i = 1; i + 5 <= n; i += 6){
            cout << i << ' ' << i + 1 << ' ' << i + 3 << '\n';
            cout << i + 2 << ' ' << i + 4 << ' ' << i + 5 << '\n';
        }
    }else{
        cout << "1 2 4\n3 5 9\n6 7 8\n";
        for(int i = 10; i + 5 <= n; i += 6){
            cout << i << ' ' << i + 1 << ' ' << i + 4 << '\n';
            cout << i + 2 << ' ' << i + 3 << ' ' << i + 5 << '\n';
        }
    }
     
    return ;
}
signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        sol();
    }
    return 0;
}
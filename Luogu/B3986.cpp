#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int tag = n - 1;
    for(int i = 0; i < n; i++){
        cout << 'Z';
    }
    cout << '\n';
    for(int i = 0; i < n - 2; i++){
        tag--;
        for(int j = 0; j < n; j++){
            cout << (j != tag ?  '-' : 'Z');
        }
        cout << '\n';
    }
    for(int i = 0; i < n; i++){
        cout << 'Z';
    }
    return 0;
}
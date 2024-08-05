#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n * n; i++){
        cout << (i < 10 ? "0" + to_string(i) : to_string(i));
        if(i % n == 0){
            cout << endl;
        } 
    }
    cout << endl;

    int a = 1;
    int l = 1;
    for(int i = 1; i <= n * n; i++){
        if( i % n == 1){
            for(int j = 0; j < n - l; j++){
                cout << "  ";
            }
        }

        if( i % n == n - l){
            for(int j = 0; j < l; j++){
                cout << (a < 10 ? "0" + to_string(a) : to_string(a));
                a += 1;
            }
        }

        if(i % n == 0){
            l += 1;
            cout << endl;
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i = 100; i >= 1; i--){
        int k = (int)ceil(((n * 1.0 / 52 / 7) - i));
        if( k % 3 == 0 && k > 0){
            cout << i << endl << (k / 3) << endl;
            break;
        }
    }
    return 0;
}
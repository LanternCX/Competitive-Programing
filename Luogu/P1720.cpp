#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long a[100];
    a[1] = 1;
    a[2] = 1;
    a[0] = 0;
    if(n <= 2){
        cout << a[n] << ".00";
        return 0;
    }
    for(int i = 3; i <= n; i++){
        a[i] = a[i - 1] + a[i - 2];
    }
    // for(int i = 0; i <= n; i++){
    //     cout << a[i] << endl;
    // }
    cout << a[n] << ".00";
    return 0;
}

/**
 * 1 1 2 3 5 8 13
 */
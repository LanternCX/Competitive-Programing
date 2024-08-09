#include <bits/stdc++.h>
using namespace std;
long long c(int n, int r){
    long long a = 1,b = 1,c = 1;
    for(int i = 2; i <= n; i++){
        a *= i;
    }
    for(int i = 2; i <= r; i++){
        b *= i;
    }
    for(int i = 2; i <= n - r; i++){
        c *= i;
    }
    return a / (b * c);
}
int main(){
    long long n;
    cin >> n;
    cout << 1 << endl;
    for(int i = 1; i <= n - 1; i++ ){
        for(int j = 1; j <= i + 1; j++){
            cout << c(i,j - 1);
            if(j == i + 1){
                cout << endl;
            }else {
                cout << ' ';
            }
        }
    }
    return 0;
}
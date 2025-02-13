#include <bits/stdc++.h>
using namespace std;

int p = 1;
int binpow(int a, int b){
    if(b == 0){
        return 1;
    }
    if(b % 2 == 0){
        int res = binpow(a, b / 2) % p;
        return (res % p * res) % p;
    }else{
        int res = binpow(a, b - 1) % p;
        return ((a % p) * res) % p;
    }
}

int main(){
    int a,b;
    cin >> a >> b;
    cout << binpow(a, b);
    return 0;
}
/**
 *  (a + b) % p == (a % p + b % p) % p
 */
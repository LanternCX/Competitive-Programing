#include <bits/stdc++.h>
using namespace std;

int binpow(int a, int b){
    if(b == 0){
        return 1;
    }
    if(b % 2 == 0){
        int res = binpow(a, b / 2);
        return res * res;
    }else{
        int res = binpow(a, b - 1);
        return a * res;
    }
}

int main(){
    int a,b;
    cin >> a >> b;
    cout << binpow(a, b);
    return 0;
}
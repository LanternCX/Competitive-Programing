#include <bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin >> a;
    int i = 1;
    while(a != 1){
        a /= 2;
        i += 1;
    }
    cout << i;
    return 0;
}
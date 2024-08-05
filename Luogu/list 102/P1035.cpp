#include <bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin >> k;
    double sn = 0;
    double an = 1;
    double i = 0;
    while(sn <= k){
        i += 1;
        an = 1 / i;
        sn += an;
    }
    cout << i;
    return 0;
}
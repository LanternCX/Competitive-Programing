#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int an[101];
    cin >> n;
    int i = 1;
    an[0] = n;
    while(n != 1){
        if(n % 2 == 1){
            n *= 3;
            n += 1;
            an[i] = n;
            i++;
        }else{
            n /= 2;
            an[i] = n;
            i++;
        }
    }

    i -= 1;
    for(; i >= 0; i-- ){
        cout << an[i] << ' ';
    }
    return 0;
}
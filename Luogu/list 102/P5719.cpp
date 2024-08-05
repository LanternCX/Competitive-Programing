#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    int aa = 0,an = 0,bb = 0,bn = 0;
    for(int i = 1; i <= n; i++){
        if(i % k == 0){
            aa += i;
            an += 1;
        }else{
            bb += i;
            bn += 1;
        }
    }
    cout << fixed << setprecision(1) << (aa * 1.0 / an)<< " " << (bb * 1.0 / bn);
    return 0;
}
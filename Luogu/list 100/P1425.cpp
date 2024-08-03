#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int t = c * 60 + d - (a * 60 + b);
    cout << ((t - t % 60)/60) << ' ' << t % 60;
    return 0;
}
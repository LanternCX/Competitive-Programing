#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
string fun(int x, int y, int z){
    if (x > y){
        return (to_string(y / gcd(y,z)) + "/" + to_string(z / gcd(y,z)));
    }else{
        return (to_string(x / gcd(x,z)) + "/" + to_string(z / gcd(x,z)));
    }
    
}
int main(){
    int a,b,c;
    string ans = "";
    cin >> a >> b >> c;
    int maxnum = max({a , b , c});
    if(maxnum == a){
        ans = fun(b , c , a);
    }
    if(maxnum == b){
        ans = fun(a , c , b);
    }
    if(maxnum == c){
        ans = fun(a , b , c);
    }
    cout << ans;
    return 0;
}
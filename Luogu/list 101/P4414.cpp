#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    string str;
    cin >> a >> b >> c;
    cin >> str;
    int C = max({a,b,c});
    int A = min({a,b,c});
    int B = 0;
    if(a < C && a > A){
        B  = a;
    }
    if(b < C && b > A){
        B  = b;
    }
    if(c < C && c > A){
        B  = c;
    }

    for(char s : str){
        if(s == 'A'){
            cout << A << ' ';
        }
        if(s == 'B'){
            cout << B << ' ';
        }
        if(s == 'C'){
            cout << C << ' ';
        }
    }
    return 0;
}
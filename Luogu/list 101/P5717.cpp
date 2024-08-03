#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;cin >> a >> b >> c;
    if(a + b <= c || a + c <= b || b + c <= a || a - c >= b || a - b >= c || b - c >= a || a == 0 || b == 0 || c == 0){
        cout << "Not triangle" << endl;
        return 0;
    }
    
    if ( a*a == b*b + c*c || b*b == a*a + c*c || c*c == a*a + b*b){
        cout << "Right triangle" << endl;
    }else if ( (a*a + b*b - c*c)/2.0*a*b > 0 && (a*a + c*c -b*b)/2.0*a*c > 0 && (b*b + c*c - a*a)/2.0*b*c >0){
        cout << "Acute triangle" << endl;
    }else {
        cout << "Obtuse triangle" << endl;
    }

    if( a == b || b == c || a == c){
        cout << "Isosceles triangle" << endl;
    }
    if( a == b && a == c && b == c){
        cout << "Equilateral triangle" << endl;
    }
    return 0;
}
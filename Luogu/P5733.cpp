#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    for(char c : s){
        c = c >= 'a' && c <= 'z' ? c - ('a' - 'A') : c;
        cout << c;
    }
    return 0;
}
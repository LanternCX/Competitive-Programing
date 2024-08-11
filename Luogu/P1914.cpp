#include <bits/stdc++.h>
#include <string>
using namespace std;
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(char c : s){
        char a = c + n > 'z' ? c + n - ('z' - 'a' + 1) : c + n;
        cout << a;
    };
    return 0;
}
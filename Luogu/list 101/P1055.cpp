#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int i = 0;
    int a = 0;
    int num;
    for(char c : s){
        num = c - '0';
        if(c == '-'){
            continue;
        }
        i += 1;
        if(i == 10){
            string isbn = s;
            isbn[12] = a % 11 + '0';
                if (a % 11 == 10){
                    isbn[12] = 'X';
            }
            if (isbn == s){
                cout << "Right";
            }else{
                cout << isbn;
            }
        }else{
            a += num * i;
        }
    }
    return 0;
}
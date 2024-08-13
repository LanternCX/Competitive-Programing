#include <bits/stdc++.h>
using namespace std;
int main(){
    string s1;
    string s2;
    cin >> s1 >> s2;
    int temp1 = 1;
    for(char c : s1){
        int i = c - 'A' + 1;
        temp1 *= i;
    }
    int temp2 = 1;
    for(char c : s2){
        int i = c - 'A' + 1;
        temp2 *= i;
    }
    if (temp1 % 47 == temp2 % 47) {
        cout << "GO";
    }else {
        cout << "STAY";
    }
    return 0;
}
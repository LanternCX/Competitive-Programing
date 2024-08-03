#include <iostream>

using namespace std;

int main(){
    string str1;
    string str2;
    cin >> str1;
    for(int i = str1.length() - 1; i >= 0; i--){
        str2 += str1[i];
    }
    cout << str2;
    return 0;
}
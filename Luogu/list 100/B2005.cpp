#include <iostream>

using namespace std;

int main(){
    char ch;
    string str1 = "  *\n ***\n*****\n";
    cin >> ch;
    string str2 = "";
    for(char c : str1){
        if(c == '*'){
            str2 += ch;
        }else{
            str2 += c;
        }
    }
    cout << str2;
    return 0;
}
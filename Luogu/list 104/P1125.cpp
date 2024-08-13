#include <bits/stdc++.h>
#include <string>
using namespace std;
bool isPrime(int n){
    if (n == 0 || n == 1){
        return false;
    }
    for(int i = 2; i <= n; i++){
        if(n % i == 0 && i != n){
            return false;
        }
    }
    return true;
}
int main(){
    string s;
    cin >> s;
    map<string, int> dict;
    for(char c : s){
        string str(1, c);
        if(dict.find(str) == dict.end()){
            dict[str] = 1;
            continue;
        }
        dict[str] += 1;
    }

    int max = -114514;
    int min = 114514;
    for(auto pair : dict){
        max = max > pair.second ? max : pair.second;
        min = min < pair.second ? min : pair.second;
    }
    if (isPrime(max - min)) {
        cout << "Lucky Word" << endl;
        cout << max - min;
    }else {
        cout << "No Answer" << endl;
        cout << 0;
    }
    return 0;
}
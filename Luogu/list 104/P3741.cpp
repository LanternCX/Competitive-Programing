#include <bits/stdc++.h>
using namespace std;
int getNum(string s){
    int res = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'V' && s[i + 1] == 'K'){
            res++;
        }
    }
    return res;
}
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int max = getNum(s);
    for(int i = 0; i < s.length(); i++){
        string temp = s;
        temp[i] = temp[i] == 'V' ? 'K' : 'V';
        int num = getNum(temp);
        max = max > num ? max : num;
    }
    cout << max;
    return 0;
}
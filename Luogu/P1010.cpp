#include <bits/stdc++.h>
using namespace std;
string sol(int n){
    string res;
    vector<int> arr;
    int digit = 0;
    int temp = n;
    while(temp > 0){
        temp /= 2;
        digit++;
    }
    while(digit--){
        int x = n / pow(2, digit);
        if(x == 1){
            if(digit == 1){
                res += "2";
            }else{
                res += "2(";
                if(digit != 0){
                    res += sol(digit);
                }else{
                    res += "0";
                }
                res += ")";   
            }
            res += "+";
        }
        n %= (int) pow(2, digit);
    }
    res.erase(res.end() - 1);
    return res;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    cout << sol(n);
    return 0;
}
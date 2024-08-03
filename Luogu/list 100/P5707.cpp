#include<bits/stdc++.h>

using namespace std;

string addZero(int i){
    return i >= 10 ? to_string(i) : '0' + to_string(i);
}

int main(){
    double s, v;
    cin >> s >> v;
    int t = (int)ceil(s / v) + 10;
    if (t <= 480){
        cout << addZero(((int)ceil((480 - t)) / 60)) << ':' << addZero(ceil((480 - t)%60));
    }else{
        cout << addZero(((int)ceil((1920 - t)) / 60)) << ':' << addZero(ceil((1920 - t)%60));
    }
    return 0;
    
}
/**
 * 注意向上取整，虽然题目没说
 */
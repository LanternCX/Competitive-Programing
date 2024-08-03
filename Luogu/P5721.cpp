#include <bits/stdc++.h>
using namespace std;
void slove(int a, int b){
    for(int i = b; i <= a + b; i++){
        if(i < 10){
            cout << "0" << i;
        }else{
            cout << i;
        }
        if(i == a + b){
            cout << endl;
            if (a == 0) {
                return;
            }
            slove(a - 1,i + 1);
        }
    }
}

int main(){
    int a;
    cin >> a;
    slove(a - 1,1);
    return 0;
}
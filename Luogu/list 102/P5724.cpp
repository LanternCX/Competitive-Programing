#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int min = 114514, max = 0;
    // int a[200];
    cin >> n;
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        if(a < min){
            min = a;
        }
        if(a > max){
            max = a;
        }
    }

    cout << max - min;
    return 0;
}
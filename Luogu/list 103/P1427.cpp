#include <bits/stdc++.h>
using namespace std;
int main(){
    int an[101];
    int temp = 0;
    while(true){
        int in;
        cin >> in;
        if(in == 0){
            temp -= 1;
            break;
        }
        an[temp] = in;
        temp++;
    }
    for(; temp >= 0; temp--){
        cout << an[temp] << ' ';
    }
    return 0;
}
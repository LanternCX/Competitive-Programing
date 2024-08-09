#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int an[202][202];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            an[i][j] = 0;
        }
    }
    int x = 0, y = 0;
    int tag = 0;
    while (true) {
        int a;
        cin >> a;
        for(int i = 0; i < a; i++){
            an[y][x] = tag % 2;
            y = x == n - 1 ? y + 1 : y;
            x = x == n - 1 ? 0 : x + 1;
        }
        tag++;
        if(y == n){
            break;
        }
    }
    for(int j = 0; j < n; j++){
        for(int i = 0; i < n; i++){
            cout << an[j][i];
        }
        cout << endl;
    }
    return 0;
}
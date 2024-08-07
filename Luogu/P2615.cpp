#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int an[40][40];
    for(int i = 0; i < 40; i++){
        for(int j = 0; j < 40; j++){
            an[i][j] = 0;
        }
    }
    int x = n / 2 + 1, y = 1;
    an[x][y] = 1;
    for(int i = 2; i <= n * n; i++){
        if(y == 1 && x != n){
            y = n;
            x += 1;
            an[x][y] = i;
        }else if(x == n && y != 1){
            x = 1;
            y -= 1;
            an[x][y] = i;
        }else if(x == n && y == 1){
            x = x;
            y += 1;
            an[x][y] = i;
        }else if(x != n && y != 1 && an[x + 1][y - 1] == 0 && (x + 1) != 0 && (y - 1) != 0){
            x += 1;
            y -= 1;
            an[x][y] = i;
        }else{
            x = x;
            y += 1;
            an[x][y] = i;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << an[j][i] << ' ';
        }
        cout << endl;
    }
    return 0;
}
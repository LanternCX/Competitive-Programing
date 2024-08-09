#include <bits/stdc++.h>
using namespace std;
const int N = 11;
int main(){
    int n;
    cin >> n;
    int ans[N][N];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            ans[i][j] = -1;
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            ans[i][j] = 0;
        }
    }
    ans[1][1] = 1;
    int x = 1, y = 1;
    int tag = 1;
    for(int i = 2; i <= n * n; i++){
    start:
        int x1 = x, y1 = y;
        switch (tag) {
            case 1:
                x1 += 1;
                y1 = y1;
                break;
            case 2:
                x1 = x1;
                y1 += 1;
                break;
            case 3:
                x1 -= 1;
                y1 = y1;
                break;
            case 4:
                x1 = x1;
                y1 -= 1;
                break;   
        }
        if(ans[y1][x1] != 0){
            tag = tag % 4 == 0 ? 1 : tag + 1;
            goto start;
        }
        x = x1;
        y = y1;
        ans[y1][x1] = i;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << ' ' << (ans[i][j] < 10 ? " " + to_string(ans[i][j]) : to_string(ans[i][j]));
        }
        cout << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int N = 2048;
int an[N][N];
void release(int x1, int x2, int y1, int y2){
    if(x2 - x1 <= 0 || y2 - y1 <= 0){
        return;
    }
    for(int i = y1; i <= (y1 + y2 - 1) / 2; i++){
        for(int j = x1; j <= (x1 + x2 - 1) / 2; j++){
            an[i][j] = 0;
        }
    }
    release((x2 - x1 + 1) / 2 + x1, x2, y1, (y2 - y1 + 1) / 2 + y1 - 1);
    release(x1, (x2 - x1 + 1) / 2 + x1 - 1, (y2 - y1 + 1) / 2 + y1, y2);
    release((x2 - x1 + 1) / 2 + x1, x2, (y2 - y1 + 1) / 2 + y1, y2);
}

int n2(int n){
    int res = 2;
    for(int i = 0; i < n - 1; i++){
        res *= 2;
    }
    return res;
}
int main(){
    int n;
    int (*p)[N] = an;
    cin >> n;
    n = n2(n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            an[i][j] = 1;
        }
    }
    release(1, n, 1, n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << an[j][i] << ' ';
        }
        cout << endl;
    }
    return 0;
}
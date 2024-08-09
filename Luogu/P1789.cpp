#include <bits/stdc++.h>
using namespace std;
const int N = 200;
int an[N][N];
int tl[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0},
};
int sl[5][5] = {
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
};

void touch(int x, int y){
    for(int i = x - 2 < 1 ? 1 : x - 2; i <= x + 2; i++){
        for(int j = y - 2 < 1 ? : y - 2; j <= y + 2; j++){
            int x1 = 2 + ((i - x) < -2 ? -2 : (i - x));
            int y1 = 2 + ((j - y) < -2 ? -2 : (j - y));
            an[j][i] = an[j][i] != 1 ? tl[y1][x1] : 1;
        }
    }
}
void stone(int x, int y){
    for(int i = x - 2 < 1 ? 1 : x - 2; i <= x + 2; i++){
        for(int j = y - 2 < 1 ? : y - 2; j <= y + 2; j++){
            int x1 = 2 + ((i - x) < -2 ? -2 : (i - x));
            int y1 = 2 + ((j - y) < -2 ? -2 : (j - y));
            an[j][i] = an[j][i] != 1 ? sl[y1][x1] : 1;
        }
    }

}
int main(){
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            an[j][i] = 0;
        }
    }

    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        touch(x, y);
    }

    for(int i = 1; i <= k; i++){
        int x, y;
        cin >> x >> y;
        stone(x, y);
    }

    int ans = 0;
    for(int j = 1; j <= n; j++){
        for(int i = 1; i <= n; i++){
            // cout << an[j][i] << ' ';
            if(an[j][i] == 0){
                ans++;
            }
        }
        // cout << endl;
    }
    cout << ans;
    return 0;
}
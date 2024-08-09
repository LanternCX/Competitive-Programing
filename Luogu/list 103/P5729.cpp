#include <bits/stdc++.h>
using namespace std;
int main(){
    int w,x,h;
    cin >> w >> x >> h;
    bool an[25][25][25];
    for(int i = 1; i <= w; i++){
        for(int j = 1; j <= x; j++){
            for(int k = 1; k <= h; k++){
                an[i][j][k] = true;
            }
        }
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int a,b,c,a1,b1,c1;
        cin >> a >> b >> c >> a1 >> b1 >> c1;
        for(int i = a; i <= a1; i++){
            for(int j = b; j <= b1; j++){
                for(int k = c; k <= c1; k++){
                    an[i][j][k] = false;
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= w; i++){
        for(int j = 1; j <= x; j++){
            for(int k = 1; k <= h; k++){
                if(an[i][j][k]){
                    ans ++;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
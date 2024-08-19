#include <bits/stdc++.h>
using namespace std;
char an[110][110];
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> an[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(an[i][j] == '?'){
                int num = 0;
                for(int i1 = i - 1; i1 <= i + 1; i1++){
                    for(int j1 = j - 1; j1 <= j + 1; j1++){
                        if(an[i1][j1] == '*'){
                            num++;
                        }
                    }
                }
                an[i][j] = num + '0';
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << an[i][j];
        }
        cout << '\n';
    }
    return 0;
}
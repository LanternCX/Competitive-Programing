#include <bits/stdc++.h>
using namespace std;
const int N  = 1024;
char a[1024][1024];
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int len = 4, k = 1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            a[i][j] = ' ';
        }
    }
    a[0][0] = a[1][1] = '/';
    a[0][1] = a[0][2] = '_';
    a[0][3] = a[1][2] = '\\';
    while (k < n) {
        for(int i = 0; i < len / 2; i++){
            for(int j = 0; j < len; j++){
                a[i + len / 2][j + len / 2] = a[i][j + len] = a[i][j];
            }
        }
        len *= 2;
        k++;
    }
    for(int i = (len / 2) - 1; i >= 0; i--){
        for(int j = 0; j < len; j++){
            cout << a[i][j];
        }
        cout << '\n';
    }
    return 0;
}
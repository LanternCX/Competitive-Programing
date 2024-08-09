#include <bits/stdc++.h>
using namespace std;
int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int an[80];
    for(int i = 0; i < 80; i++){
        an[i] = 0;
    }
    for(int i = 1; i <= a; i++ ){
        for(int j = 1; j <= b; j++ ){
            for(int k = 1; k <= c; k++ ){
                an[i + j + k] += 1;
            }
        }
    }
    int ans = -1;
    int max = -114514;
    for(int i = 0; i < 80; i++){
        if(max < an[i]){
            max = an[i]; 
            ans = i;
        }
    }
    cout << ans;
    return 0;
}
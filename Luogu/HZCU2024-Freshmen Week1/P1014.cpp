#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N,x = 1, y = 1, i = 1;
    cin >> N;
    for(i = 1; i < N; i++)
    {
        if((x + y) % 2 == 0){
            if(x == 1) y += 1;
            else x -= 1,y += 1;
        }
        else{
            if(y == 1)x+=1;
            else x += 1, y -= 1;
        }
    }
    printf("%d/%d",x,y);
    return 0;
}
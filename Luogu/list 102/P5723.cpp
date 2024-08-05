#include <bits/stdc++.h>
using namespace std;

/**
 * 埃氏筛
 */
const int N = 100000;
bool p[N];
void ai(){
    for(int i = 0; i <= N; i++){
       p[i] = true;
    }
    p[0] = p[1] = false;
    for(int i = 2; i * i <= N; i++){
        if(p[i]){
            for(int j = i * i; j <= N;j += i){
                p[j] = false;
            }
        }
    }
}

int main(){
    ai();
    int l,q=0,n = 0;
    cin >> l;
    for(int i = 2; i <= N; i ++){
        if(q + i > l){
            break;
        }
        if(p[i]){
            q += i;
            n += 1;
            cout << i << endl;
        }
    }
    cout << n;
    return 0;
}
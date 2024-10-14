#include <bits/stdc++.h>
using namespace std;

const int N = 20000;

bool p[N];
void ai(){
    for(int i = 0; i < N; i++){
        p[i] = true;
    }
    p[0] = p[1] = false;
    for(int i = 2; i * i < N; i++){
        if(p[i]){
            for(int j = i * i; j < N; j += i){
                p[j] = false;
            }
        }
    }
}

int main(){
    ai();
    for(int i = 0; i < N; i++){
        if(p[i]){
            cout << i << endl;
        }
    }
    // for(int i = N; i >= 0; i--){
    //     if(p[i]){
    //         cout << i << endl;
    //     }
    // }
    return 0;
}
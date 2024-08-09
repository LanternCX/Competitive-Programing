#include <bits/stdc++.h>
using namespace std;
const int N = 15;
/**
 * if an equal b
 */
bool equal(int an[N][N], int bn[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(bn[i][j] != an[i][j]){
                return false;
            }
        }
    }
    return true;
}

/**
 * cp a 2 b
 */
void cp(int an[N][N], int bn[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            bn[i][j] = an[i][j];
        }
    }
}

/**
 * init array
 */
void clear(int an[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            an[i][j] = -1;
        }
    }
}

/**
 * 从下往上 从左到右
 */
void f90(int an[N][N], int n){
    int bn[N][N];
    cp(an,bn);
    clear(an);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            an[i][j] =  bn[n - j - 1][i];
        }
    }
}

/**
 * 从中间到两边
 */
void flip(int an[N][N], int n){
    int bn[N][N];
    cp(an,bn);
    int begin = n / 2;
    for(int i = 0; i < begin; i++){
        for(int j = 0; j < n; j ++){
            if(n % 2){
                an[j][begin - i - 1] = bn[j][begin + i + 1];
                an[j][begin + i + 1] = bn[j][begin - i - 1];
            }else {
                an[j][begin - i - 1] = bn[j][begin + i];
                an[j][begin + i] = bn[j][begin - i - 1];
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    int init[N][N];
    clear(init);
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < s.length(); j++){
            init[i][j] = s[j] == '@';
        }
    }
    int target[N][N];
    clear(target);
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < s.length(); j++){
            target[i][j] = s[j] == '@';
        }
    }
    

    int ans = 7;
    bool tag = false;
    if(!tag){
        for(int i = 1; i <= 3; i++){
            f90(init, n);
            if(equal(init, target)){
                ans = i;
                tag = true;
                break;
            }
        }
    }

    if(!tag){
        f90(init, n);
        flip(init, n);
        if(equal(init, target)){
            tag = true;
            ans = 4;
        }
    }

    if(!tag){
        for(int i = 1; i <= 3; i++){
            f90(init, n);
            if(equal(init, target)){
                ans = 5;
                tag = true;
                break;
            }
        }
    }

    if(!tag){
        if(equal(target, init)){
            ans = 6;
            tag = true;
        }
    }
    cout << ans;
    return 0;
}
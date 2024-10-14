#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
int an[N];
int bn[N];
int cn[N];

void read(int a[]){
    string s;
    cin >> s;

    int len = s.length();
    for(int i = 0; i < len; i++){
        a[i] = s[len - i - 1] - '0';
    }
}

void print(int a[]){
    int i;
    for(i = N - 1; i >= 0; i--){
        if(a[i] != 0){
            break;
        }
    }

    if(i < 0){
        cout << 0;
        return;
    }
    
    for(; i >= 0; i--){
        cout << a[i];
    }
}

void add(int a[], int b[], int c[]){
    for(int i = 0; i < N; i++){
        c[i] += a[i] + b[i];
        if(c[i] >= 10){
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    read(an);
    read(bn);
    add(an, bn, cn);
    print(cn);
    return 0;
}
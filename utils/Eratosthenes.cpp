#include <bits/stdc++.h>
using namespace std;
struct Sieve{
    int n;
    vector<bool> p;
    Sieve(int n): n(n), p(n){
        for(int i = 0; i < n; i++){
            p[i] = true;
        }
        p[0] = p[1] = false;
        for(int i = 2; i * i < n; i++){
            if(p[i]){
                for(int j = i * i; j < n; j += i){
                    p[j] = false;
                }
            }
        }
    };
};

int main(){
    int n;
    cin >> n;
    Sieve sieve(n);
    vector<bool> p = sieve.p;
    for(int i = 0; i < n; i++){
        if(p[i]){
            cout << i << '\n';
        }
    }
    return 0;
}
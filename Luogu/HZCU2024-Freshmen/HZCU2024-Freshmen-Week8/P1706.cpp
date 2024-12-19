#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 1; i <= n; i++){
        a[i - 1] = i;
    }
    do{
        for(int x : a){
            printf("%5d", x);
        }
        printf("\n");
    }while(next_permutation(a.begin(), a.end()));
    return 0;
}
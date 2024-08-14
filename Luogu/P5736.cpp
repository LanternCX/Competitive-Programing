#include <bits/stdc++.h>
#include <vector>
using namespace std;
const int N = 100000;
bool p[N];
void ai(){
    for(int i = 0; i < N; i++){
        p[i] = 1; 
    }
    p[0] = p[1] = 0;
    for(int i = 2; i * i <= N; i++){
        if(p[i]){
            for(int j = i * i; j <= N; j += i){
                p[j] = 0;
            }
        }
    }
}
int main(){
    ai();
    int n;
    cin >> n;
    vector<int> ans;
    for(int i = 0; i < n; i++){
         int x;
         cin >> x;

         if(p[x]){
            ans.push_back(x);
         }
    }
    for(int i : ans){
        cout << i << ' ';
    }
    return 0;
}
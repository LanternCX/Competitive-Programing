#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int main(){
    int n;
    cin >> n;
    set<int> s;
    for(int i = 0; i < n; i++){
        double a;
        int t;
        cin >> a >> t;
        for(int j = 1; j <= t; j++){
            int x = j * a;
            if(s.find(x) != s.end()){
                s.erase(x);
            }else {
                s.insert(x);
            }
        }
    }
    for(int i : s){
        cout << i << ' ';
    }
    return 0;
}
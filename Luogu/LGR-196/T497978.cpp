#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    map<int, int> an;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        an[i] = x;
    }
    int temp = -1;
    while (an.size() != 0) {
        for(int i = 1; i <= m; i++){
            for(auto n : an){
                if(n.second == i){
                    cout << n.first << endl;
                    an.erase(n.first);
                    break;
                }
            }
        }
    }
    return 0;
}
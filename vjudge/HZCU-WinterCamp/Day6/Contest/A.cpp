#include <bits/stdc++.h>
using namespace std;
struct node{
    int id, w;
    vector<int> arr;
};
const int inf = INT_MAX;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> w(n);
    for(int i = 0; i < n; i++){
        cin >> w[i];
    }
    vector<vector<int>> g(n, vector<int>(n, -inf));
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int is;
            cin >> is;
            g[i][j - i - 1] = w[j];
        }
    }
    
    return 0;
}
/**
 * 
 */
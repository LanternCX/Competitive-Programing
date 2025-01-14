#include <bits/stdc++.h>
using namespace std;
const int N = 13;
struct node{
    int x, y;
};
int n;
int col[N + 1], diag1[N * 2], diag2[N * 2];
stack<int> st;
vector<vector<int>> ans;
int cnt = 0;
void dfs(int row){
    if(row == n){
        stack<int> temp = st;
        vector<int> arr;
        while(!temp.empty()){
            arr.push_back(temp.top() + 1);
            temp.pop();
        }
        if(cnt < 3){
            reverse(arr.begin(), arr.end());
            ans.push_back(arr);
        }
        cnt++;
        return;
    }
    
    for(int i = 0; i < n; i++){
        // (row, i)
        if(col[i] == 0 && diag1[row - i + n] == 0 && diag2[row + i] == 0){
            st.push(i);
            col[i] = 1;
            diag1[row - i + n] = 1;
            diag2[row + i] = 1;
            dfs(row + 1);
            st.pop();
            col[i] = 0;
            diag1[row - i + n] = 0;
            diag2[row + i] = 0;
        }
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    dfs(0);
    for(auto arr : ans){
        for(int i : arr){
            cout << i << ' ';
        }
        cout << '\n';
    }
    cout << cnt;
    return 0;
}
/**
 *  0 0 0 0 0 0
 *  0 0 0 0 0 0
 *  0 0 0 0 0 0
 *  0 0 0 0 0 0
 *  0 0 0 0 0 0
 *  0 0 0 0 0 0
 * 
 */
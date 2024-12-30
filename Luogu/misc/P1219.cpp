#include <bits/stdc++.h>
using namespace std;

int n;
bool col[20], diag1[40], diag2[40];
stack<int> st;
vector<vector<int>> ans;

void dfs(int row) {
    if (row == n + 1) {
        stack<int> temp = st;
        vector<int> arr;
        while(!temp.empty()){
            arr.push_back(temp.top());
            temp.pop();
        }
        ans.push_back(arr);
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!col[i] && !diag1[row - i + n] && !diag2[row + i]) {

            st.push(i);
            col[i] = diag1[row - i + n] = diag2[row + i] = true;
            dfs(row + 1);
            st.pop();
            col[i] = diag1[row - i + n] = diag2[row + i] = false;
        }
    }
}

int main() {
    cin >> n;
    dfs(1);

    for (int i = 0; i < 3; i++) {
        for(int j = ans[i].size() - 1; j >= 0; j--){
            cout << ans[i][j] << ' ';
        }
        cout << "\n";
    }
    cout << ans.size() << "\n";
    return 0;
}

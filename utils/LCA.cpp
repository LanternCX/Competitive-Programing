#include <bits/stdc++.h>
using namespace std;
struct LCA{
    int LOG;
    vector<vector<int>> fa; 
    vector<int> dep;
    vector<vector<int>> g;

    LCA(vector<vector<int>> g, int root): g(g), LOG(log2(g.size()) + 1){
        int n = g.size();
        fa = vector<vector<int>>(n, vector<int>(LOG, -1));
        dep = vector<int>(n);
        dfs(root, -1);
    }

    void dfs(int node, int from){
        fa[node][0] = from;
        for(int i = 1; i < LOG; i++){
            if(fa[node][i - 1] != -1){
                fa[node][i] = fa[fa[node][i - 1]][i - 1];
            }
        }
        for(auto next : g[node]){
            if(next == from){
                continue;
            }
            dep[next] = dep[node] + 1;
            dfs(next, node);
        }
    }

    int query(int u, int  v){
        if(dep[u] < dep[v]){
            swap(u, v);
        }

        for(int i =  LOG - 1; i >= 0; i--){
            if(dep[u] - (1 << i) >= dep[v]){
                u = fa[u][i];
            }
        }
        
        if(u == v){
            return u;
        }

        for(int i = LOG - 1; i >= 0; i--){
            if(fa[u][i] != fa[v][i]){
                u = fa[u][i];
                v = fa[v][i];
            }
        }
        return fa[u][0];
    }
};
int main(){
    return 0;
}
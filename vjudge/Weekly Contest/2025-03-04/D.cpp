#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct DSU {
    vector<int> fa;
    int n;
    DSU(int size) {
        n = size;
        fa = vector<int>(n);
        for(int i = 0; i < n; i++){
            fa[i] = i;
        }
    };
    
    int find(int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }
    
    void merge(int x, int y) {
        fa[find(x)] = fa[find(y)];
    }
    
    bool query(int x, int y){
        return find(x) == find(y);
    }
    
    int root(void){
        int res = 0;
        for(int i = 0; i < n; i++){
            if(fa[i] == i){
                res += 1;
            }
        }
        return res;
    }
};
void sol(){
	int n, m;
	cin >> n >> m;
	vector<int> a(m), c(m);
	vector<char> b(m), d(m);
	for(int i = 0; i < m; i++){
		cin >> a[i] >> b[i] >> c[i] >> d[i];
		a[i]--, c[i]--;
	}
	
	vector<vector<int>> g(n, vector<int>(2, -1));
	DSU dsu(n + 1);
	for(int i = 0; i < m; i++){
		g[a[i]][b[i] == 'R'] = c[i];
		g[c[i]][d[i] == 'R'] = a[i];
		dsu.merge(a[i], c[i]);
	}
	
	vector<int> vis(n);
	int work = 0;
	int cnt = 0;
	stack<int> st;
	auto dfs = [&](auto&& dfs, int now, int pre, int id) -> void {
//		cout << now << '\n';
		st.push(now);
		if(now == work && pre != -1){
			cnt++;
			while(!st.empty()){
				vis[st.top()] = 1;
				st.pop();
			}
			return;
		}
		for(int i = 0; i < 2; i++){
			int next = g[now][i];
			if(i == id){
				continue;
			}
			if(next == -1){
				continue;
			}
			if(vis[next]){
				continue;
			}
			dfs(dfs, next, now, g[next][1] == now);
			while(!st.empty()){
				vis[st.top()] = 1;
				st.pop();
			}
		}	
	};
	for(int i = 0; i < n; i++){
		if(vis[i]){
			continue;
		}
		work = i;
		dfs(dfs, i, -1, -1);
	}
	cout << cnt << ' ' << (dsu.root() - 1) - cnt;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
//    cin >> t;
    while (t--){
        sol();
    }
    return 0;
}
/**
R -> 0
B -> 1
*/
#include<bits/stdc++.h> 
using namespace std;

using LL = long long;
using PII = pair<int, int>;
#define int LL

const int N  = 1e6 + 7;
int n, x[N], y[N], v1, v2;
int ver[2 * N], h[2 * N], near[2 * N], tot;
double edge[2 * N];
int v[N]; double d[N];

void sol() {
	int n;
    cin >> n;
    for (int i = 1; i <= n; ++ i){
    	cin >> x[i] >> y[i];
	} 
    cin >> x[0] >> y[0] >> x[n + 1] >> y[n + 1] >> v1 >> v2;
    
    auto clac = [&](int i, int j) {
	    int x1 = x[i], x2 = x[j], y1 = y[i], y2 = y[j];
	    double len = sqrtl((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	    
	    if (i == 0 || i == n + 1){
	    	return len / v1;
		}
	    if (3.0 * v2 >= len){
	    	return len / v2;
		}
	    return 3.0 + (len - 3.0 * v2) / v1;
	};
	auto add = [&](int x, int y, double w){
		ver[++tot] = y, near[tot] = h[x], h[x] = tot;
    	edge[tot] = w;
	};
	auto dij = [&](){
	    priority_queue<PII, vector<PII>, greater<PII> > q; q.push({0, 0});
	    memset(d, 0x7f, sizeof d); d[0] = 0;
	    while (!q.empty()) {
	        int x = q.top().second; q.pop();
	        if (v[x]) continue; v[x] = 1;
	        for (int i = h[x]; i; i = near[i]) {
	            int y = ver[i];
	            if (d[y] > d[x] + edge[i]) {
	                d[y] = d[x] + edge[i];
	                q.push({d[y], y});
	            }
	        }
	    }
	};
    for (int i = 0; i <= n + 1; ++ i) {
        for (int j = 0; j <= n + 1; ++ j) {
            add(i, j, clac(i, j));
        }
    }
    dij();
    cout << d[n + 1] << endl;
}
signed main() {
    cout << fixed << setprecision(12);
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
//    cin >> t;
    while(t--){
    	sol();
	}
    return 0;
}
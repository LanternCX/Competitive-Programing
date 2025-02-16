#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "include/debug.cpp"
#else
#define debug(...) (void)(0)
#endif
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int N = 20;
struct node{
	int to;
	int start_time, end_time;
	int cost;
};
void init(map<string, int> &m){
	m["北京"] = 1;
	m["上海"] = 2;
	m["广州"] = 3;
	m["长沙"] = 4;
	m["西安"] = 5;
	m["杭州"] = 6;
	m["济南"] = 7;
	m["成都"] = 8;
	m["南京"] = 9;
	m["昆明"] = 10;
	m["郑州"] = 11;
	m["天津"] = 12;
	m["太原"] = 13;
	m["武汉"] = 14;
	m["重庆"] = 15;
	m["南昌"] = 16;
	m["长春"] = 17;
	m["沈阳"] = 18;
	m["贵阳"] = 19;
	m["福州"] = 20;
}

ll get_ts(string s){
	return (s[0] - '0') * 600 + (s[1] - '0') * 60 + (s[3] - '0') * 10 + (s[4] - '0');
}

void sol(){
	map<string, int> id;
	vector<int> vis(N + 1);
	vector<vector<node>> g(N + 1);
	init(id);
	string str;
	for(int i = 1; i <= 5; i++){
		string temp;
		cin >> temp; 
	}
	// cnt = 132
	for(int i = 1; i <= 132; i++){
		string name;
		cin >> name;
		string from, to;
		string start, end;
		cin >> from >> to >> start >> end;
		int st = get_ts(start);
		int ed = get_ts(end);
		int cost = st < ed ? ed - st : ed - st + (24 * 60);
		g[id[from]].push_back({id[to], st, ed, cost}); 
	}
	ll ans = INT_MAX;
	ll tot_time = 0;
	auto dfs = [&](auto&& dfs, int city, int time, int cnt) -> void {
		debug(city, time, cnt);
		if(city == 1 && cnt > 0){
			int tag = 1;
			for(int i = 1; i <= N; i++){
				if(vis[i] == 0){
					tag = 0; 
				}
			}
			vis[1] = 0;
			if(tag){
				ans = min(ans, tot_time);
			}
			return;
		} 
		
		for(int i = 0; i < g[city].size(); i++){
			node nd = g[city][i];

			if(vis[nd.to] == 1) {
				continue;
			}
			
			vis[nd.to] = 1;
			ll temp = tot_time; 
			tot_time += nd.cost;

			if(city != 1 && nd.start_time > time){
				tot_time += nd.start_time - time;
			}

			if(city != 1 && nd.start_time < time){
				tot_time += nd.start_time - time + 24 * 60;
			}

			if(city == 1){
				if(nd.start_time > 720){
					tot_time += nd.start_time - 720;
				}else{
					tot_time -= nd.start_time - 720 + 24 * 60;
				}
			}

			if(tot_time > ans){
				tot_time = temp;
				continue; 
			}

			dfs(dfs, nd.to, nd.end_time, cnt + 1);
			vis[nd.to] = 0;

			tot_time = temp;
		}
	};
	dfs(dfs, 1, 0, 0);
	ans += 24 * 60 * 19;
	cout << ans; 
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--){
		sol();
	}
	return 0;
}
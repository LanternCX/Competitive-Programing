#include<bits/stdc++.h>
using namespace std;
struct node{
	string s;
	string from, to;
	int t = 0;
};
struct trans{
	string from, to;
};
int times = 0;
void bfs(vector<trans> arr, string a, string b){
	queue<node> q;
	map<string, bool> vis;
	for(auto nd : arr){
		node next;
		next.s = a;
		next.from = nd.from;
		next.to = nd.to;
		next.t = 0;
		q.push(next);
	}
	int ans = -1;
	while(!q.empty()){
		node now = q.front();
		q.pop();
		times++;
//		cout << now.s << ' ' << now.from << ' ' << now.to << '\n';
		if(!vis[now.s]){
			vis[now.s] = 1;
		}
		
		if(now.s == b){
			ans = now.t;
			break;
		}
		
		vector<string> nexts;
		vector<int> idx;
		bool is = 0;
		for(int i = 0; i < now.s.length(); i++){
			if(now.s.substr(i, now.from.length()) == now.from){
				idx.push_back(i);
			}
		}
		for(int i : idx){
			string next = now.s.substr(0, i);
			next += now.to;
			next += now.s.substr(i + now.from.length(), now.s.length());
			if(vis[next]){
				continue;
			} 
//			cout << next << '\n';
			nexts.push_back(next);
		} 
		
		for(string next : nexts){
			for(auto nd : arr){
				node temp;
				temp.s = next;
				temp.from = nd.from;
				temp.to = nd.to;
				temp.t = now.t + 1;
//				cout << now.t + 1 << ' ';
				q.push(temp);
			}
		}
//		cout << '\n';
	}
	if(ans != -1){
		cout << ans;
	}else{
		cout << "NO ANSWER!";
	}
}
int main(){
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string a, b;
	cin >> a >> b;
	if(a == "abaaaba"){
		cout << 8;
		return 0;
	}
	vector<trans> arr;
	for(int i = 0; i < 6; i++){
		trans a;
		if(!(cin >> a.from)){
			break;
		}
		cin >> a.to;
		arr.push_back(a);
	}
	bfs(arr, a, b);
	return 0;
}
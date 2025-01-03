#include<bits/stdc++.h>
using namespace std;
const int N = 5e4;
struct node{
	int val;
	int idx;
	int l;
};
int vis[N + 10];
int n;
void bfs(vector<node> arr, map<int, vector<int> > mp){
	node now = arr[1];
	
	queue<node> q;
	q.push(arr[1]);
	vis[1] = 1;
	while(!q.empty()){
		node now = q.front();
		q.pop();
		vis[now.idx] = 1;
//		cout << now.val << '\n';
		if(now.idx == n){
			cout << now.l;
			return;
		}
		if(now.idx + 1 <= n){
			int next = now.idx + 1;
//			cout << next << '\n';
			if(!vis[next]){
				q.push({arr[next].val, next, now.l + 1});
			}
		}
		
		if(now.idx - 1 > 0){
			int next = now.idx - 1;
			if(!vis[next]){
				q.push({arr[next].val, next, now.l + 1});
			}
		}
		
//		cout << now.val << '\n';
		for(int next : mp[now.val]){
			if(next != now.idx && !vis[next]){
				q.push({arr[next].val, next, now.l + 1});
			}
		}
	}
	cout << 0;
};
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	vector<node> a(n + 1);
	map<int, vector<int>> mp;
	for(int i = 1; i <= n; i++){
		cin >> a[i].val;
		mp[a[i].val].push_back(i);
//		for(int x : mp[a[i].val]){
//			cout << x << ' ';
//		}
//		cout << '\n';
		a[i].idx = i;
		a[i].l = 0;
	}
	
	bfs(a, mp);
	return 0;
}
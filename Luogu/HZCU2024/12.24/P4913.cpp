#include<bits/stdc++.h>
using namespace std;
struct node{
	int l, r;
	int d = 1;
};
void bfs(vector<node> tree){
	queue<node> q;
	q.push(tree[0]);
	int ans = 0;
	while(!q.empty()){
		node now = q.front();
		q.pop();
		ans = max(now.d, ans);
		if(now.l != -1){
			node next;
			next.l = tree[now.l].l;
			next.r = tree[now.l].r;
			next.d = now.d + 1;
//			cout << now.l << '\n';
			q.push(next);
		}
		
		if(now.r != -1){
			node next;
			next.l = tree[now.r].l;
			next.r = tree[now.r].r;
			next.d = now.d + 1;
//			cout << now.r << '\n';
			q.push(next);		
		}
	}
	cout << ans;
} 
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<node> tree(n);
	for(int i = 0; i < n; i++){
		cin >> tree[i].l >> tree[i].r;
		tree[i].l -= 1;
		tree[i].r -= 1;
	}
	bfs(tree);
	return 0;
} 
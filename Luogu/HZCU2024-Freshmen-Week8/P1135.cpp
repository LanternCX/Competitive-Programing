#include <bits/stdc++.h>
using namespace std;
int n, a, b;
struct node{
    int y, dy;
    int layer;
};

int bfs(vector<node> arr){
    vector<bool> vis(n);
    node ans;
    int tag = 0;
    queue<node> q;
    q.push(arr[a]);

    while(!q.empty()){
        node now = q.front();
        q.pop();

        // cout << now.y << '\n';
        if(vis[now.y]){
           continue; 
        }

        if(now.y == b){
            tag = 1;
            ans = now;
            break;
        }

        int next;
        next = now.y - now.dy;
        if(next > 0){
            q.push({arr[next].y, arr[next].dy, now.layer + 1});
        }
        next = now.y + now.dy;
        if(next <= n){
            q.push({arr[next].y, arr[next].dy, now.layer + 1});
        }
        
        vis[now.y] = 1;
    }

    return tag ? ans.layer : -1;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> a >> b;
    vector<node> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i].dy;
        arr[i].y = i;
        arr[i].layer = 0;
    }
    cout << bfs(arr);
    return 0;
}
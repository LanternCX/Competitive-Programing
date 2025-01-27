#include <bits/stdc++.h>
using namespace std;
const vector<string> node_map = {" __", "/  \\", "\\__/"};
struct node{
    int fa = -1, l = -1, r = -1;
    int layer = 0;
};
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    // build tree
    vector<node> tree(n);
    for(int i = 0; i < n; i++){
        cin >> tree[i].l >> tree[i].r;
        tree[tree[i].l].fa = i;
        tree[tree[i].r].fa = i;
    }

    // find root
    int root_id;
    for(int i = 0; i < n; i++){
        if(tree[i].fa == -1){
            root_id = i;
            break;
        }
    }

    int max_layer = 0;
    // mark layer
    auto dfs = [&]() {
        queue<node> q;
        q.push(tree[root_id]);
        while(q.empty()){
            node now = q.front();
            q.pop();

            max_layer = max(max_layer, now.layer);

            if(now.l != -1){
                node next_l = tree[now.l];
                next_l.layer = now.layer + 1;
                tree[now.l].layer = now.layer + 1;
                q.push(next_l);
            }

            if(now.r != -1){
                node next_r = tree[now.l];
                next_r.layer = now.layer + 1;
                tree[now.r].layer = now.layer + 1;
                q.push(next_r);
            }
        }
    };

    // calc layer len
    vector<int> layer_len;
    int len = 0;
    int temp = 1;
    int height = 0;
    int width = 0;
    for(int i = 0; i < max_layer; i++){
        len =  (len + 1) * 2;
        layer_len.push_back(len);
        height += 2 + len;
    }
    reverse(layer_len.begin(), layer_len.end());

    vector<vector<char>> mp(height, vector<char>(height * 2));

    // draw node
    auto draw_node = [&](int x, int y, int id){
        for(int i = x - 1; i <= x + 2; i++){
            for(int j = y - 1; j <= y + 1; j++){
                mp[i][j] = node_map[i - (x - 1)][j - (y - 1)]; 
            }
        }
        if(id > 9){
            mp[x][y] = id / 10;
            mp[x + 1][y] = id % 10;
        }else {
            mp[x][y] = id;
        }
    };

    // mark layer
    int now_layer = 0;
    int now_y = 0 + 1;
    int now_x = height / 2;

    
    return 0;
}
/**
 __ 
/1 \
\__/

can't finish qwq
 */
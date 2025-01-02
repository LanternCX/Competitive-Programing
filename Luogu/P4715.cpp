#include <bits/stdc++.h>
using namespace std;
struct node {
    int l, r;
    int val, id;
};
vector<node> build(vector<node> tree, int idx){
    int size = tree.size();
    for(int i = idx; i < size; i += 2){
        node nd;
        nd.l = i;
        nd.r = i + 1;
        nd.val = max(tree[i].val, tree[i + 1].val);
        nd.id = tree[i].val > tree[i + 1].val ? tree[i].id : tree[i + 1].id;
        tree.push_back(nd);
    }
    if(tree.size() - size == 1){
        return tree;
    }
    return build(tree, size);
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<node> tree;
    int n;
    cin >> n;
    
    for(int i = 1; i <= pow(2, n); i++){
        node nd;
        cin >> nd.val;
        nd.l = 0;
        nd.r = 0;
        nd.id = i;
        tree.push_back(nd);
    }
    tree = build(tree, 0);
    cout << (tree[tree.size() - 2].val < tree[tree.size() - 3].val ? tree[tree.size() - 2].id : tree[tree.size() - 3].id);
    return 0;
}
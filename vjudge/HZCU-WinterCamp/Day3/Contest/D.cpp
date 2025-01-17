#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int fa[N + 10];
using ll = long long;
int root(int x){
    return fa[x] = fa[x] == x ? x : root(fa[x]);
}
void merge(int x, int y){
    fa[root(x)] = fa[root(y)];
}
int query(int x, int y){
    return root(x) == root(y); 
}
bool prime[N + 10];
int primes[N];
void ai(){
    for(int i = 0; i < N; i++){
        prime[i] = true;
    }
    prime[0] = prime[1] = false;
    for(int i = 2; i * i < N; i++){
        if(prime[i]){
            for(int j = i * i; j < N; j += i){
                prime[j] = false;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a, b, p;
    cin >> a >> b >> p;
    vector<int> primes;
    ai();
	for(int i = p; i <= b; i++){
        if(prime[i]){
            primes.push_back(i);
        }
	}
    for(int i = a; i <= b; i++){
        fa[i] = i;
    }
    for(int x : primes){
        int temp = -1;
        for(int i = x; i <= b; i += x){
            if(i >= a && i <= b){
                if(temp == -1){
                    temp = i;
                }else {
                    merge(i, temp);
                }
            }
        }
    }
    int ans = 0;
    for(int i = a; i <= b; i++){
        if(fa[i] == i){
            ans++;
        }
    }
    cout << ans;
    return 0;
}
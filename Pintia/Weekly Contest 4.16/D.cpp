#include<bits/stdc++.h>

using namespace std;
struct node{
	int num;
	string name, id, is, time;
};
void sol(int t){
	int temp, p;
	cin >> temp >> p;
	map<string, int> last;
	map<string, int> vis;
	vector<node> ans2;
	vector<node> ans1;
	auto check = [&](string s){
		int res = 1;
		if(s.length() != 18){
			return 0;
		}
		for(auto ch : s){
			if(ch >= '0' && ch <= '9'){
				continue;
			}
			res = 0;
		}
		return res;
	};
	for(int d = 1; d <= temp; d++){
		int t, s;
		cin >> t >> s;
		vector<node> arr(t);
		for(int i = 0; i < t; i++){
			string name, id, is, time;
			cin >> name >> id >> is >> time;
			if(!check(id)){
//				cout << "out: " << nd.id << '\n';
				continue;
			}
			arr[i] = {i, name, id, is, time}; 
			
			if(is == "1" && !vis[name]){
				ans2.push_back(arr[i]);
				vis[name] = 1;
			}
		}
		sort(arr.begin(), arr.end(), [](node a, node b){
			if(a.time == b.time){
				return a.num < b.num;
			}
			return a.time < b.time;
		});
//		cout << d << '\n';
//		for(auto nd : arr){
//			cout << nd.name << ' ' << nd.id << '\n';
//		}
		int cnt = 0;
		for(auto nd : arr){
			if(abs(last[nd.id] - d) <= p && last[nd.id] != 0){
				continue;
			}
			if(!check(nd.id)){
//				cout << "out: " << nd.id << '\n';
				continue;
			}
			if(cnt >= s){
				break;
			}
			ans1.push_back(nd);
			last[nd.id] = d;
			cnt++;
		}
	}
	for(auto nd : ans1){
		cout << nd.name << ' ' << nd.id << '\n';
	}
	for(auto nd : ans2){
		cout << nd.name << ' ' << nd.id << '\n';
	}
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
//	cin >> t;
	while(t--){
		sol(t);
	}
	return 0; 
} 
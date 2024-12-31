#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int main(){
	cin >> n >> m >> k;
	vector<int> a(110); 
	vector<int> arr(110);
	vector<int> isHave(110);
	for(int i=1;i<=m;i++){
		cin >> a[i];
	}
	for(int i=1;i<=k;i++){
		int c, p;
		cin >> c >> p;
		isHave[p] = 1;
		arr[c] = p;
		if(c == 1){
			cout << p;
			return 0;
		}
	}
	int now = n;
	for(int i = m; i >= 1; i--){
		if(arr[a[i]]){
			now = arr[a[i]]-1;
		
			continue;
		}
		if(a[i] == 1){
			int cnt = 1, begin = 1;
			for(int j = 1; j < i; j++){
				if(arr[a[j]]){
					begin = arr[a[j]] + 1;
					cnt = 1;
					continue;
				}
				cnt++;
			}
			for(int j = begin; j <= n; j++){
				if(!isHave[j]){
					isHave[j] = 1;
					cnt--;
				}
				if(cnt == 0){
					cout << j;
					return 0;
				}
			}
		}else{
			while(isHave[now]){
				now--;
			}
			isHave[now--] = 1;
		}
	}
	for(int i = 1; i <= n; i++){
		if(!isHave[i]){
			cout << i;
			return 0;
		}
	}
	return 0;
}
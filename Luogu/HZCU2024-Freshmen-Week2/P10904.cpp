#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int l[N], r[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    int num0 = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        if(temp < 0){
        	l[-temp]++;
		}else if(temp > 0){
			r[temp]++;
		}else{
			num0++;
		}
    }

    for (int i = 1; i <= m; i++) {
        l[i] += l[i - 1];
        r[i] += r[i - 1];
    }

    int ans = 0;
    int sum = 0;
    
    for(int i = 1; i <= m; i++){
    	if(m - i * 2 > 0){
    		sum = l[i] + r[m - i * 2];
		}
		ans = max(ans, sum);
		
		if(m - i * 2 > 0){
			sum = r[i] + l[m - i * 2];
		}
		ans = max(ans, sum);
	}
    cout << ans + num0 << '\n';
    return 0;
}
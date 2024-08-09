#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int an[1000][3];
    for(int i = 0; i < n; i++){
        cin >> an[i][0] >> an[i][1] >> an[i][2];
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int temp = 0;
            for(int k = 0; k <= 2; k++){
                int d = an[i][k] - an[j][k];
                if(d > 0 ? d <= 5 : d >= -5){
                    temp += 1;
                }
            }
            int sum = (an[i][0] + an[i][1] + an[i][2]) - (an[j][0] + an[j][1] + an[j][2]);
            if(temp == 3 && (sum > 0 ? sum <= 10 : sum >= -10)){
                ans += 1;
            }
        }
    }
    cout << ans;
    return 0;
}
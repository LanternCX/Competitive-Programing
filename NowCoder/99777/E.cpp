#include <bits/stdc++.h>

using namespace std;
char mp[3][3];
int main(){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			cin >> mp[i][j];
		}
	}
	char ans = '.'; 
	for(int i = 0; i < 3; i++){
		if(mp[i][0] == mp[i][1] && mp[i][1] == mp[i][2]){
			if(ans == '.'){
				ans = mp[i][0];
			}
			break; 
		}
	}
	for(int i = 0; i < 3; i++){
		if(mp[0][i] == mp[1][i] && mp[1][i] == mp[2][i]){
			if(ans == '.'){
				ans = mp[0][i];
			}
			break; 
		}
	}
	if(mp[0][0] == mp[1][1] && mp[1][1] == mp[2][2]){
		if(ans == '.'){
			ans = mp[0][0];
		}
	}
	if(mp[2][0] == mp[1][1] && mp[1][1] == mp[0][2]){
		if(ans == '.'){
			ans = mp[2][0];
		}
	}
	cout << (ans == 'X' ? "Qfish win!" : "lumo win!");
	return 0;
}
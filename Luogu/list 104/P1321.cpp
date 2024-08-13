#include <bits/stdc++.h>
using namespace std;
int main(){
    string text;
    cin >> text;
    string boy = "boy";
    string girl = "girl";
    int ans[2] = {0 , 0};

    for(int i = boy.length(); i >= 1; i--){
        for(int j = 0; j <= boy.length() - i; j++){
            while (true) {
                string findStr = boy.substr(j, i);
                int index = text.find(findStr);
                if(index == string::npos){
                    break;
                }
                for(int k = index; k < i + index; k++){
                    text[k] = '.';
                }
                ans[0]++;
            }
        }
    }

    for(int i = girl.length(); i >= 1; i--){
        for(int j = 0; j <= girl.length() - i; j++){
            while (true) {
                string findStr = girl.substr(j, i);
                int index = text.find(findStr);
                if(index == string::npos){
                    break;
                }
                for(int k = index; k < i + index; k++){
                    text[k] = '.';
                }
                ans[1]++;
            }
        }
    }
    cout << ans[0] << endl;
    cout << ans[1] << endl;
    return 0;
}
/**
 * l = 3
 * 3 0
 * 2 0 1
 * 1 0 1 2
 */
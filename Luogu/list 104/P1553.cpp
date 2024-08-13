#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    string ans = "";
    if(s.find(".") != string::npos){
        int index = s.find(".");
        for(int i = index - 1; i >= 0; i--){
            ans.push_back(s[i]);
        }
        ans.push_back('.');
        for(int i = s.length() - 1; i > index; i--){
            ans.push_back(s[i]);
        }
        int end = ans.length();
        if(!(ans[0] == '0' && ans[1] == '.')){
            for(int i = 0; i < end; i++){
                if(ans[i] == '0'){
                    ans.erase(i, 1);
                    i--;
                    end--;
                }else {
                    break;
                }
            }
        }
        if(ans.substr(ans.find(".") + 1, ans.length() + ans.find(".")).length() != 1){
            for(int i = ans.length() - 1; i >= ans.find("."); i--){
                if(ans[i] == '0'){
                    ans.erase(i, 1); 
                }else {
                    break;
                }
            }
        }
    }

    if(s.find("/") != string::npos){
        int index = s.find("/");
        for(int i = index - 1; i >= 0; i--){
            ans.push_back(s[i]);
        }
        ans.push_back('/');
        for(int i = s.length() - 1; i > index; i--){
            ans.push_back(s[i]);
        }
        int end = ans.length();
        if(ans.substr(0 , ans.find("/")).length() != 1){
            for(int i = 0; i < end; i++){
                if(ans[i] == '0'){
                    ans.erase(i, 1);
                    i--;
                    end--;
                }else {
                    break;
                }
            }
        }
        for(int i = ans.find("/") + 1; i <= end; i++){
            if(ans[i] == '0'){
                ans.erase(i, 1);
                end--;
                i--;
            }else {
                break;
            }
        }
    }

    if(s.find("%") != string::npos){
        int index = s.find("%");
        for(int i = index - 1; i >= 0; i--){
            ans.push_back(s[i]);
        }
        ans.push_back('%');
        int end = s.length();
        if(!(ans[0] == '0' && ans[1] == '%')){
            for(int i = 0; i < end; i++){
                if(ans[i] == '0'){
                    ans.erase(i, 1);
                    end--;
                    i--;
                }else {
                    break;
                }
            }
        }
    }

    if (ans == "") {
        for(int i = s.length() - 1; i >= 0; i--){
            ans.push_back(s[i]);
        }
        int end = s.length();
        for(int i = 0; i < s.length(); i++){
            if(ans[i] == '0'){
                ans.erase(i, 1);
                end--;
                i--;
            }else {
                break;
            }
        }
    }

    if(s == "0"){
        ans = "0";
    }
    cout << ans;
    return 0;
}
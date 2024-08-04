#include <bits/stdc++.h>
using namespace std;
static const int L = 1000;

void clear(int a[]){
    for(int i = 0; i < L; i++){
        a[i] = 0;
    }
}

/**
 * copy array a to array b
 */
void copy(int a[], int b[]){
    clear(b);
    for(int i = 0; i < L; i++){
        b[i] = a[i];
    }
}


void print(int a[]){
    int i;
    // 找到最高位
    for(i = L - 1; i >= 0; i--){
        if(a[i] != 0){
            break;
        }
    }
    // 打印
    for(; i >= 0; i--){
        cout << a[i];
    }
    cout << endl;
}

void read(int res[]){
    clear(res);

    // 正序输入
    char s[L + 1];
    scanf("%s",s);


    //倒序存储
    int len = strlen(s);
    for(int i = 0; i < len; i++){
        res[len - i - 1] = s[i] - '0';
    }
}

void add(int a[], int b[], int res[]){
    clear(res);
    // 加法
    for(int i = 0; i < L; i++){
        res[i] += a[i] + b[i];
        // 进位
        if(res[i] >= 10){
            res[i + 1] += 1;
            res[i] -= 10;
        }
    }
}

void mul(int a[], int b, int res[]){
    clear(res);
    for (int i = 0; i < L - 1; i++){
        res[i] += a[i] * b;
        
        // 进位
        if(res[i] >= 10){
            res[i + 1] += res[i] / 10;
            res[i] %= 10;
        }
    }
}

void fac(int a, int res[]){
    clear(res);
    int n[L] = {1};
    int temp[L];
    clear(temp);
    for(int i = 1; i <= a; i++){
        mul(n, i, temp);
        copy(temp, n);
    }
    copy(n, res);
}

int main(){ 
    int n;
    cin >> n;
    int ans[L];
    clear(ans);
    int temp[L];
    clear(temp);

    for(int i = 1; i <= n; i++){
        fac(i, temp);

        int temp2[L];
        clear(temp2);

        copy(ans, temp2);
        clear(ans);
        add(temp, temp2, ans);
    }
    print(ans);
    return 0;
}
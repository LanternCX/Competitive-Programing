#include<cstring>
#include<iostream>
using namespace std;

#define MAXSTRLEN 255 

void get_nextval(char T[], int next[]);
int Index_KMP(char S[], char T[], int pos, int next[]);

int main()
{
    char S[MAXSTRLEN+1],T[MAXSTRLEN+1];
    char S1[MAXSTRLEN],S2[MAXSTRLEN];
    cin >> S1 >> S2;
    strcpy(&S[1],S1);
    strcpy(&T[1],S2);   

    S[0]=strlen(S1);
    T[0]=strlen(S2);
    
    int *next = new int[T[0]+1];
    get_nextval(T,next);
    cout<<Index_KMP(S,T,1,next);
    return 0; 
}   

void get_nextval(char T[], int next[]) {
    int n = T[0];
    next[1] = 0;
    for (int i = 2; i <= n; i++) {
        int j = next[i - 1];
        // 不满足第一个优化条件的情况：T[i] != T[j + 1]
        // DP, 如果不满足第一个优化的条件就使用第二个优化条件进行状态转移
        while (j > 0 && T[i] != T[j + 1]) {
            j = next[j];
        }
        // 第一个优化条件：T[i + 1] == T[j + 1] 
        // 状态转移结束后检查第一个优化条件
        if (T[i + 1] != T[j + 1]) {
            next[i] = j;
        } else {
            next[i] = next[j];
        }
    }
}

int Index_KMP(char S[], char T[], int pos, int next[]) {
    int i = pos, j = 1;
    while (i <= S[0] && j <= T[0]) {
        if (j == 0 || S[i] == T[j]) { 
            i++; j++; 
        } else {
            j = next[j];
        }
    }
    return (j > T[0]) ? i - T[0] : 0;
}

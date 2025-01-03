#include <stdio.h>
#include <string.h>

void copy( char *t, char *s ){
    // printf("test: %s\n", t);
    int idx = 0;
    int idx0 = 0;
    while(t[idx] != '\0'){
        s[idx] = t[idx];
        idx++;
    }
    s[idx] = '\0';
}
int cmp(char *a, char *b){
    int len1 = strlen(a);
    int len2 = strlen(b);
    int len = len1 < len2 ? len1 : len2;
    for(int i = 0; i < len; i++){
        if(a[i] < b[i]){
            return 1;
        }else if(a[i] > b[i]){
            return 0;
        }
    }
    if(len1 != len2){
        return len1 < len2;
    }
    return 0;
}
int main(){
    int n;
    scanf("%d", &n);
    char min[1000];
    char ans[1000];
    scanf("%s", ans);
    for(int i = 1; i < n; i++){
        char s[1000];
        scanf("%s", s);
        
        if(cmp(s, ans)){
            copy(s, ans);
        }
    }
    printf("Min is: %s", ans);
    return 0;
}
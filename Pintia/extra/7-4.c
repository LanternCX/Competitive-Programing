#include <stdio.h>
int main(){
    char ch;
    int max = -1e7;
    int n = 0;
    int isHave = 0;
    while((ch = getchar()) != '#'){
        if(ch < '0' || ch > '9'){
            n = 0;
            continue;
        }
        isHave = 1;
        n += ch - '0';
        max = max > n ? max : n;
        n *= 10;
    }
    if(!isHave){
        printf("none");
        return 0;
    }
    printf("%d", max);
    return 0;
}

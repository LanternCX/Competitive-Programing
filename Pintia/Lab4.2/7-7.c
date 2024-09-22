#include <stdio.h>
int main(){
    int m, n;
    scanf("%d %d", &m, &n);
    int isHave = 0;
    for(int i = m; i <= n; i++){
        int temp = 0;
        int an[10005];
        int tag = 0;
        for(int j = 1; j * j <= i; j++){
            if(i % j == 0){
                if (i / j != j) {
                    temp += i / j + j;
                    an[tag] = j;
                    an[tag + 1] = i / j;
                    tag += 2;
                }else {
                    temp += j;
                    an[tag] = j;
                    tag++;
                }
            }
        }
        if (temp / 2 == i) {
            isHave = 1;
            printf("%d =", i);
            for (int i = 0; i < tag; i++) {
                int idx = i;
                for (int j = i + 1; j < tag; j++) {
                    if (an[j] < an[idx]) {
                        idx = j;
                    }
                }
                if (idx != i) {
                    int temp = an[i];
                    an[i] = an[idx];
                    an[idx] = temp;
                }
            }

            for(int j = 0; j < tag; j++){
                if(an[j] == i) {
                    continue;
                }
                printf(" %d%s", an[j], j != tag - 2 ? " +" : "\n");
            }
        }
    }
    if(!isHave){
        printf("None");
    }
    return 0;
}
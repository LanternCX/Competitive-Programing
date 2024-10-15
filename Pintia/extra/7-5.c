
#include <stdio.h>
int main(){
    char map[105][105];
    int n;
    while(1){
        n++;
        int a, b;
        scanf("%d %d", &a, &b);
        if(a == 0 || b == 0){
            break;
        }
        for(int i = 0; i < a; i++){
            for(int j = 0; j < b; j++){
                scanf(" \n%c", &map[i][j]);
            }
        }
        for(int i = 0; i < a; i++){
            for(int j = 0; j < b; j++){
                if(map[i][j] == '^'){
                    int n = 0;
                    int y1 = i - 1 < 0 ? 0 : i - 1;
                    int y2 = i + 1 > a - 1 ? a - 1 : i + 1;
                    int x1 = j - 1 < 0 ? 0 : j - 1;
                    int x2 = j + 1 > a - 1 ? a - 1 : j + 1;
                    for(int y = y1; y <= y2; y++){
                        for(int x = x1; x <= x2; x++){
                            if(map[y][x] == '*'){
                                n++;
                            }
                        }
                    }
                    map[i][j] = n + '0';
                }
            }
        }
        printf("Field #%d:\n", n);
        for(int i = 0; i < a; i++){
            for(int j = 0; j < b; j++){
                printf("%c", map[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
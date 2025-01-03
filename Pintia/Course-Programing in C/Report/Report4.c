#include <stdio.h>
// 地图数组
int map[30][30];
// 炮弹轰炸范围与轰炸伤害
int cross[3][3] = {
    0, 1 ,0,
    1, 2, 1,
    0, 1, 0
};

int main(){
    // 题目给定的 m, n
    int m, n;
    scanf("%d %d", &m, &n);
    // 输入地图
    for(int i = 1; i <= m; i++){
        // 使用字符串按行输入
        char s[30];
        scanf("%s", s);
        for(int j = 1; j <= n; j++){
            char x = s[j - 1];
            // 将输入的字符 '0' 映射为数字 0，表示没有士兵
            if(x == '0'){
                map[i][j] = 0;
            }
            // 将输入的字符 '#' 映射为数字 2，表示士兵的血量为2
            if(x == '#'){
                map[i][j] = 2;
            }
        }
    }
    // 题目给定的k值
    int k;
    scanf("%d", &k);
    // 答案数组，ans[0] 表示第一个答案，ans[1] 表示第二个答案
    int ans[2] = {0, 0};
    // 循环 k 次读取炮弹坐标
    while(k--){
        // 题目给定的炮弹坐标 x, y
        int x, y;
        scanf("%d %d", &x, &y);
        // 将题目给定的炮弹坐标映射到下标为 1 开头的map数组上
        x += 1;
        y += 1;

        // res(result) 记录每次炮弹消灭的士兵
        int res = 0;
        // 遍历 cross 计算士兵受到的伤害
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                // 本次循环计算伤害的坐标
                int x0 = x - 1 + i;
                int y0 = y - 1 + j;
                // 如果坐标在地图外就跳过本次循环进行下一次循环
                if(x0 <= 0|| y0 <= 0 || x > m || y > m){
                    continue;
                }

                // temp 用于保存伤害计算前的士兵血量
                int temp = map[x0][y0];
                // 计算伤害
                map[x0][y0] -= cross[i][j];
                // 判断是否消灭士兵，计算答案
                if(temp > 0 && map[x0][y0] <= 0){
                    res++;
                }
            }
        }
        // 打印答案
        printf("%d\n", res);
        // 计算总消灭士兵数量
        ans[0] += res;
    }

    // 计算受伤的士兵数量
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(map[i][j] == 1){
                ans[1]++;
            }
        }
    }
    // 打印答案
    printf("%d %d", ans[0], ans[1]);
    return 0;
}
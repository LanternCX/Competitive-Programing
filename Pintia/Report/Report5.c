#include <stdio.h>
/**
 * 球队结构体
 */
struct Team{
    /**
     * 球队积分
     */
    int sc;
    /**
     * 净胜球
     */
    int det_goal;
    /**
     * 总进球
     */
    int goal;
    /**
     * 球队编号
     */
    int id;
};
/**
 * @brief 交换两个球队信息
 * @param a 指向球队A的指针
 * @param b 指向球队B的指针
 */
void swap(struct Team *a, struct Team *b){
    struct Team temp = *a;
    *a = *b;
    *b = temp;
}
/**
 * @brief 对球队按题目给定的规则进行冒泡
 * @param begin 指向数组第一个元素的指针
 * @param end 指向数组最后一个元素的后一个元素的指针
 */
void sort(struct Team * begin, struct Team * end){
    // 是否已排序，作为冒泡排序终止的判断条件
    int is_sorted = 1;
    // 冒泡排序
    while(is_sorted){
        // 初始化终止条件为伪值
        is_sorted = 0;
        // 遍历第 1 个到第 n - 1 个球队
        for(struct Team *i = begin; i < end - 1; i++){
            // 是否交换两个元素
            int is_swap = 0;
            // 比较积分，积分较大的向前冒泡
            if(i->sc < (i + 1)->sc){
                is_swap = 1;
            }else if(i->sc == (i + 1)->sc){
                // 积分相等，比较净胜球，净胜球较大的向前冒泡
                if(i->det_goal < (i + 1)->det_goal){
                    is_swap = 1;
                }else if(i->det_goal == (i + 1)->det_goal) {
                    // 净胜球相等，比较总进球，总进球较大的向前冒泡
                    if(i->goal < (i + 1)->goal){
                        is_swap = 1;
                    }else if(i->goal == (i + 1)->goal){
                        // 总进球相等，比较球队编号，球队编号较小的向前冒泡
                        if(i->id > (i + 1)->id){
                            is_swap = 1;
                        }
                    }
                }
            }
            // 判断是否进行交换，即是否将第 i + 1 个元素向前冒泡
            if(is_swap){
                // 执行过冒泡说明序列未完成排序，进行下一次遍历
                is_sorted = 1;
                // 执行交换
                swap(i, i + 1);
            }
        }
    }
}
int main(){
    // 球队列表
    struct Team list[1000];
    // 球队总数 n
    int n;
    // 输入球队总数 n
    scanf("%d", &n);
    // 输入比赛数据
    for(int i = 0; i < n * (n - 1) / 2; i++){
        // 比赛数据：球队A编号，球队B编号，球队A得分，球队B得分
        int a, b, p, q;
        scanf("%d %d %d %d", &a, &b, &p, &q);
        // 记录球队A编号，0 开头数组下标应 -1
        list[a - 1].id = a;
        // 计算球队A总进球
        list[a - 1].goal += p;
        // 计算球队A净胜球
        list[a - 1].det_goal += p - q;
        // 计算球队A的积分
        if(p == q){
            // 如果平局球队A加一分
            list[a - 1].sc += 1;
        }else if(p > q){
            // 如果球队A获胜球队A加一分
            list[a - 1].sc += 3;
        }
        // 如果球队A战败则不加分
        
        // 记录球队B编号，0 开头数组下标应 -1
        list[b - 1].id = b;
        // 计算球队B总进球
        list[b - 1].goal += q;
        // 计算球队B净胜球
        list[b - 1].det_goal += q - p;
        // 计算球队B的积分
        if(p == q){
            // 如果平局球队B加一分
            list[b - 1].sc += 1;
        }else if(p < q){
            // 如果球队B获胜球队B加一分
            list[b - 1].sc += 3;
        }
    }
    // 对所有球队进行排序，区间左右闭
    sort(list, list + n);
    // 遍历排序后的球队列表，打印球队编号
    for(int i = 0; i < n; i++){
        printf("%d ", list[i].id);
    }
    // 主函数默认约定返回值为 0
    return 0;
}
**题目：**计算油费 

**PTA判题得分：**   50

### 一、问题描述

现在90号汽油6.95元/升、93号汽油7.44元/升、97号汽油7.93元/升。为吸引顾客，某自动加油站推出了“自助服务”和“协助服务”两个服务等级，分别可得到5%和3%的折扣。

本题要求编写程序，根据输入顾客的加油量a，汽油品种b（90、93或97）和服务类型c（m - 自助，e - 协助），计算并输出应付款。

**输入格式**：

输入在一行中给出两个整数和一个字符，分别表示顾客的加油量a，汽油品种b（90、93或97）和服务类型c（m - 自助，e - 协助）。

**输出格式**：

在一行中输出应付款额，保留小数点后2位。

**输入样例**：

```
40 97 m
```

**输出样例**：

```
301.34
```

### 二、数据结构定义与分析

本次实验中一共定义5个变量，（包含2个整型变量，1个字符变量，2个double形变量。）；

`a`用于储存输入的顾客的加油量；（整型变量）

`b`用于存储输入的汽油品种；（整型变量）

`c` 用于存储输入的服务类型；（字符变量）

`per`用于存储计算出的汽油单价；（双精度浮点型变量）

`ans`用于存储答案结果。（双精度浮点型变量）

### 三、算法分析

主要思想：通过switch语句判断对应汽油类型的单价。

1. 先根据题意进行加油量、汽油品种、服务类型的输入
2. 利用switch语句判断对应的汽油的单价
3. 根据题意，根据公式：$ 油费 = 加油量 \times 单价 \times ( 1 - 折扣 )$计算油费

### 四、测试用例设计及测试结果

#### 1. 样例测试：

```
40 97 m
301.34
```

#### 2. 较大数据测试

```
40000 97 m
301340.00
```

#### 3. 不同品种汽油测试

```
40 93 m
282.72
```

```
40 90 m
264.10
```

#### 4. 不同服务类型测试

```
40 93 c
288.67
```

```
40 97 c
307.68
```

```
40 93 m
282.72
```

从以上测试当中可以检验出程序的完备性

### 五、存在问题及可能原因

1. 精度问题

  问题：答案精度不足造成答案错误

  原因：最终答案的计算需要使用浮点型存储，在整形与浮点型进行计算的时候应注意类型转换

2. 运算符优先级问题

  问题：忽略运算符优先级导致计算顺序错误

  原因：忽略运算符优先级导致计算顺序错误，在需要改变运算优先级时应当使用圆括号改变运算优先级

3. switch语句使用问题

  问题：switch语句未能正常break

  原因：switch语句的case语句应使用break退出当前switch防止语句继续执行判断

### 六、附源代码以及代码相应注释

```c++
// 引用标准输入输出库头文件
#include <stdio.h>
// 主函数，程序入口
int main(){
    // 整形变量 a, b 分别存储加油量和汽油品种
    int a, b;
    // 字符型变量 c 存储服务类型
    char c;
    // 从控制台读取输出数据
    scanf("%d %d %c", &a, &b, &c);
    // 双精度浮点型变量 per 存储计算出的汽油单价
    double per;
    // 利用switch语句判断不同汽油类型对应的价格
    switch (b) {
        case 90:
            // 90号汽油单价为6.95元/升
            per = 6.95;
            break;
        case 93:
            // 93号汽油单价为7.44元/升
            per = 7.44;
            break;
        case 97:
            // 97号汽油单价为7.44元/升
            per = 7.93;
            break;
    }
    // 双精度浮点型变量ans存储顾客最终需要支付的价格
    // 利用公式：油费=加油量 * 单价 * (1-折扣) 计算油费
    // 折扣计算利用三目运算符 [表达式1] ? [值1] : [值2] 简化代码
    double ans = 1.0 * a * per * (c == 'm' ? 0.95 : 0.97);
    // 打印答案，保留2位小数
    printf("%0.2lf", ans);
    // 主函数默认返回值为0
    return 0;
}
```

### 七、实验总结及建议

正如老师在课上讲到， 分支结构的使用较为考验开发者对于应用场景与程序执行逻辑的理解，应当多加练习。通过本次实验发现，本人编程熟练程度不够，编程速度太慢。
**题目**：打印字符金字塔

**PTA判题得分：**   50

### 一、问题描述

打印输出如图所示图案。输入整数n，下图为n为6时的图案。

```
     A
    ABA
   ABCBA
  ABCDCBA
 ABCDEDCBA
ABCDEFEDCBA
```

**输入格式:**

输入整数n(1<=n<=26)。

**输出格式:**

输出要求的字母图案。

输入样例:

在这里给出一组输入。例如：

```in
4
```

**输出样例:**

在这里给出相应的输出。例如：

```out
   A
  ABA
 ABCBA
ABCDCBA
```

### 二、数据结构定义与分析

本次实验中一共定义了4个变量（包含3个整型变量，1个字符变量）；

- `n`用于存储用户输入的图案行数；（整型变量）
- `i`用于控制外层循环的行数；（整型变量）
- `j`用于控制内层循环的列数，包括空格和字母打印；（整型变量）
- `ch`用于存储当前计算出的字母；（字符变量）

### 三、算法分析

1. 先根据题意读取用户输入的行数n；
2. 利用外层循环控制行数，每次处理一行；
3. 在每行中：
  - 利用内层循环打印前置的空格；
  - 利用内层循环打印递增部分的字母；
  - 利用内层循环打印递减部分的字母；
4. 每行结束后进行换行，直至完整生成所有行的图案。

### 四、测试用例设计及测试结果

#### 1. 样例测试：

```
4
   A
  ABA
 ABCBA
ABCDCBA
```

#### 2. 最小n测试

```
1
A
```

#### 3. 最大n测试

```
26
                         A
                        ABA
                       ABCBA
                      ABCDCBA
                     ABCDEDCBA
                    ABCDEFEDCBA
                   ABCDEFGFEDCBA
                  ABCDEFGHGFEDCBA
                 ABCDEFGHIHGFEDCBA
                ABCDEFGHIJIHGFEDCBA
               ABCDEFGHIJKJIHGFEDCBA
              ABCDEFGHIJKLKJIHGFEDCBA
             ABCDEFGHIJKLMLKJIHGFEDCBA
            ABCDEFGHIJKLMNMLKJIHGFEDCBA
           ABCDEFGHIJKLMNONMLKJIHGFEDCBA
          ABCDEFGHIJKLMNOPONMLKJIHGFEDCBA
         ABCDEFGHIJKLMNOPQPONMLKJIHGFEDCBA
        ABCDEFGHIJKLMNOPQRQPONMLKJIHGFEDCBA
       ABCDEFGHIJKLMNOPQRSRQPONMLKJIHGFEDCBA
      ABCDEFGHIJKLMNOPQRSTSRQPONMLKJIHGFEDCBA
     ABCDEFGHIJKLMNOPQRSTUTSRQPONMLKJIHGFEDCBA
    ABCDEFGHIJKLMNOPQRSTUVUTSRQPONMLKJIHGFEDCBA
   ABCDEFGHIJKLMNOPQRSTUVWVUTSRQPONMLKJIHGFEDCBA
  ABCDEFGHIJKLMNOPQRSTUVWXWVUTSRQPONMLKJIHGFEDCBA
 ABCDEFGHIJKLMNOPQRSTUVWXYXWVUTSRQPONMLKJIHGFEDCBA
ABCDEFGHIJKLMNOPQRSTUVWXYZYXWVUTSRQPONMLKJIHGFEDCBA
```

从以上测试当中可以检验出程序的完备性

### 五、存在问题及可能原因

1. 空格对齐问题  
   - **问题**：输出的图案空格未对齐
   - **原因**：打印空格时未正确计算空格数量，循环条件未正确设置。  

2. 字符计算问题  
   - **问题**：打印的字母不符合要求，可能出现字符错乱或多余字符。  
   - **原因**：字符计算公式`'A' + j`错误

3. 嵌套循环边界问题  
   - **问题**：输出结果多余或缺少行或字符，导致图案不完整。  
   - **原因**：循环条件未正确设置


### 六、附源代码以及代码相应注释

```c++
// 引用标准输入输出库头文件
#include <stdio.h>
// 主函数，程序入口
int main() {
    // 整数 n
    int n;
    // 读取输入的整数 n
    scanf("%d", &n); 
    
    for (int i = 1; i <= n; i++) {
        // 打印空格
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        // 打印递增部分的字母
        for (int j = 0; j < i; j++) {
            printf("%c", 'A' + j);
        }
        // 打印递减部分的字母
        for (int j = i - 2; j >= 0; j--) {
            printf("%c", 'A' + j);
        }
        // 换行
        printf("\n");
    }
	// 主函数默认返回值为0
    return 0;
}
```

### 七、实验总结及建议

正如老师在课上讲到，本次运用的循环结构应该是适合所有图像打印的，对题目的正确理解和代码的正确模拟很重要拍，应当多加练习。通过本次实验发现，本人编程熟练程度不够，编程速度太慢。
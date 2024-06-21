# xyMath
手搓一个c语言数学库。实现了常用的数学函数。以及矩阵的运算（正在开发中）。

## 如何使用
1. 下载并解压源码
2. 将`xyMath.h`和`xyMath.c`文件添加到工程中
3. 在需要使用数学函数的文件中包含`xyMath.h`文件
4. 调用函数即可

## 已实现的函数
### 常用数学函数
常用数学函数均以m_开头，如m_sqrt、m_pow、m_log、m_exp等。
- 三角函数：sin、cos、tan
- 对数函数：log、log10，以及以2为底的log函数
- 指数函数：exp
- 平方根函数：sqrt
- 绝对值函数：abs
- 乘方函数：pow
- 取整函数：floor、ceil
- 阶乘函数：fact
- pi常量：m_pi
- e常量：m_e
### 矩阵运算
矩阵是一个结构体，包含行数、列数、数据指针。名为Matrix。
- 矩阵初始化：init_matrix
- 矩阵打印：print_matrix
- 释放矩阵：free_matrix
- 二维数组转矩阵：array_to_matrix

## 正在开发的函数
- 矩阵运算：矩阵相加、减法、乘法、除法...
- 向量运算：向量点乘、叉乘、向量长度、单位向量、向量夹角、向量旋转...
- 随机数生成：rand、rand_int、rand_float、rand_normal、rand_gauss
- ...

## 示例
```c
#include "xyMath.h"

int main() {
    double x = 2.0;
    double y = 3.0;
    double z = m_sqrt(x*x + y*y);
    printf("%f\n", z);
    return 0;
}
``` 

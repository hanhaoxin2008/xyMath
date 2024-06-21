
#include "basic.h"
double m_pow(double x, int  n) {
    //计算x的n次方
    //计算原理：
    // 1. 若n为0，则返回1
    // 2. 若n为负数，则返回1/x^(-n)
    // 3. 若n为偶数，则返回x^(n/2)^2
    // 4. 若n为奇数，则返回x^n * x^(n-1)
    if (n == 0) {
        return 1;
    }
    if (n < 0) {
        return 1 / m_pow(x, -n);
    }
    if (n % 2 == 0) {
        double half = m_pow(x, n / 2);
        return half * half;
    }
    return x * m_pow(x, n - 1);
}
int m_fact(int n) {
    //计算阶乘
    //计算原理：
    // 1. 若n为0，则返回1
    // 2. 否则，返回n * fact(n-1)

    if (n == 0) {
        return 1;
    }
    return n * m_fact(n - 1);
}


double m_e(int x){
    // 计算e的近似值
    // 计算原理：
    // 1. 若x为0，则返回1
    // 2. 否则，返回1 + 1/1! + 1/2! + 1/3! + ... + 1/x!
    if (x == 0) {
        return 1;
    }
    int i;
    double result = 1;
    for (i = 1; i <= x; i++) {
        double n=1.0/(double)m_fact(i);
        result +=n;
    }
    return result;
}


double m_sqrt(double x) {
    //牛顿迭代法求平方根
    // 计算原理：
    // 1. 取x/2作为初始猜测值
    // 2. 计算guess^2 - x，若小于误差限，则返回guess
    // 3. 否则，更新guess为(guess + x/guess)/2，重复步骤2
    // 4. 直到guess^2 - x大于误差限，则返回guess

    double guess = x / 2;    // 初始猜测值
    double epsilon = 0.00001; // 误差限
    while (abs(guess * guess - x) > epsilon) {   // 循环，直到误差小于限
        guess = (guess + x / guess) / 2;   // 迭代公式
    }
    return guess;


}
double m_log(double x){
    // CORDIC算法求对数
    // 计算原理：
    // 1. 取1作为初始猜测值
    // 2. 计算guess * guess - x，若小于误差限，则返回guess
    // 3. 否则，更新guess为(guess + x/guess)/2，重复步骤2
    // 4. 直到guess * guess - x大于误差限，则返回guess

    double epsilon = 0.00001; // 误差限
    double guess = 1; // 初始猜测值
    while (abs(guess * guess - x) > epsilon) {   // 循环，直到误差小于限
        guess = (guess + x / guess) / 2;   // 迭代公式
    }
    return guess;


}

double m_log10(double x){
    // 计算log10
    // 计算原理：
    // 1. 计算log(x) / log(10)
    return m_log(x) / m_log(10);

}

double m_log2(double x) {
    // 计算log2
    // 计算原理：
    // 1. 计算log(x) / log(2)
    return m_log(x) / m_log(2);
}

double m_pi() {
    // 计算pi泰勒级数近似值
    // 计算原理：
    // 1. 计算pi = 1/1! - 1/3! + 1/5! - 1/7! + ...
    // 2. 重复1000000次，求和

    double pi = 0;
    int i;
    for (i = 0; i < 1000000; i++) {
        pi += m_pow(-1, i) / (2 * i + 1);
    }

    return 4 * pi;
}
double m_sin(double x) {

    // 计算sin
    // 计算原理：
    // 1. 计算sin(x) = x - x^3/3! + x^5/5! - x^7/7! + ...
    // 2. 重复1000000次，求和

    double result = 0;
    int i;
    for (i = 0; i < 1000000; i++) {
        result += m_pow(-1, i) * m_pow(x, 2 * i + 1) / m_fact(2 * i + 1);
    }
}

int m_floor(double x) {
    // 向下取整
    // 计算原理：
    // 1. 取x的整数部分
    return (int)x;
}
int m_ceil(double x) {
    // 向上取整
    // 计算原理：
    // 1. 取x的整数部分加1
    return (int)x + (x > 0);
}

double m_exp (double x) {
    // 计算e的x次方
    // 计算原理：
    // 1. 计算e^x = 1 + x + x^2/2! + x^3/3! + ...
    // 2. 重复1000000次，求和
    double result = 1;
    int i;
    for (i = 1; i < 1000000; i++) {
        result += m_pow(x, i) / m_fact(i);
    }
    return result;
}

double m_cos(double x) {
    // 计算cos
    // 计算原理：
    // 1. 计算cos(x) = 1 - x^2/2! + x^4/4! - x^6/6! + ...
    // 2. 重复1000000次，求和
    double result = 1;
    int i;
    for (i = 0; i < 1000000; i++) {
        result -= m_pow(x, 2 * i) / m_fact(2 * i);
    }
}
double m_tan(double x) {
    // 计算tan
    // 计算原理：
    // 1. 计算tan(x) = x - x^3/3! + 2x^5/5! - 17x^7/7! + ...
    // 2. 重复1000000次，求和
    double result = 0;
    int i;
    for (i = 0; i < 1000000; i++) {
        result += m_pow(-1, i) * m_pow(x, 2 * i + 1) / (2 * i + 1);
    }
    return result;

}
double random (){
    //拉斯维加斯算法


}





#ifndef XYMATH_BASIC_H
#define XYMATH_BASIC_H
#define m_abs(x) ((x) >= 0? (x) : -(x))
#include "stdlib.h"
#define RAND_MAX 0x7fff
double m_pow(double x, int y);
double m_sqrt(double x);
double m_e(int x);
int m_fact(int x);
double m_log10(double x);
double m_log(double x);
double m_log2(double x);
double m_pi();
double m_sin(double x);
int m_floor(double x);
int m_ceil(double x);
double m_exp(double x);
double m_cos(double x);
double m_tan(double x);
double m_asin(double x);
double m_acos(double x);
double m_atan(double x);
double m_random();



#endif //XYMATH_BASIC_H

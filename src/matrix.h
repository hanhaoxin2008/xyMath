//
// Created by hanha on 2024/6/21.
//

#ifndef XYMATH_MATRIX_H
#define XYMATH_MATRIX_H

//枚举类型
enum  ERROR_CODE {
    ERROR_NONE = 0, //无错误
    ERROR_INVALID_INPUT = -1, //输入参数错误
    ERROR_OUT_OF_MEMORY = -2, //内存不足
};




//预定义数据类型
typedef unsigned  int ERROR;
typedef int INDEX;
typedef double REAL;
typedef short FLAG;
typedef char* STRING;
typedef void* VOIDP;
typedef int INTEGER;

//矩阵结构体
typedef struct {
    INDEX rows; //行数
    INDEX cols; //列数
    REAL* data; //数据指针
} Matrix;

ERROR init_matrix(Matrix* mat, INDEX rows, INDEX cols);//初始化矩阵
void print_error(ERROR err);//打印错误信息
ERROR free_matrix(Matrix* mat);//释放矩阵内存
void print_matrix(Matrix mat);//打印矩阵
//将二维数组转化为矩阵
ERROR array_to_matrix(REAL** arr, Matrix* mat, INDEX rows, INDEX cols);




//初始化矩阵






#endif //XYMATH_MATRIX_H

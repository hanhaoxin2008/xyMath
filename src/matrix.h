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
    ERROR_INDEX_OUT_OF_RANGE = -3,
    ERROR_NULL_POINTER = -4,
    ERROR_NEGATIVE_INPUT = -5, //输入参数为负数
    //维度为零
    ERROR_ZERO_DIMENSION = -6,
    //维度不匹配
    ERROR_DIMENSION_NOT_MATCH = -7,



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
REAL get_matrix_element(Matrix mat, INDEX row, INDEX col);//获取矩阵元素


ERROR array_to_matrix(REAL** arr, Matrix* mat, INDEX rows, INDEX cols);
//矩阵的数乘
ERROR  matrix_num_mul(Matrix* mat,Matrix *res,REAL num);
//矩阵的加法
ERROR  matrix_add(Matrix* mat1, Matrix* mat2, Matrix* res);
//矩阵的减法
ERROR  matrix_sub(Matrix* mat1, Matrix* mat2, Matrix* res);
//矩阵的转置
ERROR  matrix_transpose(Matrix* mat, Matrix* res);
//矩阵的乘法
ERROR  matrix_mul(Matrix* mat1, Matrix* mat2, Matrix* res);
//复制矩阵
ERROR  matrix_copy(Matrix* mat1, Matrix* res);
//生成单位矩阵
ERROR  matrix_identity(INDEX n, Matrix* res);
//矩阵的行列式




#endif //XYMATH_MATRIX_H

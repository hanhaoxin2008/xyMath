//
// Created by hanha on 2024/6/21.
//
#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include "pthread.h"
#include <math.h>


void print_error(ERROR err) {
    switch (err) {
        case ERROR_NONE:
            printf("No error.\n");
            break;

        case ERROR_INVALID_INPUT:
            printf("Invalid input.\n");
            break;

        case ERROR_OUT_OF_MEMORY:
            printf("Out of memory.\n");
            break;
        case ERROR_NEGATIVE_INPUT:
            printf("Negative input.\n");
            break;

        default:
            printf("Unknown error.\n");
            break;
    }
}

// 获取矩阵元素
REAL get_matrix_element(Matrix mat, INDEX row, INDEX col){
    /**
     * 获取矩阵元素
     * @param mat 矩阵
     * @param row 行索引
     * @param col 列索引
     * @return 矩阵元素
     */
    if (row < 0 || row >= mat.rows || col < 0 || col >= mat.cols) {
        return ERROR_INDEX_OUT_OF_RANGE;
    }
    return mat.data[row * mat.cols + col];
}





ERROR init_matrix(Matrix *mat, INDEX row, INDEX col) {
    /**
     * 初始化矩阵
     * @param mat 矩阵指针
     * @param row 行数
     * @param col 列数
     * @return 错误码
     */
    // 检查输入
    if (row <= 0 || col <= 0) {
        return ERROR_NEGATIVE_INPUT;
    }
    // 初始化矩阵
    mat->rows = row;
    mat->cols = col;
    mat->data = (REAL*) malloc(row * col * sizeof(REAL));
    // 检查内存分配
    if (mat->data == NULL) {
        return ERROR_OUT_OF_MEMORY;
    }

    return ERROR_NONE;
}
ERROR free_matrix(Matrix *mat) {
    /**
     * 释放矩阵
     * @param mat 矩阵指针
     * @return 错误码
     */

    // 检查输入
    if (mat->data!= NULL) {
        // 释放内存
        free(mat->data);
        // 重置矩阵
        mat->data = NULL;
    }
    // 重置矩阵维度
    mat->rows = 0;
    mat->cols = 0;
    return ERROR_NONE;
}
void print_matrix(Matrix mat) {
    /**
     * 打印矩阵
     * @param mat 矩阵
     */

    for (INDEX i = 0; i < mat.rows; i++) {
        for (INDEX j = 0; j < mat.cols;  j++) {
            printf("%.2f ", get_matrix_element(mat, i, j));
        }
        printf("\n");
    }
}




ERROR array_to_matrix(REAL** arr, Matrix* mat, INDEX row, INDEX col){
    /**
     * 数组转化为矩阵
     * @param arr 数组指针
     * @param mat 矩阵指针
     * @param row 行数
     * @param col 列数
     * @return 错误码
     */
    // 检查指针是否为空
    if(arr == NULL || *arr == NULL || mat == NULL){
        return ERROR_NULL_POINTER;
    }
    // 检查数组维度是否合法
    if(row == 0 || col == 0){
        return ERROR_ZERO_DIMENSION;
    }
    // 初始化矩阵
    ERROR err = init_matrix(mat, row, col);
    // 检查矩阵初始化是否成功
    if(err != ERROR_NONE){
        return err;
    }
    // 复制数组元素到矩阵
    //矩阵元素索引方式为：mat.data[row * mat.cols + col]
    //数组元素索引方式为：*((REAL*)arr+i*col+j)
    for(INDEX i = 0; i < row; i++){
        for(INDEX j = 0; j < col; j++){
            mat->data[i * mat->cols + j] = *((REAL*)arr+i*col+j);
        }
    }

    return ERROR_NONE;
}
ERROR  matrix_num_mul(Matrix* mat,Matrix *res,REAL num){
    /**
     * 矩阵元素乘以常数
     * @param mat 矩阵指针
     * @param res 结果矩阵指针
     * @param num 常数
     * @return 错误码
     */

    //矩阵数乘规则：矩阵元素*常数
    //检查输入
    if(mat == NULL){
        return ERROR_NULL_POINTER;
    }
    //初始化res
    ERROR err = init_matrix(res, mat->rows, mat->cols);
    if(err != ERROR_NONE){
        return err;
    }
    //矩阵元素乘以常数
    for(INDEX i = 0; i < mat->rows; i++){
        for(INDEX j = 0; j < mat->cols; j++){
            res->data[i * res->cols + j] = mat->data[i * mat->cols + j] * num;
        }
    }
    return ERROR_NONE;
}


ERROR  matrix_add(Matrix* mat1, Matrix* mat2, Matrix* res){
    /**
     * 矩阵加法
     * @param mat1 矩阵1指针
     * @param mat2 矩阵2指针
     * @param res 结果矩阵指针
     * @return 错误码
     */
     //矩阵加法规则：矩阵A(m*n)与矩阵B(m*n)相加，结果矩阵C(m*n)的元素Cij=Aij+Bij
    //检查输入
    if(mat1 == NULL || mat2 == NULL ){
        return ERROR_NULL_POINTER;
    }
    //检查矩阵维度是否相同
    if(mat1->rows != mat2->rows || mat1->cols != mat2->cols ){
        //不同型矩阵不能相加
        return ERROR_DIMENSION_NOT_MATCH;
    }
    //初始化res
    ERROR err = init_matrix(res, mat1->rows, mat1->cols);
    if(err != ERROR_NONE){
        return err;
    }
    //矩阵加法
    for(INDEX i = 0; i < mat1->rows; i++){
        for(INDEX j = 0; j < mat1->cols; j++){
            res->data[i * res->cols + j] = mat1->data[i * mat1->cols + j] + mat2->data[i * mat2->cols + j];
        }
    }
    return ERROR_NONE;

}

ERROR  matrix_sub(Matrix* mat1, Matrix* mat2, Matrix* res){
    /**
     * 矩阵减法
     * @param mat1 矩阵1指针
     * @param mat2 矩阵2指针
     * @param res 结果矩阵指针
     * @return 错误码
     */
     //矩阵减法规则：矩阵A(m*n)减去矩阵B(m*n)，结果矩阵C(m*n)的元素Cij=Aij-Bij
    //检查输入
    if(mat1 == NULL || mat2 == NULL ){
        return ERROR_NULL_POINTER;
    }
    //检查矩阵维度是否相同
    if(mat1->rows != mat2->rows || mat1->cols != mat2->cols ){
        //不同型矩阵不能相减
        return ERROR_DIMENSION_NOT_MATCH;
    }
    //初始化res
    ERROR err = init_matrix(res, mat1->rows, mat1->cols);
    if(err != ERROR_NONE){
        return err;
    }
    //矩阵减法
    for(INDEX i = 0; i < mat1->rows; i++){
        for(INDEX j = 0; j < mat1->cols; j++){
            res->data[i * res->cols + j] = mat1->data[i * mat1->cols + j] - mat2->data[i * mat2->cols + j];
        }
    }
    return ERROR_NONE;
}

//matrix_mul_thread
void* matrix_mul_thread(void* arg){

    struct mat_mul_thread_arg* arg_p = (struct mat_mul_thread_arg*)arg;
    Matrix* mat1 = arg_p->mat1;
    Matrix* mat2 = arg_p->mat2;
    Matrix* res = arg_p->res;
    INDEX row = arg_p->row;
    INDEX col = arg_p->col;
    //矩阵乘法
    REAL sum = 0;
    for(INDEX k = 0; k < mat2->cols; k++){
        sum += mat1->data[row * mat1->cols + k] * mat2->data[k * mat2->cols + col];
    }
    res->data[row * res->cols + col] = sum;
    return NULL;
}




ERROR  matrix_mul(Matrix* mat1, Matrix* mat2, Matrix* res){
    /**
     * 矩阵乘法
     * @param mat1 矩阵1指针
     * @param mat2 矩阵2指针
     * @param res 结果矩阵指针
     * @return 错误码
     */
     //矩阵乘法规则：矩阵A(m*n)与矩阵B(n*p)相乘，结果矩阵C(m*p)的元素Cij=Aik*Bkj
    //检查输入
    if(mat1 == NULL || mat2 == NULL ){
        return ERROR_NULL_POINTER;
    }
    //检查第一个矩阵的列数是否等于第二个矩阵的行数
    if(mat1->cols != mat2->rows ){
        //矩阵维度不匹配
        return ERROR_DIMENSION_NOT_MATCH;
    }
    //初始化res
    ERROR err = init_matrix(res, mat1->rows, mat2->cols);
    if(err != ERROR_NONE){
        return err;
    }
    //矩阵乘法

    if(mat1->rows * mat2->cols <= 100){
        for(INDEX i = 0; i < mat1->rows; i++) {
            for (INDEX j = 0; j < mat2->cols; j++) {
                REAL sum = 0;
                for (INDEX k = 0; k < mat1->cols; k++) {
                    sum += mat1->data[i * mat1->cols + k] * mat2->data[k * mat2->cols + j];
                }
                res->data[i * res->cols + j] = sum;
            }
        }
    }else{
        pthread_t threads[mat1->rows*mat2->cols];
        for(INDEX i = 0; i < mat1->rows; i++){
            for(INDEX j = 0; j < mat2->cols; j++){

                struct mat_mul_thread_arg *arg;

                arg = (struct mat_mul_thread_arg*)malloc(sizeof(struct mat_mul_thread_arg));
                arg->mat1 = mat1;
                arg->mat2 = mat2;
                arg->res = res;
                arg->row = i;
                arg->col = j;
                pthread_create(&threads[i*mat2->cols+j],NULL,matrix_mul_thread, (void*)arg);
            }
        }
        for(INDEX i = 0; i < mat1->rows; i++){
            for(INDEX j = 0; j < mat2->cols; j++){
                pthread_join(threads[i*mat2->cols+j],NULL);
            }
        }
    }

    return ERROR_NONE;
}
ERROR  matrix_transpose(Matrix* mat, Matrix* res){
    /**
     * 矩阵转置
     * @param mat 矩阵指针
     * @param res 结果矩阵指针
     * @return 错误码
     */

    //矩阵转置规则：矩阵A(m*n)的转置矩阵B(n*m)的元素Bij=Aji
    //检查输入
    if(mat == NULL){
        return ERROR_NULL_POINTER;
    }
    //初始化res
    ERROR err = init_matrix(res, mat->cols, mat->rows);
    if(err != ERROR_NONE){
        return err;
    }
    //矩阵转置
    for(INDEX i = 0; i < mat->rows; i++){
        for(INDEX j = 0; j < mat->cols; j++){
            res->data[j * res->cols + i] = mat->data[i * mat->cols + j];
        }
    }
    return ERROR_NONE;
}
ERROR  matrix_copy(Matrix* mat1, Matrix* res){
    /**
     * 矩阵拷贝
     * @param mat1 矩阵1指针
     * @param res 结果矩阵指针
     * @return 错误码
     */
     //矩阵拷贝规则：矩阵A(m*n)的拷贝矩阵B(m*n)的元素Bij=Aij
     if(mat1 == NULL){
         return ERROR_NULL_POINTER;
     }
     //初始化res
     ERROR err = init_matrix(res, mat1->rows, mat1->cols);
     if(err != ERROR_NONE){
         return err;
     }
     //矩阵拷贝
     for(INDEX i = 0; i < mat1->rows; i++){
         for(INDEX j = 0; j < mat1->cols; j++){
             res->data[i * res->cols + j] = mat1->data[i * mat1->cols + j];
         }
     }
     return ERROR_NONE;
}

ERROR  matrix_identity(INDEX n, Matrix* res){
    /**
     * 单位矩阵
     * @param n 矩阵维度
     * @param res 结果矩阵指针
     * @return 错误码
     */
     //单位矩阵规则：n*n的单位矩阵I(n*n)的元素Iij=0,i!=j;Iij=1,i==j

    //检查输入
    if(n <= 0) {
        return ERROR_NEGATIVE_INPUT;
    }
    //初始化res
    ERROR err = init_matrix(res, n, n);
    if(err != ERROR_NONE){
        return err;
    }
    //单位矩阵
    for(INDEX i = 0; i < n; i++){
        for(INDEX j = 0; j < n; j++){
            if(i == j){
                res->data[i * res->cols + j] = 1;
            }else{
                res->data[i * res->cols + j] = 0;
            }
        }
    }
    return ERROR_NONE;

}

REAL matrix_det(Matrix*mat){
    /**
     * 矩阵行列式
     * @param mat 矩阵
     * @return 行列式值
     */
    //矩阵行列式规则：n阶方阵的行列式的值等于n个元素的乘积的排列组合
    //对于n阶方阵，其行列式的值可以由对角线元素的乘积和对角线以下元素的乘积的排列组合得到
    //对于2阶方阵，其行列式的值可以由对角线元素的乘积和对角线以下元素的乘积的排列组合得到
    //对于3阶方阵，其行列式的值可以由对角线元素的乘积和对角线以下元素的乘积的排列组合得到
    //对于n阶方阵，其行列式的值可以由对角线元素的乘积和对角线以下元素的乘积的排列组合得到


    //检查输入
    if(mat == NULL) {
        return ERROR_NULL_POINTER;
    }

    //检查矩阵维度是否合法
    if(mat->rows != mat->cols ){
        //不是方阵
        return ERROR_DIMENSION_NOT_MATCH;
    }

    //2阶方阵
    if(mat->rows == 2){
        return mat->data[0] * mat->data[3] - mat->data[1] * mat->data[2];
    }
    if(mat->rows == 1){
        return mat->data[0];
    }
    //3阶方阵
    if(mat->rows == 3){
        return mat->data[0] * (mat->data[4] * mat->data[8] - mat->data[5] * mat->data[7]) - mat->data[1] * (mat->data[3] * mat->data[8] - mat->data[5] * mat->data[6]) + mat->data[2] * (mat->data[3] * mat->data[7] - mat->data[4] * mat->data[6]);
    }
    //n阶方阵
    REAL det = 0;
    for(INDEX i = 0; i < mat->rows; i++){
        //计算第i行的乘积
        REAL prod = 1;
        for(INDEX j = 0; j < mat->cols; j++){
            if(i != j){
                prod *= mat->data[i * mat->cols + j];
            }
        }
        //计算乘积的排列组合
        if(i % 2 == 0){
            det += prod;
        }else{
            det -= prod;
        }
    }
    return det;
}





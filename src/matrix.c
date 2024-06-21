//
// Created by hanha on 2024/6/21.
//
#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
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

        default:
            printf("Unknown error.\n");
            break;
    }
}


ERROR init_matrix(Matrix *mat, INDEX row, INDEX col) {

    if (row <= 0 || col <= 0) {
        return ERROR_INVALID_INPUT;
    }
    mat->rows = row;
    mat->cols = col;
    mat->data = (REAL*) malloc(row * col * sizeof(REAL));
    if (mat->data == NULL) {
        return ERROR_OUT_OF_MEMORY;
    }
    return ERROR_NONE;
}
ERROR free_matrix(Matrix *mat) {
    if (mat->data!= NULL) {
        free(mat->data);
        mat->data = NULL;
    }
    mat->rows = 0;
    mat->cols = 0;
    return ERROR_NONE;
}
void print_matrix(Matrix mat) {
    for (INDEX i = 0; i < mat.rows; i++) {
        for (INDEX j = 0; j < mat.cols; j++) {
            printf("%.2f ", mat.data[i * mat.cols + j]);
        }
        printf("\n");
    }
}

ERROR array_to_matrix(REAL** arr, Matrix* mat, INDEX row, INDEX col){
    if(arr == NULL || *arr == NULL || mat == NULL){
        return ERROR_INVALID_INPUT;
    }

    if(row == 0 || col == 0){
        return ERROR_INVALID_INPUT;
    }

    ERROR err = init_matrix(mat, row, col);
    if(err != ERROR_NONE){
        return err;
    }
    for(INDEX i = 0; i < row; i++){
        for(INDEX j = 0; j < col; j++){
            mat->data[i * mat->cols + j] = *((REAL*)arr+i*col+j);
        }
    }

    return ERROR_NONE;
}


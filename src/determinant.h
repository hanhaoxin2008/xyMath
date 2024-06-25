#ifndef XYMATH_DETERMINANT_H
#define XYMATH_DETERMINANT_H

enum ERR_CODE {
    ERR_OK = 0, //成功
    ERROR_MALLOC,//内存分配失败

};


typedef unsigned  int ERROR;
typedef int INDEX;
typedef double REAL;

//行列式结构体
typedef struct {
    //阶数
    INDEX n;
    //元素数组
    REAL* elem;
 } DETERMINANT;
//初始化行列式
ERROR det_init(INDEX n,DETERMINANT* det);



#endif //XYMATH_DETERMINANT_H

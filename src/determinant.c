
#include "determinant.h"

#include <stdlib.h>
ERROR det_init(INDEX n,DETERMINANT* det){
    det->n = n;
    det->elem = (REAL*) malloc(n*n*sizeof(REAL));
    if(det->elem == NULL){
        return ERROR_MALLOC;
    }
    return ERR_OK;
}

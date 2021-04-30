#ifndef LAB_MATRIX_H
#define LAB_MATRIX_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    int w1;
    int h1;
    int *arr_M;
    float *arr_A;
    int arr_M_len;
    int arr_A_len;
} matrix1;

void arr_insert(int **arr,int *arrlen,int pos,int len);
float getelem(matrix1 *a,int x,int y);
void setelem(matrix1 *a,int x,int y,float val);
void matrix1_print(matrix1 *a);
void matrix1_printnormal(matrix1 *a);
void matrix1_fromfile(char *filename,matrix1 *m);
int max_elem(matrix1 *a);
void func(matrix1 *a);
void func1(matrix1 *a);


#endif //LAB_MATRIX_H

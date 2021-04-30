#include "mtx7.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



int main(int argc,char *argv[])
{
    if(argc!=2)
    {
        printf("Введите имя файла\n");
        return 1;
    }
    float max = 0;
    matrix1 mtx1={0,0,0,0,0,0};
    matrix1_fromfile(argv[1],&mtx1);
    printf("Стандартный вид матрицы:\n");
    matrix1_printnormal(&mtx1);
    printf("\nВид матрицы по варианту:\n");
    matrix1_print(&mtx1);
    max = max_elem(&mtx1);
    printf("наибольший элемент = %.2f\n", max);
    func1(&mtx1);
    printf("Стандартный вид матрицы после преобразования:\n");
    matrix1_printnormal(&mtx1);
    printf("Вид матрицы по варианту после преобразования:\n");
    matrix1_print(&mtx1);
    return 0;
}

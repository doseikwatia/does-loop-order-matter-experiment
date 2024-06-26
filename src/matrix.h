#include <stdlib.h>
#include <stdio.h>
typedef struct matrix {
    int n_rows;
    int n_cols;
    void* data;
} matrix_t;

matrix_t* mat_new(int row, int col);
void mat_free(matrix_t *m);
size_t _mat_get_row_maj_index(matrix_t *m,  size_t row, size_t col);
float mat_get(matrix_t* m, size_t row, size_t col);
void mat_set(matrix_t*m, size_t row, size_t col, float value);
void mat_randinit(matrix_t *m);
void mat_print(matrix_t *m);
void mat_mul_mnp(matrix_t *A, matrix_t *B, matrix_t *C);
void mat_mul_mpn(matrix_t *A, matrix_t *B, matrix_t *C);
void mat_mul_nmp(matrix_t *A, matrix_t *B, matrix_t *C);
void mat_mul_npm(matrix_t *A, matrix_t *B, matrix_t *C);
void mat_mul_pmn(matrix_t *A, matrix_t *B, matrix_t *C);
void mat_mul_pnm(matrix_t *A, matrix_t *B, matrix_t *C);
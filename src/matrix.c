#include "matrix.h"

matrix_t *mat_new(int row, int col)
{
    size_t size = row * col * sizeof(float);
    matrix_t *matrix = malloc(sizeof(matrix_t));
    void *data = malloc(size);

    matrix->n_cols = col;
    matrix->n_rows = row;
    matrix->data = data;

    return matrix;
}

void mat_free(matrix_t *m)
{
    free(m->data);
    free(m);
}

size_t _mat_get_row_maj_index(matrix_t *m, size_t row, size_t col)
{
    size_t index = ((m->n_rows * col) + row) * sizeof(float);
    return index;
}

float mat_get(matrix_t *m, size_t row, size_t col)
{
    int index = _mat_get_row_maj_index(m, row, col);
    float *valptr = m->data + index;
    float value = *valptr;
    return value;
}

void mat_set(matrix_t *m, size_t row, size_t col, float value)
{
    int index = _mat_get_row_maj_index(m, row, col);
    float *valptr = m->data + index;
    *valptr = value;
}
void mat_randinit(matrix_t *m)
{
    float value;
    for (size_t i = 0; i < m->n_rows; i++)
    {
        for (size_t j = 0; j < m->n_cols; j++)
        {
            value = (float)(rand() % 10);
            mat_set(m, i, j, value);
        }
    }
}
void mat_print(matrix_t *m)
{
    float value;
    printf("\n");
    for (size_t i = 0; i < m->n_rows; i++)
    {
        printf("[ ");
        for (size_t j = 0; j < m->n_cols; j++)
        {
            value = mat_get(m, i, j);
            printf("%.0f ", value);
        }
        printf("]\n");
    }
}

void mat_mul_mnp(matrix_t *A, matrix_t *B, matrix_t *C)
{
    float a, b, c;
    int M = A->n_rows;
    int N = A->n_cols;
    int P = B->n_cols;

    for (int m = 0; m < M; m++)
    {
        for (int n = 0; n < N; n++)
        {
            for (int p = 0; p < P; p++)
            {
                a = mat_get(A, m, n);
                b = mat_get(B, n, p);
                c = mat_get(C, m, p);
                c += a * b;
                mat_set(C, m, p, c);
            }
        }
    }
}

void mat_mul_mpn(matrix_t *A, matrix_t *B, matrix_t *C)
{
    float a, b, c;
    int M = A->n_rows;
    int N = A->n_cols;
    int P = B->n_cols;

    for (int m = 0; m < M; m++)
    {
        for (int p = 0; p < P; p++)
        {
            for (int n = 0; n < N; n++)
            {
                a = mat_get(A, m, n);
                b = mat_get(B, n, p);
                c = mat_get(C, m, p);
                c += a * b;
                mat_set(C, m, p, c);
            }
        }
    }
}

void mat_mul_nmp(matrix_t *A, matrix_t *B, matrix_t *C)
{
    float a, b, c;
    int M = A->n_rows;
    int N = A->n_cols;
    int P = B->n_cols;

    for (int n = 0; n < N; n++)
    {
        for (int m = 0; m < M; m++)
        {
            for (int p = 0; p < P; p++)
            {
                a = mat_get(A, m, n);
                b = mat_get(B, n, p);
                c = mat_get(C, m, p);
                c += a * b;
                mat_set(C, m, p, c);
            }
        }
    }
}

void mat_mul_npm(matrix_t *A, matrix_t *B, matrix_t *C)
{
    float a, b, c;
    int M = A->n_rows;
    int N = A->n_cols;
    int P = B->n_cols;

    for (int n = 0; n < N; n++)
    {
        for (int p = 0; p < P; p++)
        {
            for (int m = 0; m < M; m++)
            {
                a = mat_get(A, m, n);
                b = mat_get(B, n, p);
                c = mat_get(C, m, p);
                c += a * b;
                mat_set(C, m, p, c);
            }
        }
    }
}

void mat_mul_pmn(matrix_t *A, matrix_t *B, matrix_t *C)
{
    float a, b, c;
    int M = A->n_rows;
    int N = A->n_cols;
    int P = B->n_cols;

    for (int p = 0; p < P; p++)
    {
        for (int m = 0; m < M; m++)
        {
            for (int n = 0; n < N; n++)
            {
                a = mat_get(A, m, n);
                b = mat_get(B, n, p);
                c = mat_get(C, m, p);
                c += a * b;
                mat_set(C, m, p, c);
            }
        }
    }
}

void mat_mul_pnm(matrix_t *A, matrix_t *B, matrix_t *C)
{
    float a, b, c;
    int M = A->n_rows;
    int N = A->n_cols;
    int P = B->n_cols;

    for (int p = 0; p < P; p++)
    {
        for (int n = 0; n < N; n++)
        {
            for (int m = 0; m < M; m++)
            {
                a = mat_get(A, m, n);
                b = mat_get(B, n, p);
                c = mat_get(C, m, p);
                c += a * b;
                mat_set(C, m, p, c);
            }
        }
    }
}

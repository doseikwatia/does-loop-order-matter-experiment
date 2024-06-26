#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"

typedef struct experiment
{
    char *name;
    void (*fnptr)(matrix_t *A, matrix_t *B, matrix_t *C);
    double gflops;
} experiment_t;

static experiment_t experiments[] = {
    {"mnp", mat_mul_mnp, 0.0},
    {"mpn", mat_mul_mpn, 0.0},
    {"nmp", mat_mul_nmp, 0.0},
    {"npm", mat_mul_npm, 0.0},
    {"pmn", mat_mul_pmn, 0.0},
    {"pnm", mat_mul_pnm, 0.0},
    {"", NULL, 0.0}};

int main(int argc, char *argv[])
{
    clock_t start, end;
    double cpu_time_used;
    matrix_t *A, *B, *C;

    double n_flop = 0;

    if (argc != 3)
    {
        fprintf(stderr, "Requires two numbers to be passed\n");
        return -1;
    }

    long n_rows = strtol(argv[1], NULL, 10);
    long n_cols = strtol(argv[2], NULL, 10);

    printf("num_rows = %ld, num_cols %ld\n", n_rows, n_cols);

    A = mat_new(n_rows, n_cols);
    B = mat_new(n_cols, n_rows);
    

    srand(time(NULL));

    printf("initializing matrices\n");
    mat_randinit(A);
    mat_randinit(B);

    printf("running experiment\n");

    n_flop = (double)((n_rows * n_rows) * ((2 * n_cols) - 1));
    printf("number of floating point operations %lf \n",n_flop);

    for (experiment_t *exp = experiments; exp->fnptr != NULL; exp++)
    {
        C = mat_new(n_rows, n_rows);
        printf("running %s ...", exp->name);
        start = clock();
        exp->fnptr(A, B, C);
        end = clock();
        cpu_time_used = ((double)(end - start))/CLOCKS_PER_SEC;
        exp->gflops = ((double)n_flop) / (((double)1000000) * cpu_time_used);
        printf(" done in %lf s\n", cpu_time_used);
        mat_free(C);
    }

    printf("|-----|--------|\n");
    printf("| Exp | GFlops |\n");
    printf("|-----|--------|\n");
    for (experiment_t *exp = experiments; exp->fnptr != NULL; exp++)
    {
        printf("| %s | %.3lf |\n", exp->name, exp->gflops);
    }
    printf("|-----|--------|\n");

    mat_free(A);
    mat_free(B);

    return 0;
}
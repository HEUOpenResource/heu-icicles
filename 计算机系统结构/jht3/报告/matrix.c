#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <sys/time.h>

#define N    1000
#define SEED    0x1234

float matrixA[N][N];
float matrixB[N][N];
float matrixC[N][N];

void gen_data(void)
{
    unsigned i,j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            // SEED * 0.1 is used to get duplicated random number
            matrixA[i][j] = (float)(SEED * 0.0001);
            matrixB[i][j] = (float)(SEED * 0.0001);
            matrixC[i][j] = 0;
        }
    }
}

void print_data(void)
{
    // print first 2 and last 2 element.
    printf("%f, %f, %f, %f\n", matrixC[0][0], matrixC[1][1], matrixC[N - 2][N - 2], matrixC[N - 1][N - 1]);
}

void matrix(void)
{
    unsigned i,j,k;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                matrixC[i][j]+=matrixA[i][k]*matrixB[j][k];//假设数组B已完成数据重排 以列主序存储
            }
        }
    }
}

int main(void)
{
    double msecs;
    struct timeval before, after;

    gen_data();
    gettimeofday(&before, NULL);
    matrix();
    gettimeofday(&after, NULL);

    // 1000 is used to convert tv_sec and tv_usec to msec.
    msecs = (after.tv_sec - before.tv_sec) * 1000.0 + (after.tv_usec - before.tv_usec) / 1000.0;
    print_data();
    printf("Execution time = %2.3lf ms\n", msecs);

    return 0;
}
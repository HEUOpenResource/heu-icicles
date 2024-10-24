#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <sys/time.h>
#include <arm_neon.h>

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
    float32x4_t src1, src2, dst, sum;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            sum = vdupq_n_f32(0);
            for (k = 0; k < (N & ((~(unsigned)0x3))); k+=4) {
                src1 = vld1q_f32(&matrixA[i][k]);
                src2 = vld1q_f32(&matrixB[j][k]);
                dst = vmulq_f32(src1, src2);
                sum = vaddq_f32(dst,sum);
            }
            matrixC[i][j] +=  vgetq_lane_f32(sum,0);
            matrixC[i][j] +=  vgetq_lane_f32(sum,1);
            matrixC[i][j] +=  vgetq_lane_f32(sum,2);
            matrixC[i][j] +=  vgetq_lane_f32(sum,3);
            for (; k < N; k++) {
                matrixC[i][j]+=matrixA[i][k]*matrixB[k][j];
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
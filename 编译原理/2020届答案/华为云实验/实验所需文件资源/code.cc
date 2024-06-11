/**
#!/bin/bash
set -ex

clang code.cc -o noOpt.exe
#./noOpt.exe

clang code.cc -O2 -o base.exe
./base.exe

rm -rf profile *.profraw *.profdata *.data

clang++ -O2 -fprofile-instr-generate code.cc -o sample.exe
LLVM_PROFILE_FILE="code-%p.profraw" ./sample.exe &> /dev/null
llvm-profdata merge -output=code.profdata code-*.profraw
clang++ -O2 -fprofile-use=code.profdata -fcs-profile-generate code.cc -o cs_code
./cs_code &> /dev/null
llvm-profdata merge -output=cs_code.profdata code.profdata
clang++ -O2 code.cc -fprofile-use=cs_code.profdata -o pgo.exe
./pgo.exe
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <assert.h>
#include <unistd.h>
#define ARRAY_LEN 80000
int data[ARRAY_LEN];
static struct timeval tm1;
static inline void start() { gettimeofday(&tm1, NULL); }
static inline void stop() {
  struct timeval tm2;
  gettimeofday(&tm2, NULL);
  unsigned long long t =
      1000 * (tm2.tv_sec - tm1.tv_sec) + (tm2.tv_usec - tm1.tv_usec) / 1000;
  printf("Average: %llu ms\n", t);
}
void swap_int(int *a,int *b) {
  int c = *a;
  *a = *b;
  *b = c;
}
void bubble_sort(int *a, int n) {
  int i, t, s = 1;
  for (i = 0; i < n -1; i++) {
    for(int j=0;j<n-1;j++)
      if (a[i] < a[j]) {
        swap_int(&a[i],&a[j]);
      }
  }
}
void sort_array() {
  printf("Bubble sorting array of %d elements\n", ARRAY_LEN);
  bubble_sort(data, ARRAY_LEN);
}
void get_data() {
  if (!access("tmp.data", W_OK)) {
    FILE *fp = fopen ("tmp.data", "r");
    assert(fp != NULL);
    fread(data,ARRAY_LEN*sizeof(int),1,fp);
    fclose(fp);
  } else {
    for (int i = 0; i < ARRAY_LEN; ++i) {
      data[i] = i;
    }
    FILE *fp = fopen ("tmp.data", "w");
    assert(fp != NULL);
    fwrite(data,ARRAY_LEN*sizeof(int),1,fp);
    fclose(fp);
  }
}
int main() {
  get_data();
  start();
  sort_array();
  stop();
  return 0;
}


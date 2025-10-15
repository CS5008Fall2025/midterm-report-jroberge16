#ifndef FIB_H 
#define FIB_H  

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

typedef uint64_t fib_int;
#define FIB_INT_MAX UINT64_MAX

// My Functions for fib
fib_int static inline _check_base_case(int num, int p);
fib_int iterativeFib(int fib_num, int print);
fib_int recursiveFib(int num, int p);
fib_int _dynamic_fib(int num, int p,fib_int *memo);
fib_int dynamicFib(int num, int p);

// My Constants
extern const char algs_names[4][25];
extern fib_int (*fibs[])(int, int);

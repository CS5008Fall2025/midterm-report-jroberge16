#ifndef UTILS_H 
#define UTILS_H  

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>

#include "fib.h"

void helper(void);
void proccess_args(int argc, char *argv[], int *algorithm, int *print, int *fib_number);
void time_it( int alg_type, int fib_num, int p, uint64_t *result, double *time_taken );
int test_one(int algorithm, int fib_num, int print);
int test_all(int fib_num, int print);
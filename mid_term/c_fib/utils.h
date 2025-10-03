#ifndef UTILS_H 
#define UTILS_H  

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "fib.h"
#include "utils.h"

const char algs_names[4][25] = {"Itterative", "Recursive", "Dynamic Programming", "All"};

long int (*fibs[])(int, int) = {
    itterativeFib,
    recursiveFib, 
    dynamicFib
};

// Static functions
void helper(void){
    printf("\n🚀🚀🚀🚀🚀 Welcome to Josh's Fibonacci Benchmarker 🚀🚀🚀🚀🚀\n\n");
    printf("Description:\n\tThis program is used to benchmark the performance differences between different implementations of Fibonacci code\n\n");
    printf("Command Line Arguments\n");
    printf("\t-f int: What Fibonacci number to calculate to\n");
    printf("\t-h: Help\n");
    printf("\t-p: prints infromation about each step (used for debugging)\n");
    printf("\t -a `1-4`: denotes the algorithum followed algorithum selection:\n");
    printf("\t\t 1: itterative Fibonacci solution\n");
    printf("\t\t 2: recursive Fibonacci solution\n");
    printf("\t\t 3: dynamic programming Fibonacci solution\n");
    printf("\t\t 4: All solutions\n");
    printf("\n\n");
}


void proccess_args(int argc, char *argv[], int *algorithum, int *print, int *fib_number){
    int opt;
    while ((opt = getopt(argc, argv, "f:hpa:")) != -1){
        switch(opt){
            case 'h':
                helper();
                exit(1);
            case 'a':
                if (optarg == NULL){
                       printf("ERROR: -a needs an argument\n");
                       helper();
                        exit(1);;
                }
                *algorithum = atoi(optarg) - 1;
                if ((*algorithum > 3) |(*algorithum < 0)){
                       printf("ERROR: You must select an algorithum option\n");
                       helper();
                        exit(1);;
                }
                break;
            case 'p':
                *print = 1;
                break;
            case 'f':
                if (optarg == NULL){
                       printf("ERROR: -f needs an arguments\n");
                       helper();
                        exit(1);;
                }
                *fib_number = atoi(optarg);
                break;
        }
    
    }
    if(*fib_number < 0){
        printf("ERROR: You Msut enter a `-f int` option \n");
        helper();
        exit(1);;

    }
}


double time_it( int alg_type, int fib_num, int p){
    // Setup timers
    struct timespec begin, end;
    // Get the time before we start
    clock_gettime(CLOCK_MONOTONIC, &begin);
    
    // fibs[alg_type](fib_num-1, p);

    // Get the time after we are done
    clock_gettime(CLOCK_MONOTONIC, &end);

    return (end.tv_nsec - begin.tv_nsec) / 1000000000.0 +
           (end.tv_sec - begin.tv_sec);
}


#endif 
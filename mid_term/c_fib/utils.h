#ifndef UTILS_H 
#define UTILS_H  

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>

#include "fib.h"

static const char algs_names[4][25] = {"Iterative", "Recursive", "Dynamic", "All"};

static uint64_t (*fibs[])(int, int) = {
    iterativeFib,
    recursiveFib, 
    dynamicFib
};


/**
 * This displays the help menue
 */
static void helper(void){
    printf("\n🚀🚀🚀🚀🚀 Welcome to Josh's Fibonacci Benchmarker for C 🚀🚀🚀🚀🚀\n\n");
    printf("Description:\n\tThis program is used to benchmark the performance differences between different implementations of Fibonacci code\n\n");
    printf("Command Line Arguments\n");
    printf("\t-f int: What Fibonacci number to calculate to\n");
    printf("\t-h: Help\n");
    printf("\t-p: prints information about each step (used for debugging)\n");
    printf("\t -a `1-4`: denotes the algorithum followed algorithum selection:\n");
    printf("\t\t 1: itterative Fibonacci solution\n");
    printf("\t\t 2: recursive Fibonacci solution\n");
    printf("\t\t 3: dynamic programming Fibonacci solution\n");
    printf("\t\t 4: All solutions\n");
    printf("\n\n");
}

/* 
* this function is used to procee the comment line arguments
* @param argc: Argument count from command line
* @param argv: Argument vector from command line
* @param algorithum: Algorithum number eg => 0: iterative, 1: recursive, 2: dynamic
* @param print: prints debug code
* @param fib_number: The Fibonacci number to calculate
*/
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
            default:
                break;
        }
    
    }
    if(*fib_number < 0){
        printf("ERROR: You Must enter a `-f int` option \n");
        helper();
        exit(1);;

    }
}

/*
* This function is used for timming the our algorithums
* @param alg_type: Algorthum number eg => 0: iterative, 1: recursive, 2: dynamic
* @param fib_num: The Fibonacci number to calculate
* @param print: prints debug code
* @param result: Final results of the fibonacci calculation
* @param time_taken: Total time elsaspaed during the calculation
*/
void time_it( int alg_type, int fib_num, int p, uint64_t *result, double *time_taken ){

    if ((alg_type>2) || (alg_type<0) || (fib_num < 0)){
        exit(1);
    }

    // Setup timers
    struct timespec begin, end;
    // Get the time before we start
    clock_gettime(CLOCK_MONOTONIC, &begin);
    
    *result  = fibs[alg_type](fib_num, p);

    // Get the time after we are done
    clock_gettime(CLOCK_MONOTONIC, &end);

    *time_taken  = (end.tv_nsec - begin.tv_nsec) / 1000000000.0 +
           (end.tv_sec - begin.tv_sec);
}

/**
 * This is used to test one algorithum at a time
 * @param algorithum: Algorithum number eg => 0: iterative, 1: recursive, 2: dynamic
 * @param fib_num: The Fibonacci number to calculate
 * @param print: prints debug code
 * @return: 0 => success, 1 => failure
 */
int test_one(int algorithum, int fib_num, int print){
    uint64_t result;
    double time_taken;
    OPERATION_COUNTER=0;

    if ((algorithum>2) || (algorithum<0) || (fib_num< 0)){
        return 1;
    }
    if(print){
        printf("\n============== 🧮 CALCULATIONS 🧮 ==============\n");
    }
    time_it(algorithum, fib_num, print, &result, &time_taken);

    if(print){
        printf("\n============== 🏁 Results 🏁 ==============\n");
        printf("Algorithum:\t%s\n", algs_names[algorithum]);
        printf("Total Time:\t%.10f\n", time_taken);
        printf("Result for F_%d:\t%ld\n\n", fib_num, result);
    }else{
        printf("f_%d,%s,%.10f,%" PRIu64"\n", fib_num, algs_names[algorithum], time_taken, OPERATION_COUNTER);
    }
    return 0;
}
/*
* This tests all the algorithums at once. Do to time complexity we skip over extreme cases
* @param fib_num: The Fibonacci number to calculate
* @param print: prints debug code
* @return: 0 => success, 1 => failure
*/
int test_all(int fib_num, int print){
    double time_taken[] = {0,0,0};
    uint64_t results[] = {0,0,0};
    if (fib_num< 0){
        return 1;
    }
    for(int i=0; i<3; i++){
        OPERATION_COUNTER = 0;
        // Due to time we will skip large values of n for recursive
        if((i==1) && (fib_num > 48)){
            results[i] = 0;
            time_taken[i] = -1;
        }else{
            time_it(i, fib_num, 0, &results[i], &time_taken[i]);
        }
    }

    if(print){
        printf("\n============== 🏁 Benchmarking All Results 🏁 ==============\n");
        printf("|Fib Number\t|%s\t|%s\t|%s\t|\n", algs_names[0], algs_names[1], algs_names[2]);
        printf("|f_%d\t\t|%.10f\t|%.10f\t|%.10f\t\t|\n", fib_num, time_taken[0], time_taken[1], time_taken[2]);
    }else{
        printf("f_%d,%.10f,%.10f,%.10f\n", fib_num, time_taken[0], time_taken[1], time_taken[2]);
    }
    return 0;
}

#endif 
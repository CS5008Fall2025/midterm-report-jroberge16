
#ifndef FIB_H 
#define FIB_H  

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

// Counts total fib calculations per run
uint64_t OPERATION_COUNTER = 0;

/**
* This function check the base case conditions for the fibonacci sequence
* @param num: The Fibonacci number to calculate
* @param p: prints debug code
* @return: The fibonacci number or -999 if an error occurs
*/
uint64_t static inline _check_base_case(int num, int p){
    if(num==1){
        if(p){
            printf("f_1:\t1\n");
        }
        OPERATION_COUNTER += 1;
        return 1;
    }
    if(num==0){
        if(p){
            printf("f_0:\t0\n");
        }
        OPERATION_COUNTER += 1;
        return 0;
    }else{
        if(p){
            printf("Error:\t-999\n");
        }
        OPERATION_COUNTER += 1;
        return UINT64_MAX;
    }
}


/**
* This is the interative solution for the fibonacci sequence
* @references: [^3]: Lionell, A. (n.d.).
* @param fib_num: The Fibonacci number to calculate
* @param print: prints debug code
* @return: The fibonacci number or -999 if an error occurs
*/
uint64_t iterativeFib(int fib_num, int print){
    if(fib_num <= 1){
        return _check_base_case(fib_num, print);
    }

   uint64_t first_term = 1;
   uint64_t second_term = 0;
   uint64_t fib_calculation = 0;

   OPERATION_COUNTER += 3;
   
   for (int i =2; i <= fib_num; i++){
        fib_calculation = first_term + second_term  ;
        if(print){
            printf("f_%d:\t%ld + %ld = %ld\n", i, first_term,  second_term, fib_calculation);
        }
        
        second_term = first_term;
        first_term = fib_calculation;

        OPERATION_COUNTER += 3;
    }

    return fib_calculation;
}


/**
 * This is the recursive solution for the fibonacci sequence
 * @references: [^3]: Lionell, A. (n.d.).
 * @param fib_num: The Fibonacci number to calculate
 * @param print: prints debug code
 * @return: The fibonacci number or -999 if an error occurs
 */
uint64_t recursiveFib(int num, int p){
    if(num<=1){
        OPERATION_COUNTER += 1;
        return _check_base_case(num, p);
    }
    OPERATION_COUNTER += 1;

    uint64_t result = recursiveFib(num-1, p) + recursiveFib(num-2, p);
    OPERATION_COUNTER += 3;

    if(p){
        printf("f_%d:\t%ld\n",num,  result);
    }
    return result;
}

/*
* private function for dynamicFib
* @param fib_num: The Fibonacci number to calculate
* @param print: prints debug code
* @return: The Fibonacci number or -999 fir errors
*/
uint64_t _dynamic_fib(int num, int p,uint64_t *memo){
    if (num <= 1) {
        OPERATION_COUNTER += 1;
        return _check_base_case(num, p);
    }

    if(memo[num] != 0 ){
        OPERATION_COUNTER += 2;
        return memo[num];
    }
    OPERATION_COUNTER += 2;

    memo[num] = _dynamic_fib(num-1, p, memo) + _dynamic_fib(num-2, p, memo);
    OPERATION_COUNTER += 3;

    if(p){
        printf("f_%d:\t\t%ld\n",num,  memo[num]);
    }

    return memo[num];
 }

/*
* This is the dynamic programming solution for the fibonacci sequence
* @param fib_num: The Fibonacci number to calculate
* @param print: prints debug info
* @return: The fibonacci number or -999 if an error occurs
*/
uint64_t dynamicFib(int num, int p){
    // Need to check this before hand if we go to -1  to 1
    // we return memo[1] + memo[0] , but this never gets assigned in the base case
    if (num <= 1) {
        OPERATION_COUNTER += 1;
        return _check_base_case(num, p);
    }
    
    // allocates memory to 000
    uint64_t  *memo = calloc(num + 1, sizeof( uint64_t));
    OPERATION_COUNTER += 2;

    if(!memo){
        printf("Error -> unable to allocate memory\n");
        return UINT64_MAX;
    }
    OPERATION_COUNTER += 2;

    uint64_t result = _dynamic_fib(num, p, memo );
    free(memo);
    return result;
}


#endif 
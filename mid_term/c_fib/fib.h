
#ifndef FIB_H 
#define FIB_H  

#include <stdint.h>

/*
* This function check the base case conditions for the fibonacci sequence
* @param num: The Fibonacci number to calculate
* resource: https://www.geeksforgeeks.org/c/inline-function-in-c/
* @param p: prints debug code
* @return: The fibonacci number or -999 if an error occurs
*/
uint64_t static inline _check_base_case(int num, int p){
    if(num==1){
        if(p){
            printf("f_1:\t1\n");
        }
        return 1;
    }
    if(num==0){
        if(p){
            printf("f_0:\t0\n");
        }
        return 0;
    }else{
        if(p){
            printf("Error:\t-999\n");
        }
        return -999;
    }
    return num;
}


/*
* This is the intterative solution for the fibonacci sequence
* @param fib_num: The Fibonacci number to calculate
* @param print: prints debug code
* @return: The fibonacci number or -999 if an error occurs
*/
uint64_t itterativeFib(int fib_num, int print){
    if(fib_num < 1){
        return _check_base_case(fib_num, print);
    }

   uint64_t first_term = 0;
   uint64_t second_term = 1;
   uint64_t fib_calculation;

    for (int i =1; i <= fib_num; i++){
        fib_calculation = second_term + first_term ;
        if(print){
            printf("f_%d:\t%ld + %ld = %ld\n", i, first_term,  second_term, fib_calculation);
        }
        second_term = first_term;
        first_term = fib_calculation;
    }

    return fib_calculation;
}


/**
 * This is the Recrisve solution for the fibonacci sequence
 * @param fib_num: The Fibonacci number to calculate
 * @param print: prints debug code
 * @return: The fibonacci number or -999 if an error occurs
 */
uint64_t recursiveFib(int num, int p){
    if(num<=1){
        return _check_base_case(num, p);
    }
    uint64_t result = recursiveFib(num-1, p) + recursiveFib(num-2, p);
    if(p){
        printf("f_%d:\t%ld\n",num,  result);
    }
    return result;
}

/*
* privaste function for dynamicFib
* @param fib_num: The Fibonacci number to calculate
* @param print: prints debug code
* @return: The Fibonacci number or -999 fir errors
*/
uint64_t _dynamic_fib(int num, int p,uint64_t *memo){
    if (num <= 1) {
        return _check_base_case(num, p);
    }

    if(memo[num] != 0 ){
        return memo[num];
    }
    
    memo[num] = _dynamic_fib(num-1, p, memo) + _dynamic_fib(num-2, p, memo);
    if(p){
        printf("f_%d:\t\t%ld\n",num,  memo[num]);
    }
    return memo[num];

 }

/*
* This is the dynaimc programming solution for the fibonacci sequence
* @param fib_num: The Fibonacci number to calculate
* @param print: prints debug code
* @return: The fibonacci number or -999 if an error occurs
*/
uint64_t dynamicFib(int num, int p){
    // Need to check this befroe hand if we go to -1  to 1
    // we return memo[1] + memo[0] , but this never gets assigned in the base case
    if (num <= 1) {
        return _check_base_case(num, p);
    }
    // allocates memory to 000
    uint64_t  *memo = calloc(num + 1, sizeof( uint64_t));
    _dynamic_fib(num, p, memo );
    
    return memo[num];
}


#endif 
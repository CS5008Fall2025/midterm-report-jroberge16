
#ifndef FIB_H 
#define FIB_H  

#include <stdint.h>

uint64_t itterativeFib(int fib_num, int print){

    if (fib_num <0){
        printf("Error: fibnoci number needs to be > 0\n");
        exit(1);
    }
    // base base
    if(fib_num == 0){
        return 0;
    }

   uint64_t first_term = 0;
   uint64_t second_term = 1;
   uint64_t fib_calculation;

    for (int i =1; i-1 <= fib_num; i++){
        fib_calculation = second_term + first_term ;
        if(print){
            printf("f_%d:\t%ld + %ld = %ld\n", i, first_term,  second_term, fib_calculation);
        }
        second_term = first_term;
        first_term = fib_calculation;
    }

    return fib_calculation;
}

uint64_t recursiveFib(int num, int p){
    if(num<=1){
        if(p){
        printf("f_0:\t0\n");
        }
        return num;
    }
    uint64_t result = recursiveFib(num-1, p) + recursiveFib(num-2, p);
    if(p){
        printf("f_%d:\t%ld\n",num,  result);
    }
    return result;
}



uint64_t _dynamic_fib(int num, int p,uint64_t *memo){
    if(num<=1){
        if(p){
        printf("f_0|f_1:\t0|1\n");
        }
        return num;
    }
    if(memo[num] != 0 ){
        return memo[num];
    }
    
    memo[num] = _dynamic_fib(num-1, p, memo) + _dynamic_fib(num-2, p, memo);
    // Only printing one that are caculated
    if(p){
        printf("f_%d:\t%ld\n",num,  memo[num]);
    }
    return memo[num];

 }

uint64_t dynamicFib(int num, int p){

    uint64_t  *memo = calloc(num + 1, sizeof( uint64_t));
    _dynamic_fib(num, p, memo );
    
    return memo[num];
}


#endif 

#ifndef FIB_H 
#define FIB_H  


unsigned long long int itterativeFib(int fib_num, int print){

    if (fib_num <0){
        printf("Error: fibnoci number needs to be > 0\n");
        exit(1);
    }
    // base base
    if(fib_num == 0){
        return 0;
    }

    unsigned long long int first_term = 0;
    unsigned long long int second_term = 1;
    unsigned long long int fib_calculation;

    for (int i =1; i-1 <= fib_num; i++){
        fib_calculation = second_term + first_term ;
        if(print){
            printf("f_%d:\t%llu + %llu = %llu\n", i, first_term,  second_term, fib_calculation);
        }
        second_term = first_term;
        first_term = fib_calculation;
    }

    return fib_calculation;
}

unsigned long long int recursiveFib(int num, int p){
    if(num==0){
        return 0;
    }
    if (num == 1){
        if(p){
        printf("f_1:\t1\n");
        }
        return 1;
    }

    unsigned long long result = recursiveFib(num-1, p) + recursiveFib(num-2, p);
    if(p){
        printf("f_%d:\t%llu\n",num,  result);
    }
    return result;
}

unsigned long long int dynamicFib(int num, int p){
    return 0;
}


#endif 
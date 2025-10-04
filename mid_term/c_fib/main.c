
#include <stdio.h>  
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h>
#include <unistd.h> // gets the getopt option


#include "fib.h"
#include "utils.h"


void test_one(int algorithum, int fib_num, int print){
    uint64_t result;
    double time_taken;
    if(print){
        printf("\n============== 🧮 CALCULATIONS 🧮 ==============\n");
    }
    time_it(algorithum, fib_num, print, &result, &time_taken);

    if(print){
        printf("\n============== 🏁 Results 🏁 ==============\n");
        printf("Algorithum:\t%s\n", algs_names[algorithum]);
        printf("Total Time:\t%.10f\n", time_taken);
        printf("Result for F_%d:\t%ld\n\n", fib_num, result);
    }

}

void test_all(int algorithum, int fib_num, int print){
    double time_taken[] = {0,0,0};
    uint64_t results[] = {0,0,0};
    for(int i=0; i<3; i++){
        // Due to time we will skip large values of n for recursive
        if((i==1) & (fib_num > 48)){
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
        printf("|f_%d|%.10f|%.10f|%.10f|\n", fib_num, time_taken[0], time_taken[1], time_taken[2]);
    }
}


int main(int argc, char *argv[]){
    int algorithum = 0;
    int print = 0;
    int fib_num = -1;

    // processing the command line arguments
    proccess_args(argc, argv, &algorithum, &print, &fib_num);
    if(print){
        printf("Calculating F_%d using %s method\n", fib_num, algs_names[algorithum]);
    }
    if(algorithum<3){
        test_one(algorithum, fib_num, print);
    }else{
        test_all(algorithum, fib_num, print);
    }
    return 0;
}


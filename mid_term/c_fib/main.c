
#include <stdio.h>  
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h>
#include <unistd.h> // gets the getopt option


#include "fib.h"
#include "utils.h"


void test_one(int algorithum, int fib_num, int print){


    double time_taken = time_it(algorithum, fib_num, print);
    
    printf("%s:%.6f seconds\n", algs_names[algorithum], time_taken);
    
}

void test_all(){

}


int main(int argc, char *argv[]){
    int algorithum = 0;
    int print = 0;
    int fib_num = -1;

    // processing the command line arguments
    proccess_args(argc, argv, &algorithum, &print, &fib_num);
    
    if(print){
            printf("\n Results from benchmarking %s", algs_names[algorithum]);
    }

    if(algorithum<4){
        test_one(algorithum, fib_num, print);
    }
    
    return 0;
}


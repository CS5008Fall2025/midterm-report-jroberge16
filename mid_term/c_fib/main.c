
#include <stdio.h>  
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h>
#include <unistd.h> // gets the getopt option


#include "fib.h"
#include "utils.h"


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
        test_all(fib_num, print);
    }
    return 0;
}


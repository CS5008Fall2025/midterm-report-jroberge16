
#include <stdio.h>  
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h>
#include <unistd.h> // gets the getopt option


#include "fib.h"
#include "utils.h"



void test_itterative_solution(){
    printf("hello world");

}




int main(int argc, char *argv[]){
    int algorithum = 0;
    int print = 0;

    // processing the command line arguments
    proccess_args(argc, argv, &algorithum, &print);
    
    if(print){
            printf("\n Results from benchmarking %s", algs_names[algorithum]);
    }

    test_itterative_solution();
    
    return 0;
}


/**
 * Author: Joshua Roberge
 * Date: 2025-14-10
 * Description: This is the main entry and function for the Fibonacci benchmarker
 * 
 * References:
 * [^1]: GeeksforGeeks. (2018, September 10). Getopt() function in C to parse command line arguments. https://www.geeksforgeeks.org/c/getopt-function-in-c-to-parse-command-line-arguments/ 
 * [^2]: GeeksforGeeks. (2025, May 8). Garbage collection in Python. https://www.geeksforgeeks.org/python/garbage-collection-python/ 
 * [^3]: Lionell, A. (n.d.). Module 06: Dynamic Programming. Northeastern. https://northeastern.instructure.com/courses/225849/pages/overview-dynamic-programming 
 */



#include <stdio.h>  
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h>
#include <unistd.h> // gets the getopt option


#include "fib.h"
#include "utils.h"

/**
 * Main function for the Fibonacci benchmarker
 * Description: This program is used to benchmark the performance differences between different implementations of Fibonacci code
 * Command Line Arguments:
 * -f: The Fibonacci number to calculate
 * -a: The algorithm to use (0: iterative, 1: recursive, 2: dynamic, 3: all)
 * -p: prints information for each step (used for debugging)
 * -h: Help
 * 
 * @param argc: Argument count from command line
 * @param argv: Argument vector from command line
 * @return: 0 on success, 1 on failure
 */
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


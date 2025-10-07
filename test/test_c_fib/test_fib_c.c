#include <stdio.h>  
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h>
#include <unistd.h>
#include <stdint.h>
#include <fcntl.h> // For open, O_WRONLY
#include <unistd.h> // For dup, dup2, close
#include <fcntl.h> // For open, O_WRONLY



#include "../../mid_term/c_fib/utils.h"
#include "../../mid_term/c_fib/fib.h"

void suppress_stdout() {
    //https://stackoverflow.com/questions/46728680/how-to-temporarily-suppress-output-from-printf
    fflush(stdout);
    int nullfd = open("/dev/null", O_WRONLY);
    if (nullfd == -1) {
        perror("open /dev/null");
        return;
    }
    dup2(nullfd, STDOUT_FILENO);
    close(nullfd); 
}

void restore_stdout(int original_stdout_fd) {
    fflush(stdout);
    dup2(original_stdout_fd, STDOUT_FILENO);
    close(original_stdout_fd);
}



void print_results(int result, int expectation ,char* function_name){
    if(result==expectation){
        printf("\t\t✅ %s\n", function_name);
    }else{
        printf("\t\t❌ %s\n", function_name);
    }

}


int test_test_one(void){
    printf("\t🧪 Testing test_one function:\n");
    int saved_stdout = dup(STDOUT_FILENO);

    if (saved_stdout == -1) {
        perror("dup");
        return 1;
    }

    suppress_stdout();
    int result_1 = test_one(0, 10, 1);
    int result_2 = test_one(0, 10, 0);
    int result_3 = test_one(0, 0, 0);
    int result_4 = test_one(1, -1, 0);
    int result_5 = test_one(4, 10, 1);
    int result_6 = test_one(-1, 10, 0);
    restore_stdout(saved_stdout);

    print_results(result_1, 0,"test one normal");
    print_results(result_2, 0,"test one no print");
    print_results(result_3, 0,"test one f_0");
    print_results(result_4, 1, "test one f_-1");
    print_results(result_5, 1, "test one alg 4");
    print_results(result_6, 1, "test one alg -1");

    return 0;
}


int test_test_all(void){
    printf("\t🧪 Testing test_one function:\n");
    int saved_stdout = dup(STDOUT_FILENO);

    if (saved_stdout == -1) {
        perror("dup");
        return 1;
    }

    suppress_stdout();
    int result_1 = test_all(10, 1);
    int result_2 = test_all(10, 0);
    int result_3 = test_all(-1, 0);
    restore_stdout(saved_stdout);

    print_results(result_1, 0,"test_all normal");
    print_results(result_2, 0,"test_all no print");
    print_results(result_3, 1,"test_all f_-1");


    return 0;
}

void test_time_it(void){
    uint64_t result = -1;
    double time_taken = -1 ;

    printf("\t🧪 Testing time_it:\n");

    time_it(1, 5, 0, &result, &time_taken);

    if((result != -1) & (time_taken != -1.0)){
        print_results(1, 1,"Time it normal");
    }else{
        print_results(1, 0,"Time it normal");
    }

}

void test_proccess_args(){

    printf("\t🧪 Processing Arguments:\n");

    int algorithum = 1;
    int print = 0;
    int fib_num = 5;
    char *argv[] = {"program_name", "-a", "1", "-f", "5"};
    int argc = 5;

    proccess_args(argc, argv, &algorithum, &print, &fib_num);
    if(algorithum == 0 && print == 0 && fib_num == 5){
        print_results(1, 1,"proccess_args normal");
    }else{
        print_results(1, 0,"proccess_args normal");
    }
    // I manually tested some of the exit on error function
    // Can put that in code sinze it ends the program by design.
}

void test_recursiveFib(void){
    printf("\t🧪 Testing recursiveFib:\n");
    int result_1 = recursiveFib(5, 0);
    int result_2 = recursiveFib(0, 0);
    int result_3 = recursiveFib(1, 0);
    int result_4 = recursiveFib(10, 0);
    int result_5 = recursiveFib(-1, 0);

    print_results(result_1, 5,"recursiveFib f_5");
    print_results(result_2, 0,"recursiveFib f_0");
    print_results(result_3, 1,"recursiveFib f_1");
    print_results(result_4, 55,"recursiveFib f_10");
    print_results(result_5, -999,"recursiveFib f_-1"); //
    // I manually tested print... It works as expected
}

void test_itterativeFib(void){
    printf("\t🧪 Testing itterativeFib:\n");
    int result_1 = itterativeFib(5, 0);
    int result_2 = itterativeFib(0, 0);
    int result_3 = itterativeFib(1, 0);
    int result_4 = itterativeFib(10, 0);
    int result_5 = itterativeFib(-1, 0);

    print_results(result_1, 5,"itterativeFib f_5");
    print_results(result_2, 0,"itterativeFib f_0");
    print_results(result_3, 1,"itterativeFib f_1");
    print_results(result_4, 55,"itterativeFib f_10");
    print_results(result_5, -999,"itterativeFib f_-1"); //
    // I manually tested print... It works as expected
}

void test_dynamicFib(void){
    printf("\t🧪 Testing dynamicFib:\n");
    int result_1 = dynamicFib(5, 0);
    int result_2 = dynamicFib(0, 0);
    int result_3 = dynamicFib(1, 0);
    int result_4 = dynamicFib(10, 0);
    int result_5 = dynamicFib(-1, 0);

    print_results(result_1, 5,"dynamicFib f_5");
    print_results(result_2, 0,"dynamicFib f_0");
    print_results(result_3, 1,"dynamicFib f_1");
    print_results(result_4, 55,"dynamicFib f_10");
    print_results(result_5, -999,"dynamicFib f_-1"); //
    // I manually tested print... It works as expected
}



void test_utils(void){ 
    test_test_one();
    test_test_all();
    test_time_it();
    test_proccess_args();
    test_recursiveFib();
    test_itterativeFib();
    test_dynamicFib();

}

int main(int argc, char *argv[]){
    printf("================== 🧪 Testing C-Fib Code 🧪 ==================\n");
    test_utils();
    return 0;
} 
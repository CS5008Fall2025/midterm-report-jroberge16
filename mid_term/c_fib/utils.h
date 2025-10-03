
const char algs_names[4][25] = {"Itterative", "Recursive", "Dynamic Programming", "All"};

// Static functions
void helper(void){
    printf("\n🚀🚀🚀🚀🚀 Welcome to Josh's Fibonacci Benchmarker 🚀🚀🚀🚀🚀\n\n");
    printf("Description:\n\tThis program is used to benchmark the performance differences between different implementations of Fibonacci code\n\n");
    printf("Command Line Arguments\n");
    printf("\t-h: Help\n");
    printf("\t-p: prints infromation about each step (used for debugging)\n");
    printf("\t -a `1-4`: denotes the algorithum followed algorithum selection:\n");
    printf("\t\t 1: itterative Fibonacci solution\n");
    printf("\t\t 2: recursive Fibonacci solution\n");
    printf("\t\t 3: dynamic programming Fibonacci solution\n");
    printf("\t\t 4: All solutions\n");
    printf("\n\n");
}

void proccess_args(int argc, char *argv[], int *algorithum, int *print){
    int opt;
    while ((opt = getopt(argc, argv, "hpva:")) != -1){
        switch(opt){
            case 'h':
                helper();
                abort();;
            case 'a':
                *algorithum = atoi(optarg);
                if ((*algorithum > 4) |(*algorithum < 1)){
                        helper();
                       abort();;
                }
            case 'p':
                *print = 1;
        }
    }
}
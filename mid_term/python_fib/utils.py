import argparse

def print_help():
    print("\n🚀🚀🚀🚀🚀 Welcome to Josh's Fibonacci Benchmarker for Python 🚀🚀🚀🚀🚀\n")
    print("Description:")
    print("\tThis program is used to benchmark the performance differences between different implementations of Fibonacci code\n")
    print("Command Line Arguments")
    print("\t-f int: What Fibonacci number to calculate to")
    print("\t-h: Help")
    print("\t-p: Prints information about each step (used for debugging)")
    print("\t-a `1-4`: Denotes the algorithm selection:")
    print("\t\t1: Iterative Fibonacci solution")
    print("\t\t2: Recursive Fibonacci solution")
    print("\t\t3: Dynamic programming Fibonacci solution")
    print("\t\t4: All solutions")
    print("\n")



def process_args():
    
    parser = argparse.ArgumentParser(description="Argument Parser of Pytthon Fib")

    parser.add_argument("-a", 
                        default=4,
                        type=int, 
                        help="algorithum number (0: iterative, 1: recursive, 2: dynamic, 3: all)")
    parser.add_argument("-f", 
                        default=5,
                        type=int, help="fibonaci number")
    parser.add_argument("-p", 
                        default=False,
                        action="store_true",
                        help="prints debug code")
    parser.add_argument("-help", 
                        default=False,
                        action="store_true",
                        help="help menue")
    args = parser.parse_args()

    if args.help:
        print_help()
        exit(0)
    return args

"""
Author: Joshua Roberge
Date: 2025-10-14
Description: Contains utility the utilities for the python fibonacci program.
"""

from typing import List, Dict, Any, Tuple
import argparse

from mid_term.python_fib.fib import RecursiveFib, IterativeFib, DynamicFib, FibonacciAlgorithm


algs: List[Tuple[str, FibonacciAlgorithm]] = [("Iterative", IterativeFib), ( "Recursive",RecursiveFib), ("Dynamic", DynamicFib)]

def print_help() -> None:
    """
    This function prints the help menu
    """
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

def process_args() -> argparse.Namespace:
    """
    This code is for processing the command line arguments
    References: [^1] GeeksforGeeks. (2018, September 10)
    """
    
    parser = argparse.ArgumentParser(description="Argument Parser of Python Fib")

    parser.add_argument("-a", 
                        default=4,
                        required=True,
                        type=int,
                        help="algorithm number (0: iterative, 1: recursive, 2: dynamic, 3: all)")
    parser.add_argument("-f", 
                        default=5,
                        required=True,
                        type=int, help="fibonacci number")
    parser.add_argument("-p", 
                        default=False,
                        action="store_true",
                        help="prints debug code")
    parser.add_argument("-help", 
                        default=False,
                        action="store_true",
                        help="help menu")
    args = parser.parse_args()
    
    if args.a < 1:
        print("❌ algorithm selection must be between 1-4")
        exit(0)
    if args.f < 0:
        print("❌ Fibonacci number must be greater than or equal to 0")
        exit(0)
    if args.help:
        print_help()
        exit(0)
    args.a -= 1

    return args




def run_one(alg:int, fib_num:int, p:bool) -> Dict[str, Any]:
    """
    This function test one of the algorithms for fibonacci sequence
    args:
        alg: int = algorithm number (0: iterative, 1: recursive, 2: dynamic)
        fib_num: int = fibonacci number to calculate to
        p: bool = print debug statements
    returns:
        dict = {"Elapsed_Time": float, "Result": int}
    """
    if alg<0 or alg>2 or fib_num < 0:
        raise ValueError("Error with Alg or Fib Number")
    
    alg_name:str = algs[alg][0]
    alg_func:FibonacciAlgorithm = algs[alg][1]
    alg_func:FibonacciAlgorithm = algs[alg][1](print_debug = p)
    
    if p:
        print(f"============== 🧮 CALCULATIONS for {alg_name} Fibonacci Sequence 🧮 ==============")
    
    result = alg_func.time_it(fib_num)
    if p:
        print("\n============== 🏁 Results 🏁 ==============\n");
        print(f"Algorithm:\t{alg_name}")
        print(f"Total Time:\t{result[1]}")
        print(f"Result for F_{fib_num}:\t{result[0]}")

    return {"Elapsed_Time": result[1], "Result": result[0],"Operation Count": alg_func.operation_cnt}

def run_all(fib_num:int, p: bool) -> str:
    """
    This function Test all the algorithms for fibonacci sequence
    args:
        fib_num: int = fibonacci number to calculate to
        p: bool = print debug statements
    returns:
        str = csv row
    """
    time_taken: List[int] = [0,0,0]
    results: List[int] = [0,0,0]

    if fib_num < 0:
        raise ValueError("Fib Number must be greater then 0")
    
    for i in range(3):
        ## Skipping for recursive to save time
        if i ==1 and fib_num > 40:
            results[i] = -1
            time_taken[i] = -1
        else:
            fib_cls = algs[i][1](print_debug = 0)
            results[i], time_taken[i] = fib_cls.time_it(fib_num)

    if p:
        print("\n============== 🏁 Benchmarking All Results 🏁 ==============")
        print(f"|Fib Number\t|{algs[0][0]}\t|{algs[1][0]}\t|{algs[2][0]}\t|")
        print(f"|f_{fib_num}\t\t|{time_taken[0]:.10f}\t|{time_taken[1]:.10f}\t|{time_taken[2]:.10f}\t|")
    

    return f"f_{fib_num},{time_taken[0]:.10f},{time_taken[1]:.10f},{time_taken[2]:.10f}"

    


if __name__ == "__main__":
        test_all(5, True)




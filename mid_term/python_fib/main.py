"""
Author: Joshua Roberge
Date: 2025-10-14

Description: Main Entry point for the python fibonacci program.

References:
[^1]: GeeksforGeeks. (2018, September 10). Getopt() function in C to parse command line arguments. https://www.geeksforgeeks.org/c/getopt-function-in-c-to-parse-command-line-arguments/ 
"""



from mid_term.python_fib.utils import process_args, run_one, run_all, algs
import sys
sys.setrecursionlimit(10000000)

def main():
    """
    Main Entry point of the program

    args:
        None
    returns:
        None
    """
    args = process_args()
    if args.a >= 3:
        result: int = run_all(args.f, args.p)
        print(result)
        return result
    else:
        result: int = run_one(args.a, args.f, args.p)
        print(result)
        print(f"f_{args.f},{algs[args.a][0]},{result['Elapsed_Time']:.10f}, {result['Operation Count']}")
        return result

if __name__ == "__main__":
    # import sys
    # sys.argv = ["prog", "-a", "3", "-f", "20", "-p"]
    main()

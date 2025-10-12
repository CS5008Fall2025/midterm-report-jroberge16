from mid_term.python_fib.utils import process_args, test_one, test_all, algs
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
        result: int = test_all(args.f, args.p)
        print(result)
        return result
    else:
        result: int = test_one(args.a, args.f, args.p)
        print(f"f_{args.f},{algs[args.a][0]},{result['Elasped_Time']:.10f}, {result['Operation Count']}")
        return result

if __name__ == "__main__":
    main()

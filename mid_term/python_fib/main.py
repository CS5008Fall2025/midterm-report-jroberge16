from mid_term.python_fib.utils import process_args, test_one, test_all


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
        result = test_all(args.f, args.p)
        print(result)
        return result
    else:
        result = test_one(args.a, args.f, args.p)
        print(result)
        return result

if __name__ == "__main__":
    main()

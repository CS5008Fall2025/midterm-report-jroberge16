import pytest

from mid_term.python_fib.main import main

import sys



def test_main():
    # Testing Main Function Iterative Arguments
    sys.argv = ["prog", "-a", "1", "-f", "5"]
    results = main()
    print(results)
    assert results["Result"] == 5

    # Testing Main Function Recursive Arguments
    sys.argv = ["prog", "-a", "2", "-f", "5"]
    results = main()
    print(results)
    assert results["Result"] == 5

    # Testing Main Function Recursive Arguments
    sys.argv = ["prog", "-a", "4", "-f", "5"]
    results = main()
    assert results.split(',')[0] == "f_5"

    sys.argv = ["prog", "-a", "0", "-f", "5"]
    with pytest.raises(SystemExit):
        main()



if __name__ == "__main__":
    test_main()

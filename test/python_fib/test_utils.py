import pytest
import sys

from mid_term.python_fib.utils import process_args, test_one, test_all, print_help

def test_utils():
    # Testing Process Args
    sys.argv = ["prog", "-a", "1", "-f", "5"]
    args = process_args()
    assert args.a == 0
    assert args.f == 5
    assert args.p == False
    print(args)

    # testing Bad Args
    sys.argv = ["prog", "-a", "0", "-f", "5"]
    with pytest.raises(SystemExit):
        process_args()

    # Testing Help
    sys.argv = ["prog", "-help", "True"]
    with pytest.raises(SystemExit):
        process_args()

    # Testing print help
    print_help()


    # test one
    results = test_one(0, 5, True)
    assert results["Result"] == 5

    with pytest.raises(ValueError):
        results = test_one(1, -5, False)
        assert results["Result"] == -999
    
    with pytest.raises(ValueError):
        results = test_one(8, 5, False)
        assert results["Result"] == 5

    
    # Test all with print
    results = test_all(5, True)
    assert results.split(',')[0] == "f_5"

    # test all bad
    with pytest.raises(ValueError):
        results = test_all(-5, False)
        assert results == ""



if __name__ == "__main__":
    # test_utils()
    pytest.main()
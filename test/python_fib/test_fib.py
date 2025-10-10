import pytest
from mid_term.python_fib.fib import RecursiveFib, DynamicFib, ItterativeFib



@pytest.mark.parametrize("fib_num, expectation", [
    (5, 5),
    (0, 0),
    (10, 55),
    (-1, None)
])
def test_recursive_fib(fib_num, expectation):
    fib = RecursiveFib(print_debug=False)
    assert fib.calculate(fib_num) == expectation


@pytest.mark.parametrize("fib_num ,expectation", [
    (5, 5),
    (0, 0),
    (10, 55),
    (-1, None)
])
def test_dynamic_fib(fib_num, expectation):
    fib = DynamicFib(print_debug=False)
    assert fib.calculate(fib_num) == expectation


@pytest.mark.parametrize("fib_num ,expectation", [
    (5, 5),
    (0, 0),
    (10, 55),
    (-1, None)
])
def test_itterative_fib(fib_num, expectation):
    fib = ItterativeFib(print_debug=False)
    assert fib.calculate(fib_num) == expectation

if __name__ == "__main__":
    pytest.main()
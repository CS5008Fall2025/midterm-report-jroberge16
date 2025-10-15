"""
Author: Joshua Roberge
Date: 2025-10-14
Description: Contains the Fibonacci implementations for the python fibonacci program.
"""

from typing import Dict, Any, List
from abc import ABC, abstractmethod
import time
import gc

class FibonacciAlgorithm(ABC):
    """
    Abstract Base Class for fibonacci sequence

    Attributes:
        * print_debug: makes the print statements verbose
    """
    def __init__(self, print_debug: bool = False):
        """
        Attributes:
            * print_debug: makes the print statements verbose
        """
        self.print_debug = print_debug
        self.operation_cnt = 0

    def time_it(self, n) -> tuple[int, float]:
        """
        Method for timing the fibonacci calculation
        args:
            n= fibonacci number
        returns: tuple of fibonacci number and time taken to calculate
        """
        start_time = time.time()
        result = self.calculate(n)
        end_time = time.time()
        gc.collect()
        return result, end_time - start_time
    
    def _check_base_case(self, num) -> int:
        """
        Private Method for checking the base case conditions for fibonacci sequence
        args:
            num= fibonacci number
        returns: fibonacci number or -999 for error
        """
        self.operation_cnt += 1
        match num:
            case 1:
                if self.print_debug:
                    print("f_1:\t1\n")
                return 1
            case 0:
                if self.print_debug:
                    print("f_0:\t0\n")
                return 0
            case _:
                if self.print_debug:
                    print("Error")
                return None
            
    @abstractmethod
    def calculate(self, n: int) -> int:
        """
        private method for calculating fibonacci sequence
        args:
            n= fibonacci number
        """
        raise NotImplementedError("Must override this method")


class IterativeFib(FibonacciAlgorithm):
    """
    This is the iterative implementation of
    fibonacci sequence

    Attributes:
        * print_debug: makes the print statements verbose
    """

    def calculate(self, n):
        """
        method for for calculating fibonacci sequence
        args:
            n= fibonacci number
        """
        if n <= 1:
            self.operation_cnt += 1
            return self._check_base_case(n)
        first_term: int = 1
        second_term: int = 0

        self.operation_cnt += 3

        for i in range(2,n+1):
            calculation: int = first_term + second_term
            
            if self.print_debug:
                print(f"f_{i}:\t{first_term} + {second_term} = {calculation}")
            second_term = first_term
            first_term = calculation

            self.operation_cnt += 3

        return calculation


class RecursiveFib(FibonacciAlgorithm):
    """
    This is the recursive implementation of
    fibonacci sequence

    Attributes:
        * print_debug: makes the print statements verbose
    """
    def calculate(self, n) -> int:
        """
        method for  for calculating fibonacci sequence
        args:
            n= fibonacci number
        """
        if n <= 1:
            self.operation_cnt += 1
            return self._check_base_case(n)
        self.operation_cnt += 1

        result: int = self.calculate(n-1) + self.calculate(n-2)
        self.operation_cnt += 3
        
        if self.print_debug:
            print(f"f_{n}:\t{result}")
        
        return result

class DynamicFib(FibonacciAlgorithm):
    """
    This is the memoization implementation of
    fibonacci sequence

    Attributes:
        * print_debug: makes the print statements verbose
    """

    def _calculate(self, n:int) -> int:
        """
        private method for calculating fibonacci sequence
        args:
            n= fibonacci number
        """
        if(n<=1):
            self.operation_cnt += 1
            return self._check_base_case(n)
        
        if(self.memo[n]!=0):
            self.operation_cnt += 2
            return self.memo[n]
        
        self.operation_cnt += 2
        self.memo[n] = self._calculate(n-1) +  self._calculate(n-2)
        self.operation_cnt += 3

        if(self.print_debug):
            print(f"f_{n}:\t{self.memo[n-1]} +"
                  +f" {self.memo[n-2]} = {self.memo[n-1]+self.memo[n-2]}")

        return self.memo[n]
        

    def calculate(self, n:int) -> int:
        """
        method for calculating fibonacci sequence
        args:
            n= fibonacci number
        """
        if(n<=1):
            self.operation_cnt += 1
            return self._check_base_case(n)
        
        self.memo: List[int] = [0] * (n+1)
        
        self.operation_cnt += 4

        result = self._calculate(n)
        return result


        


if __name__ == "__main__":
    recur = DynamicFib(print_debug=True)
    x = recur.calculate(25)
    print(x)

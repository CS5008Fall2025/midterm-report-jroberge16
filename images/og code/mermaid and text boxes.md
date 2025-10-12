<div style="display: flex; gap: 10px;">

<div style="flex: 1;">

**Pseudocode: Fibonacci Iterative**
```text
1.  FUNCTION iterative_fib(n):
2. 	 IF n == 0:
3.         		RETURN 0
4.    	 ELSE IF n == 1:
5.         		RETURN 1
6.    	 END IF
7.     	first_term = 0
8.     	second_term = 1
9.     	FOR i FROM 2 TO n:
10.        		calculation = first_term + second_term
11.        		first_term = second_term
12.        		second_term = calculation
13.    	END FOR
14.   	 RETURN calculation
```
</div>

<div style="flex: 1;">

**Proof: Fibonacci Iterative**
> Let $T(n)$ be $O(n)$ if and only if $\exists c, \forall n \ge n_0$ such that $T(n)\le c \cdot g(n)$
> 
> $$
> \begin{align*}
c \cdot g(n) &\ge T(n) \\
c \cdot g(n) &\ge (n-1)*3 + 4 \\
c \cdot g(n) &\ge 3\cdot n - 3 + 4 \\
c \cdot g(n) &\ge 3\cdot n + 1
> \end{align*}
> $$
>
> We can now choose $c=4$ and $n_0=1$, and by definition prove that:
> 
> $$
> \begin{align*}
> T(n) &\le c \cdot g(n) \\
> 3\cdot n + 1 &\le 4 \cdot n \\
> \therefore T(n) &= O(n)
> \end{align*}
> $$

</div> </div>
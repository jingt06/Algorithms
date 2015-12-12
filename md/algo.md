##What is Algorithm
**Algorithm**: An Algorithm is a step-by-step process for carrying out a series of computations, given an arbitary problem instance I.

**Efficiency**: Running Time and Space(Memory) 

##Order Notation:
 
**O-notation**: f (n) ∈ O(g(n)) if there exist constants c > 0 and n0 > 0
such that 0 ≤ f (n) ≤ c g(n) for all n ≥ n0.

**Ω-notation**: f (n) ∈ Ω(g(n)) if there exist constants c > 0 and n0 > 0
such that 0 ≤ c g(n) ≤ f (n) for all n ≥ n0.

**Θ-notation**: f (n) ∈ Θ(g(n)) if there exist constants c1, c2 > 0 and n0 > 0
such that 0 ≤ c1 g(n) ≤ f (n) ≤ c2 g(n) for all n ≥ n0.

**o-notation**: f (n) ∈ o(g(n)) if for all constants c > 0, there exists a
constant n0 > 0 such that 0 ≤ f (n) < c g(n) for all n ≥ n0.

**ω-notation**: f (n) ∈ ω(g(n)) if for all constants c > 0, there exists a
constant n0 > 0 such that 0 ≤ c g(n) < f (n) for all n ≥ n0.

##Growth Rates
If f (n) ∈ Θ(g(n)), then the growth rates of f (n) and g(n) are **the same**.

If f (n) ∈ o(g(n)), then we say that the growth rate of f (n) is **less than** the growth rate of g(n).

If f (n) ∈ ω(g(n)), then we say that the growth rate of f (n) is **greater than** the growth rate of g(n).

###Common Growth Rates
Θ(1) (constant complexity),

Θ(log n) (logarithmic complexity ),

Θ(n) (linear complexity ),

Θ(n log n)(pseudo-linear complexity ),

Θ(n^2) (quadratic complexity ),

Θ(n^3) (cubic complexity),

Θ(2^n) (exponential complexity ).

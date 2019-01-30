# Dynamic Programming

An algorithmic paradigm that solves a given complex problem by breaking it into subproblems and stores the results of subproblems to avoid computing the same results again. </br>
## Property
1. Overlapping Subproblem : Like Divide and Conquer, Dynamic Programming combines solutions to sub-problems.
	- Memoization (Top down) : The memoized program for a problem is similar to the recursive version with a small modification that it looks into a lookup table before computing solutions. (initialize a lookup array with all initial values as NIL.)

	- Tabulation (Bottom Up) : The tabulated program for a given problem builds a table in bottom up fashion and returns the last entry from table.

2. Optimal substructure : A given problems has Optimal Substructure Property if optimal solution of the given problem can be obtained by using optimal solutions of its subproblems. 
	- Floyd-Warshall, Bellman-Ford
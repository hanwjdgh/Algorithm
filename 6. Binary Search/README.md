# Binary Search

Search a sorted array by repeatedly dividing the search interval in half. Begin with an interval covering the whole array.

- pseudocode
```bash
function binary_search(A, n, T):
    L := 0
    R := n − 1
    while L <= R:
        m := floor((L + R) / 2)
        if A[m] < T:
            L := m + 1
        else if A[m] > T:
            R := m - 1
        else:
            return m
    return unsuccessful
```

## parametric search
## upper bound
## lower bound
# Union_Find

A disjoint-set data structure is a data structure that keeps track of a set of elements partitioned into a number of disjoint (non-overlapping) subsets. A union-find algorithm is an algorithm that performs two useful operations on such a data structure:

* Find : Determine which subset a particular element is in. This can be used for determining if two elements are in the same subset.
```bash
int find(int n) {
	if (n == par[n])
		return n;
	return par[n] = find(par[n]);
}
```

* Union : Join two subsets into a single subset.
```bash
void union(int a, int b) {
	a = find(a);
	b = find(b);
	par[b] = a;
}
```
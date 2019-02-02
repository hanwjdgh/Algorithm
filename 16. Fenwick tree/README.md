# Fenwick tree (Binary indexed tree)

Fenwick tree is a data structure that can efficiently update elements and calculate prefix sums in a table of numbers.

<img width="500" height="250" src="https://user-images.githubusercontent.com/23069776/42729522-c223ac04-8815-11e8-8162-cc6443494994.png"></img>

## Operations
- update
```bash
void update(vector<long long> &tree, int i, long long diff) {
	while (i < tree.size()) {
		tree[i] += diff;
		i += (i&-i);
	}
}
```

- sum
```bash
long long sum(vector<long long> &tree, int i) {
	long long ans = 0;
	while (i > 0) {
		ans += tree[i];
		i -= (i&-i);
	}
	return ans;
}
```

## Index
When you represent a number X as a binary number, you need to know the position of the last one using -> i & -i </br>
```bash
-i = ~i + 1
```
~i = 1's complement , -i = 2's complement
## Complexity
- time : O(log N)

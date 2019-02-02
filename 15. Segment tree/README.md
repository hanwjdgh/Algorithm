# Segment tree

Segment Tree is a basically a binary tree used for storing the intervals or segments. Each node in the Segment Tree represents an interval. 

<img width="500" height="250" src="https://user-images.githubusercontent.com/23069776/42729454-1f48a382-8814-11e8-98d0-15030940c130.png"></img>

## Tree init
```bash
int tree_size = (1 << ((int)ceil(log2(N)) + 1));
```
<img width="500" height="200" src="https://user-images.githubusercontent.com/23069776/42729456-36b33032-8814-11e8-9ec0-96886a623421.png"></img>

```bash
long long init(vector<long long> &tree, int node, int start, int end) {
	if (start == end)
		return tree[node] = initv[start];

	int mid = (start + end) / 2;

	return tree[node] = init(tree, node * 2, start, mid) + init(tree, node * 2 + 1, mid + 1, end);
}
```

## Operations
- update
```bash
void update(vector<long long> &tree, int node, int start, int end, int index, long long diff) {
	if (!(start <= index && index <= end))
		return;

	tree[node] += diff;

	if (start != end) {
		int mid = (start + end) / 2;
		update(tree, node * 2, start, mid, index, diff);
		update(tree, node * 2 + 1, mid + 1, end, index, diff);
	}
}
```

- query
```bash
long long query(vector<long long> &tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return 0;

	if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end) / 2;
	return query(tree, node * 2, start, mid, left, right) + query(tree, node * 2 + 1, mid + 1, end, left, right);
}
```

## Complexity
- time : O(log N)

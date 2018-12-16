#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

vector<int> A(5000001, 0), B;
vector<int> initv;

long long init(vector<long long> &tree, int node, int start, int end) {
	if (start == end)
		return tree[node] = initv[start];

	int mid = (start + end) / 2;

	return tree[node] = init(tree, node * 2, start, mid) + init(tree, node * 2 + 1, mid + 1, end);
}

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

long long query(vector<long long> &tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return 0;

	if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end) / 2;
	return query(tree, node * 2, start, mid, left, right) + query(tree, node * 2 + 1, mid + 1, end, left, right);
}

int main() {
	int N, num;
	long long answer = 0;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		A[num] = i;
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		B.push_back(A[num] + 1);
		initv.push_back(0);
	}

	int h = (int)ceil(log2(N));
	int tree_size = (1 << (h + 1));

	vector<long long> tree(tree_size);
	init(tree, 1, 0, N - 1);
	for (int i = 0; i < N; i++) {
		update(tree, 1, 0, N - 1, B[i] - 1, 1);
		answer += query(tree, 1, 0, N - 1, B[i], N - 1);
	}
	printf("%lld\n", answer);

	return 0;
}
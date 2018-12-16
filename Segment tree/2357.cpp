#include <iostream>
#include <ios>
#include <vector>
#include <cmath>
#include <algorithm>

#define MAX 1000000001

using namespace std;

vector <int > arr;

long long max_init(vector<long long> &tree, int node, int start, int end) {
	if (start == end)
		return tree[node] = arr[start];

	int mid = (start + end) / 2;

	return tree[node] = max(max_init(tree, node * 2, start, mid),max_init(tree, node * 2 + 1, mid + 1, end));
}

long long min_init(vector<long long> &tree, int node, int start, int end) {
	if (start == end)
		return tree[node] = arr[start];

	int mid = (start + end) / 2;

	return tree[node] = min(min_init(tree, node * 2, start, mid), min_init(tree, node * 2 + 1, mid + 1, end));
}

long long max_query(vector<long long> &tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start)
		return -1;

	if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end) / 2;
	return max(max_query(tree, node * 2, start, mid, left, right), max_query(tree, node * 2 + 1, mid + 1, end, left, right));
}

long long min_query(vector<long long> &tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start)
		return MAX;

	if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end) / 2;
	return min(min_query(tree, node * 2, start, mid, left, right), min_query(tree, node * 2 + 1, mid + 1, end, left, right));
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	int num, a, b;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> num;
		arr.push_back(num);
	}

	int h = (int)ceil(log2(N));
	int tree_size = (1 << (h + 1));

	vector <long long > max_tree(tree_size);
	vector <long long > min_tree(tree_size);

	max_init(max_tree, 1, 0, N - 1);
	min_init(min_tree, 1, 0, N - 1);

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		cout << min_query(min_tree, 1, 0, N - 1, a - 1, b - 1) << " " << max_query(max_tree, 1, 0, N - 1, a - 1, b - 1) << "\n";
	}
	return 0;
}
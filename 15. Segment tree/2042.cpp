#include <iostream>
#include <ios>
#include <vector>
#include <cmath>

using namespace std;

vector <int > arr;

long long init(vector<long long> &tree, int node, int start, int end) {
	if (start == end)
		return tree[node] = arr[start];

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

long long query(vector<long long> &tree, int node, int start, int end, int left, int right){
	if (left > end || right < start)
		return 0;

	if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end) / 2;
	return query(tree, node * 2, start, mid, left, right) + query(tree, node * 2 + 1, mid + 1, end, left, right);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, K;
	int num;
	int a, b;
	long long c;

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		cin >> num;
		arr.push_back(num);
	}

	int h = (int)ceil(log2(N));
	int tree_size = (1 << (h + 1));

	vector <long long > tree(tree_size);
	init(tree, 1, 0, N - 1);

	for (int i = 0; i < (M + K); i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(tree, 1, 0, N - 1, b - 1, c - arr[b - 1]);
			arr[b - 1] = c;
		}
		else
			cout << query(tree, 1, 0, N - 1, b - 1, c - 1) << "\n";
	}
	return 0;
}
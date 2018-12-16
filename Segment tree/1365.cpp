#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef pair <int, int > p;

vector <long long > arr;

long long init(vector<long long> &tree, int node, int start, int end) {
	if (start == end)
		return tree[node] = arr[start];

	int mid = (start + end) / 2;

	return tree[node] = init(tree, node * 2, start, mid) + init(tree, node * 2 + 1, mid + 1, end);
}

void update(vector<long long> &tree, int node, int start, int end, int index, long long diff) {
	if (!(start <= index && index <= end))
		return;

	tree[node] = max(tree[node], diff);

	if (start != end) {
		int mid = (start + end) / 2;
		update(tree, node * 2, start, mid, index, diff);
		update(tree, node * 2 + 1, mid + 1, end, index, diff);
	}
}

long long query(vector<long long> &tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start)
		return 0;

	if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end) / 2;
	return max(query(tree, node * 2, start, mid, left, right), query(tree, node * 2 + 1, mid + 1, end, left, right));
}

bool compare(const p &a, const p &b) {
	if (a.first == b.first)
		return a.second > b.second;
	return a.first < b.first;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, num;

	vector <p > v;
	cin >> N;

	for (int i = 0; i < N; i++)
		arr.push_back(0);

	int h = (int)ceil(log2(N));
	int tree_size = (1 << (h + 1));

	vector <long long > tree(tree_size);
	init(tree, 1, 0, N - 1);

	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back({ num,i });
	}

	sort(v.begin(), v.end(),compare);
	for (int i = 0; i < v.size(); i++) {
		long long temp = query(tree, 1, 0, N - 1, 0, v[i].second);
		update(tree, 1, 0, N - 1, v[i].second, temp + 1);
	}
	cout << N-tree[1] << "\n";
	return 0;
}
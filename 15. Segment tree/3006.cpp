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

	tree[node] += diff;

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
	return query(tree, node * 2, start, mid, left, right) + query(tree, node * 2 + 1, mid + 1, end, left, right);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, num;
	vector <p > v;
	cin >> N;

	for (int i = 0; i < N; i++)
		arr.push_back(1);

	int h = (int)ceil(log2(N));
	int tree_size = (1 << (h + 1));

	vector <long long > tree(tree_size);
	init(tree, 1, 0, N - 1);

	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back({ num,i });
	}

	sort(v.begin(), v.end());
	int a = 0, b = N - 1;
	for (int i = 0; i < v.size(); i++) {
		if (i % 2 == 0) {
			cout << query(tree, 1, 0, N - 1, 0, v[a].second) - 1 << "\n";
			update(tree, 1, 0, N - 1, v[a].second, -1);
			a++;
		}
		else {
			cout << query(tree, 1, 0, N - 1, v[b].second, N - 1) - 1 << "\n";
			update(tree, 1, 0, N - 1, v[b].second, -1);
			b--;
		}
	}

	return 0;
}
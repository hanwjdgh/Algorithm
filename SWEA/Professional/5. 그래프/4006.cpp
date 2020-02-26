#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

struct Node {
	int src, dst, weight;
};

bool operator<(Node a, Node b) {
	return (a.weight < b.weight);
}

int T, N, M, ans;
Node node[200001];
int parent[50001], rnk[50001];

void init() {
	ans = 0;

	for (int i = 0; i <= N; i++) {
		parent[i] = i;
		rnk[i] = 0;
	}
}


int find(int i) {
	if (i == parent[i])
		return i;
	return parent[i] = find(parent[i]);
}

void union1(int i, int j) {
	int a = find(i);
	int b = find(j);

	if (a == b)
		return;

	if (rnk[a] < rnk[b])
		parent[a] = b;

	else {
		parent[b] = a;

		if (rnk[a] == rnk[b])
			rnk[a]++;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {

		cin >> N >> M;

		init();

		for (int i = 0; i < M; i++)
			cin >> node[i].src >> node[i].dst >> node[i].weight;

		sort(node, node + M);

		for (int i = 0; i < M; i++) {
			if (find(node[i].src) != find(node[i].dst)) {
				union1(node[i].src, node[i].dst);

				ans += node[i].weight;
			}
		}

		cout << "#" << t_case << " " << ans << "\n";

	}
	return 0;
}
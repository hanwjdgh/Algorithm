#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
	int src, dst, weight;
};

bool operator<(Node a, Node b) {
	return (a.weight < b.weight);
}

int parent[100001];

int find(int x) {
	return parent[x] = parent[x] == x ? x : find(parent[x]);
}

bool union1(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return 0;
	parent[a] = b;
	return 1;
}

int T, V, E, A, B, C;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		vector <Node > v;
		cin >> V >> E;

		for (int i = 0; i < E; i++) {
			cin >> A >> B >> C;

			v.push_back({ A,B,C });
		}

		long long mincost = 0;

		for (int i = 1; i <= V; i++)
			parent[i] = i;

		sort(v.begin(), v.end());

		for (auto n : v) {
			if (union1(n.src, n.dst)) {
				mincost += n.weight;
			}
		}

		cout << "#" << t_case << " " << mincost << "\n";
	}

	return 0;
}
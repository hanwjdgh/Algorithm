#include <iostream>
#include <ios>
#include <vector>
#include <queue>
#include <climits>

#define V 5

using namespace std;

struct Node {
	int dst, weight;
};

bool operator<(Node a, Node b) {
	return (a.weight > b.weight);
}

vector <Node > ad[V];
priority_queue <Node > dist;
bool selected[V];

void add_edge(int node) {
	for (auto n : ad[node])
		dist.push(n);
}

void make_adj(int a, int b, int c) {
	ad[a].push_back({ b,c });
	ad[b].push_back({ a,c });
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	make_adj(0,1,2);
	make_adj(0,3,6);
	make_adj(1,2,3);
	make_adj(1,3,8);
	make_adj(1,4,5);
	make_adj(2,4,7);
	make_adj(3,4,9);

	int mincost = 0, edge_count = 0;

	for (int i = 0; i < V; i++)
		selected[i] = false;

	dist.push({ 0, 0 });

	for (int i = 0; i < V; i++) {
		int now = -1, min_dist = INT_MAX;

		while (!dist.empty()) {
			now = dist.top().dst;

			if (!selected[now]) {
				min_dist = dist.top().weight;
				break;
			}
			dist.pop();
		}

		if (min_dist == INT_MAX)
			continue;

		cout << "Edge " << edge_count++ << " (" << i << "," << now << ")" << " cost : " << min_dist << "\n";

		mincost += min_dist;
		selected[now] = true;
		add_edge(now);
	}

	cout << "Minimum cost = " << mincost << "\n";

	return 0;
}
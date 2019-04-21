#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>
#include <climits>

#define V 5

using namespace std;

struct Node {
	int dst, weight;
};

vector <Node > ad[V];
int dist[V];
bool selected[V];

void make_adj(int a, int b, int c) {
	ad[a].push_back({ b,c });
	ad[b].push_back({ a,c });
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	make_adj(0, 1, 2);
	make_adj(0, 3, 6);
	make_adj(1, 2, 3);
	make_adj(1, 3, 8);
	make_adj(1, 4, 5);
	make_adj(2, 4, 7);
	make_adj(3, 4, 9);

	int mincost = 0, edge_count = 0;

	for (int i = 0; i < V; i++) {
		dist[i] = INT_MAX;
		selected[i] = false;
	}

	dist[0] = 0;
	for (int i = 0; i < V; i++) {
		int now = -1, min_dist = INT_MAX;
		for (int j = 0; j < V; j++) {
			if (!selected[j] && min_dist > dist[j]) {
				min_dist = dist[j];
				now = j;
			}
		}
		if (now < 0)
			continue;

		cout << "Edge " << edge_count++ << " (" << i << "," << now << ")" << " cost : " << min_dist << "\n";

		mincost += min_dist;
		selected[now] = true;
		for (auto n : ad[now])
			dist[n.dst] = min(dist[n.dst], n.weight);
	}

	cout << "Minimum cost = " << mincost << "\n";

	return 0;
}
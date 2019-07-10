#include <iostream>
#include <ios>
#include <queue>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

struct INode {
	int x, y;
};

struct Node {
	int dst;
	double dist;
};

bool operator<(Node a, Node b) {
	return (a.dist > b.dist);
}

INode inode[1001];

bool selected[1001];
int T, N;
double E;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		double mincost = 0, edge_count = 0;
		priority_queue <Node > pq;
		vector <Node > adj[1001];

		cin >> N;

		for (int i = 0; i < N; i++)
			cin >> inode[i].x;

		for (int i = 0; i < N; i++)
			cin >> inode[i].y;

		cin >> E;

		for (int i = 0; i < N; i++)
			selected[i] = false;

		for (int i = 0; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++) {
				double dist = sqrt(pow((inode[i].x-inode[j].x),2) + pow((inode[i].y - inode[j].y), 2));
				adj[i].push_back({ j,dist });
				adj[j].push_back({ i,dist });
			}
		}

		pq.push({ 0,0 });

		for (int i = 0; i < N; i++) {
			int now = -1;
			double min_dist = numeric_limits<double>::max();

			while (!pq.empty()) {
				now = pq.top().dst;

				if (!selected[now]) {
					min_dist = pq.top().dist;
					break;
				}
				pq.pop();
			}

			if (min_dist == numeric_limits<double>::max())
				continue;

			mincost += (min_dist*min_dist);
			selected[now] = true;

			for (auto n : adj[now])
				pq.push(n);
		}

		cout << "#" << t_case << " " << long(round(mincost*E)) << "\n";
	}

	return 0;
}
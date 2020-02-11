#include <iostream>
#include <ios>
#include <queue>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int T, N, M, a, b;
long long c;

struct Node {
	int s, d;
	long long weight;
};

bool cmp(const Node& a, const Node& b) {
	return a.s < b.s;
}

Node node[1000001];
long long dist[200001], value[200001];
int inQ[200001], starting[200002];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		long long ans = 0;
		queue <int > q;

		cin >> N >> M;

		for (int i = 1; i <= N; i++) {
			dist[i] = numeric_limits<long long>::max();
			value[i] = 0;
			inQ[i] = 0;
		}

		for (int i = 0; i < 2 * M; i += 2) {
			cin >> node[i].s >> node[i].d >> node[i].weight;

			node[i + 1].s = node[i].d;
			node[i + 1].d = node[i].s;
			node[i + 1].weight = node[i].weight;
		}

		sort(node, node + 2 * M, cmp);

		int prev = 0;
		for (int i = 0; i < 2 * M; i++) {
			if (prev != node[i].s)
				starting[node[i].s] = i;
			prev = node[i].s;
		}
		starting[N + 1] = 2 * M;

		q.push(1);
		dist[1] = 0;
		inQ[1] = 1;
		
		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			inQ[cur] = 0;
			for (int i = starting[cur]; i < starting[cur + 1]; i++) {
				int next = node[i].d;
				long long n_val = node[i].weight + dist[cur];

				if (n_val < dist[next]) {
					dist[next] = n_val;
					value[next] = node[i].weight;

					if (!inQ[next]) {
						inQ[next] = 1;
						q.push({ next });
					}
				}
				else if (n_val == dist[next])
					value[next] = (value[next] > node[i].weight) ? node[i].weight : value[next];
			}
		}

		for (int i = 2; i <= N; i++)
			ans += value[i];

		cout << "#" << t_case << " " << ans << "\n";
	}

	return 0;
}
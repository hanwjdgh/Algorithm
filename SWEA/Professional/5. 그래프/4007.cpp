#include <iostream>
#include <ios>
#include <queue>
#include <algorithm>

#define MAX 10000000

using namespace std;

struct Node {
	int s, e, t;
};

bool cmp(const Node& A, const Node& B) {
	return (A.s < B.s);
}

Node adj[500001], radj[500001];
int T, N, M, X, s, e, t, ans;
int dist[50001], rdist[50001];
int inQ[50001], starting[50001];

void init() {
	ans = 0;

	for (int i = 1; i <= N; i++)
		dist[i] = rdist[i] = MAX;
}

void SPFA(Node* adj, int* dist) {
	queue <int > q;

	for (int i = 1; i <= N; i++)
		inQ[i] = starting[i] = 0;

	int prev = 0;
	for (int i = 0; i < M; i++) {
		if (prev != adj[i].s)
			starting[adj[i].s] = i;
		prev = adj[i].s;
	}
	starting[N + 1] = M;

	q.push(X);
	dist[X] = 0;
	inQ[X] = 1;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		inQ[cur] = 0;

		for (int i = starting[cur]; i < starting[cur + 1]; i++) {
			int next = adj[i].e, next_val = adj[i].t + dist[cur];

			if (next_val < dist[next]) {
				dist[next] = next_val;

				if (!inQ[next]) {
					inQ[next] = 1;
					q.push(next);
				}
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		cin >> N >> M >> X;

		init();

		for (int i = 0; i < M; i++) {
			cin >> s >> e >> t;

			adj[i].s = radj[i].e = s;
			adj[i].e = radj[i].s = e;
			adj[i].t = radj[i].t = t;
		}

		sort(adj, adj + M, cmp);
		sort(radj, radj + M, cmp);

		SPFA(adj, dist);
		SPFA(radj, rdist);

		for (int i = 1; i <= N; i++)
			ans = max(ans, dist[i] + rdist[i]);

		cout << "#" << t_case << " " << ans << "\n";

	}
	return 0;
}
#include <iostream>
#include <ios>
#include <vector>
#include <limits>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

typedef pair <int, int > p;

vector < vector<p> > adj, radj;
vector <int > dist;
int N, M, S, D;

void dijkstra(int s, int f) {
	priority_queue< p, vector<p>, greater<p> > pq;
	dist = vector <int >(N, numeric_limits<int>::max());
	dist[s] = 0;

	pq.push({ 0,s });
	while (!pq.empty()) {
		p temp = pq.top();
		int dis = temp.first;
		int cur = temp.second;
		pq.pop();

		if (dis > dist[cur])
			continue;
		for (auto next : adj[cur]) {
			int v = next.first;
			int n_dis = next.second;
			if (n_dis == -1)
				continue;
			if (n_dis + dis < dist[v]) {
				dist[v] = n_dis + dis;
				pq.push({ n_dis + dis, v });
			}
		}
	}
}

void bfs(int s, int f) {
	queue <int > q;

	q.push(f);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == s)
			continue;

		for (auto next : radj[cur]) {
			int v = next.first;
			int n_dis = next.second;

			if (dist[cur] == dist[v] + n_dis) {
				for (int i = 0; i < (int)adj[v].size(); i++) {
					if (adj[v][i].first == cur)
						adj[v][i].second = -1;
				}
				q.push(v);
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		cin >> N >> M;
		if (N == 0 && M == 0)
			break;
		cin >> S >> D;

		adj.resize(N);
		radj.resize(N);
		int a, b, c;
		for (int i = 0; i < M; i++) {
			cin >> a >> b >> c;
			adj[a].push_back({ b,c });
			radj[b].push_back({ a,c });
		}
		dijkstra(S, D);
		bfs(S, D);
		dijkstra(S, D);

		if (dist[D] == numeric_limits<int>::max())
			cout << "-1" << "\n";
		else
			cout << dist[D] << "\n";
		adj.clear();
		radj.clear();
	}
	return 0;
}
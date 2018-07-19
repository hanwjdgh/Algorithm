#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>
#include <functional>

using namespace std;

typedef pair <int, int> p;

p tmp;
vector <p > adj[1001];
int N;

long long dijkstra(int s, int f) {
	priority_queue< p, vector<p>, greater<p> > pq;
	vector <int > dist(N + 1, numeric_limits<int>::max());
	dist[s] = 0;

	pq.push(make_pair(0, s));
	while (!pq.empty()) {
		tmp = pq.top();
		int c = tmp.first;
		int u = tmp.second;
		pq.pop();

		if (c > dist[u])
			continue;
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i].first;
			int co = adj[u][i].second + c;
			if (co < dist[v]) {
				dist[v] = co;
				pq.push(make_pair(co, v));
			}
		}
	}
	return dist[f];
}

int main() {
	int E, v1, v2;
	int a, b, c;

	cin >> N >> E;

	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(b, c));
		adj[b].push_back(make_pair(a, c));
	}
	cin >> v1 >> v2;
	long long ans1 = dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, N);
	long long ans2 = dijkstra(1, v2) + dijkstra(v2, v1) + dijkstra(v1, N);
	printf("%lld", (min(ans1, ans2) >= numeric_limits<int>::max()) ? -1 : min(ans1, ans2));
	return 0;
}
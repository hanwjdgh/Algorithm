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

int dijkstra(int s, int f) {
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
		if (u == f)
			return dist[f];
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
	int M, X, max_v=0;
	int a, b, c;

	cin >> N >> M >> X;

	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(b, c));
	}
	for (int i = 1; i <= N; i++) 
		max_v = max(max_v, dijkstra(i, X) + dijkstra(X, i));
	cout << max_v;
	return 0;
}
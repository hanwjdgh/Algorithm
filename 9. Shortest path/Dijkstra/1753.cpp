#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>
#include <functional>

using namespace std;

typedef pair <int, int> p;

priority_queue< p, vector<p>, greater<p> > pq;
p tmp;
vector <p > adj[20001];

int main() {
	int V, E,K;
	int a, b, c;

	cin >> V >> E >> K;

	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(b, c));
	}
	vector <int > dist(V+1, numeric_limits<int>::max());
	dist[K] = 0;

	pq.push(make_pair(0,K));
	while (!pq.empty()) {
		tmp = pq.top();
		int c = tmp.first;
		int u = tmp.second;
		pq.pop();

		if(c>dist[u])
			continue;
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i].first;
			int co = adj[u][i].second+c;
			if (co < dist[v]) {
				dist[v] = co;
				pq.push(make_pair(co,v));
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		if (dist[i] == numeric_limits<int>::max()) {
			cout << "INF" << endl;
			continue;
		}
		cout << dist[i] << endl;
	}
	return 0;
}
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
vector <p > adj[1001];

int main() {
	int n, m, s, f;
	int a, b, c;

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(b, c));
	}
	cin >> s >> f;
	vector <int > dist(n+1, numeric_limits<int>::max());
	dist[s] = 0;

	pq.push(make_pair(0,s));
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
	for (int i = 1; i <= n; i++) {
		if(i==f)
			cout << dist[i] << endl;
	}
	return 0;
}
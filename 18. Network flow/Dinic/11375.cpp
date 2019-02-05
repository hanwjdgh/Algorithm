#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

#define MAX 2002
#define INF 1000000000

using namespace std;

int c[MAX][MAX] = { 0, }, f[MAX][MAX] = { 0, };
int level[MAX], work[MAX];
vector <int > adj[MAX];

int s = 0, t = 2001;

bool bfs() {
	fill(level, level + MAX, -1);
	level[s] = 0;

	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		for (int next : adj[curr]) {
			if (level[next] == -1 && c[curr][next] - f[curr][next] > 0) {
				level[next] = level[curr] + 1;
				q.push(next);
			}
		}
	}
	return level[t] != -1;
}

int dfs(int curr, int dest, int flow) {
	if (curr == dest)
		return flow;

	for (int &i = work[curr]; i<adj[curr].size(); i++) {
		int next = adj[curr][i];
		if (level[next] == level[curr] + 1 && c[curr][next] - f[curr][next] > 0) {
			int df = dfs(next, dest, min(c[curr][next] - f[curr][next], flow));
			if (df > 0) {
				f[curr][next] += df;
				f[next][curr] -= df;
				return df;
			}
		}
	}
	return 0;
}

int main() {
	int N, M, si, num;
	int count = 0;

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		adj[s].push_back(i);
		adj[i].push_back(s);
		c[s][i] = 1;
	}

	for (int i = 1; i <= N; i++) {
		cin >> si;
		for (int j = 0; j < si; j++) {
			cin >> num;
			adj[i].push_back(num + 1000);
			adj[num + 1000].push_back(i);
			c[i][num + 1000] = 1;
			adj[num + 1000].push_back(t);
			adj[t].push_back(num + 1000);
			c[num + 1000][t] = 1;
		}
	}

	int total = 0;
	while (bfs()) {
		fill(work, work + MAX, 0);
		while (1) {
			int flow = dfs(s, t, INF);
			if (flow == 0)
				break;
			total += flow;
		}
	}
	printf("%d\n", total);
	return 0;
}
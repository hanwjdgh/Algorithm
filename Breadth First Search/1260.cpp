#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int visit[1001] = { 0, };
queue <int > q;
vector <int > adj[1001];

void dfs(int x) {
	printf("%d ", x);
	for (int i = 0; i < adj[x].size(); i++) {
		if (!visit[adj[x][i]]) {
			visit[adj[x][i]] = 1;
			dfs(adj[x][i]);
		}
	}
}

void bfs(int x) {
	q.push(x);
	visit[x] = 1;
	while (!q.empty()) {
		int a = q.front();
		q.pop();
		printf("%d ", a);
		for (int i = 0; i < adj[a].size(); i++) {
			if (!visit[adj[a][i]]) {
				visit[adj[a][i]] = 1;
				q.push(adj[a][i]);
			}
		}
	}
}

int main() {
	int N, M, V;
	int a, b;

	scanf("%d %d %d", &N, &M, &V);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= N; i++)
		sort(adj[i].begin(), adj[i].end());

	visit[V] = 1;
	dfs(V);
	printf("\n");
	fill(visit, visit + 1001, 0);
	bfs(V);
	printf("\n");
	return 0;
}
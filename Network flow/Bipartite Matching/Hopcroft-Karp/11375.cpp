#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 1001
#define INF 1000000000

using namespace std;

int N, A[MAX], B[MAX], dist[MAX];
bool used[MAX];
vector <int > adj[MAX];

void bfs() {
	queue<int> Q;
	for (int i = 1; i <= N; i++) {
		if (!used[i]) {
			dist[i] = 0;
			Q.push(i);
		}
		else
			dist[i] = INF;
	}

	while (!Q.empty()) {
		int a = Q.front();
		Q.pop();
		for (int b : adj[a]) {
			if (B[b] != -1 && dist[B[b]] == INF) {
				dist[B[b]] = dist[a] + 1;
				Q.push(B[b]);
			}
		}
	}
}

bool dfs(int a) {
	for (int b : adj[a]) {
		if (B[b] == -1 || (dist[B[b]] == dist[a] + 1 && dfs(B[b]))) {
			used[a] = true;
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

int main() {
	int M, si, a, b;
	int count = 0;

	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &a);
		for (int j = 0; j < a; j++) {
			scanf("%d", &b);
			adj[i].push_back(b);
		}
	}

	fill(A, A + MAX, -1);
	fill(B, B + MAX, -1);
	while (1) {
		bfs();
		int flow = 0;
		for (int i = 1; i <= N; i++)
			if (!used[i] && dfs(i))
				flow++;
		if (flow == 0)
			break;
		count += flow;
	}
	printf("%d\n", count);
	return 0;
}
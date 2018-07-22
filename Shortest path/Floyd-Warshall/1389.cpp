#include <iostream>
#include <cstdio>
#include <algorithm>

#define INF 1000000000

using namespace std;

int main() {
	int n, m;
	int a, b;
	int graph[101][101];

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			graph[i][j] = i == j ? 0 : INF;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a][b] = graph[b][a] = 1;
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				graph[i][j] = min(graph[i][k] + graph[k][j], graph[i][j]);
			}
		}
	}
	int idx = 0, min = INF;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			if (graph[i][j] == INF)
				graph[i][j] = 0;
			sum += graph[i][j];
		}
		if (min > sum) {
			min = sum;
			idx = i;
		}
	}
	cout << idx;
	return 0;
}
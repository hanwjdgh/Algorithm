#include <iostream>
#include <cstdio>
#include <algorithm>

#define INF 1000000000

using namespace std;

int main() {
	int n, m;
	int a, b, c;
	int graph[101][101];

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			graph[i][j] = i == j ? 0 : INF;

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		graph[a][b] = min(graph[a][b], c);
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				graph[i][j] = min(graph[i][k] + graph[k][j], graph[i][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (graph[i][j] == INF)
				graph[i][j] = 0;
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
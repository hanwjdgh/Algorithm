#include <iostream>
#include <cstdio>
#include <algorithm>

#define INF 1000000000

using namespace std;

int main() {
	int n, m, k;
	int a, b;
	int graph[401][401];

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			graph[i][j] = i == j ? 0 : INF;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a][b] = 1;
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				graph[i][j] = min(graph[i][k] + graph[k][j], graph[i][j]);
			}
		}
	}

	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		if (graph[a][b] == INF && graph[b][a] == INF)
			cout << "0" << endl;
		else if (graph[a][b] != INF && graph[a][b] > 0)
			cout << "-1" << endl;
		else
			cout << "1" << endl;

	}
	return 0;
}
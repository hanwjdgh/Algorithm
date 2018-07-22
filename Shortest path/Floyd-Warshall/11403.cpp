#include <iostream>
#include <cstdio>
#include <algorithm>

#define INF 1000000000

using namespace std;

int main() {
	int n;
	int graph[101][101];

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 0)
				graph[i][j] = INF;
		}
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
			if (graph[i][j] != INF)
				graph[i][j] = 1;
			else
				graph[i][j] = 0;
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <limits>
#include <algorithm>

using namespace std;

int main() {
	int V, E;
	int a, b, c, min_val = numeric_limits<int>::max();
	int graph[401][401] = { 0, };

	scanf("%d %d", &V, &E);

	for (int i = 1; i <= V; i++)
		for (int j = 1; j <= V; j++)
			graph[i][j] = numeric_limits<int>::max();
	
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &a, &b, &c);
		graph[a][b] = c;
	}

	for (int k = 1; k <= V; ++k) {
		for (int i = 1; i <= V; ++i) {
			for (int j = 1; j <= V; ++j) {
				if (graph[i][k] != numeric_limits<int>::max() && graph[k][j] != numeric_limits<int>::max())
					graph[i][j] = min(graph[i][k] + graph[k][j], graph[i][j]);
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++)
			if (i == j) 
				min_val = min(min_val, graph[i][j]);		
	}
	if (min_val == numeric_limits<int>::max())
		printf("-1");
	else
		printf("%d", min_val);
	return 0;
}
#include <iostream>
#include <cstdio>

using namespace std;

int map[101][101];
int visit[101][101] = { 0, };
int N;

void dfs(int t, int x, int y) {
	map[t][y] = 1;
	visit[t][y] = 1;
	for (int i = 0; i < N; i++) {
		if (!visit[t][i] && map[y][i])
			dfs(t, y, i);
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			scanf("%d",&map[i][j]);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visit[i][j] && map[i][j])
				dfs(i, i, j);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf("%d ", map[i][j]);
		printf("\n");
	}
	return 0;
}
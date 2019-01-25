#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };
int map[51][51];
int M, N, K;

void dfs(int x, int y) {
	map[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i], ty = y + dy[i];
		if (tx >= 0 && tx < N && ty >= 0 && ty < M && map[tx][ty])
			dfs(tx, ty);
	}
}

int main() {
	int T, cnt = 0;

	int a, b;

	scanf("%d", &T);

	while (T--) {
		cnt = 0;
		memset(map, 0, sizeof(map));
		scanf("%d %d %d", &N, &M, &K);
		while (K--) {
			scanf("%d %d", &a, &b);
			map[a][b] = 1;
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j]) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };
int map[101][101];
int M, N, K;
int cnt;

void dfs(int x, int y) {
	map[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i], ty = y + dy[i];
		if (tx >= 1 && tx <= N && ty >= 1 && ty <= M && map[tx][ty]) {
			cnt++;
			dfs(tx, ty);	
		}
	}
}

int main() {
	int max_val = 0;
	int a, b;

	memset(map, 0, sizeof(map));
	scanf("%d %d %d", &N, &M, &K);
	while (K--) {
		scanf("%d %d", &a, &b);
		map[a][b] = 1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j]) {
				cnt = 1;
				dfs(i, j);
				max_val = max(max_val, cnt);
			}
		}
	}
	printf("%d\n", max_val);
	return 0;
}
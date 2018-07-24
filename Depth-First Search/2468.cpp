#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };
int map[101][101];
int visit[101][101] = { 0, };
int N;

void dfs(int x, int y) {
	visit[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i], ty = y + dy[i];
		if (tx >= 0 && tx < N && ty >= 0 && ty < N && !visit[tx][ty] && map[tx][ty]>0) {
			dfs(tx, ty);
		}
	}
}

int main() {
	int cnt, max_val = 0;
	int max_h = 0;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			max_h = max(max_h, map[i][j]);
		}
	}

	int val = 0;
	for (int i = 0; i <= max_h; i++) {
		for (int a = 0; a < N; a++)
			for (int b = 0; b < N; b++)
				map[a][b] -= val;
		cnt = 0;
		memset(visit, 0, sizeof(visit));
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				if (!visit[a][b] && map[a][b] > 0) {
					cnt++;
					dfs(a, b);
				}
			}
		}
		max_val = max(max_val, cnt);
		val = 1;
	}
	printf("%d\n", max_val);
	return 0;
}
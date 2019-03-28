#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

int map[501][501], visit[501][501];
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N, M, max_v;

void dfs(int y, int x, int cnt, int val) {
	if (cnt == 4) {
		max_v = max(max_v, val);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int ny = y + dir[i][0], nx = x + dir[i][1];

		if (ny < 0 || nx < 0 || ny >= N || nx >= M || visit[ny][nx])
			continue;

		visit[ny][nx] = 1;
		dfs(ny, nx, cnt + 1, val + map[ny][nx]);
		visit[ny][nx] = 0;
	}
}

void cal(int y, int x, int val) {
	for (int i = 0; i < 4; i++) {
		int cnt = 0, hap = val;
		for (int j = 0; j < 4; j++) {
			if (i == j)
				continue;

			int ny = y + dir[j][0], nx = x + dir[j][1];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M)
				continue;

			hap += map[ny][nx];
			cnt++;
		}
		if (cnt == 3)
			max_v = max(max_v, hap);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			cin >> map[y][x];

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			visit[y][x] = 1;
			dfs(y, x, 0, 0);
			visit[y][x] = 0;
		}
	}

	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			cal(y, x, map[y][x]);

	cout << max_v << "\n";

	return 0;
}
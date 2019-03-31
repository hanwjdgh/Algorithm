#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

int dir[4][2] = { { 1,-1 },{ 1,1 },{ -1,1 },{ -1,-1 } };
int map[21][21], visit[21][21], dessert[101];
int N, max_v;

void dfs(int sy, int sx, int y, int x, int d, int cnt) {
	if (d == 4)
		return;

	int ny = y + dir[d][0], nx = x + dir[d][1];

	if (ny < 0 || nx < 0 || ny >= N || nx >= N)
		return;

	if (visit[ny][nx] || dessert[map[ny][nx]]) {
		if (sy == ny && sx == nx) 
			max_v = max(max_v, cnt);
		return;
	}

	visit[ny][nx] = dessert[map[ny][nx]] = 1;
	dfs(sy, sx, ny, nx, d, cnt + 1);
	dfs(sy, sx, ny, nx, d+1, cnt + 1);
	visit[ny][nx] = dessert[map[ny][nx]] = 0;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		cin >> N;

		max_v = -1;
		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
				cin >> map[y][x];

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				visit[y][x] = dessert[map[y][x]] = 1;
				dfs(y, x, y, x, 0, 1);
				visit[y][x] = dessert[map[y][x]] = 0;
			}
		}

		cout << "#" << t_case << " " << max_v << "\n";
	}

	return 0;
}

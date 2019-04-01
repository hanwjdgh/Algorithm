#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

int dir[4][2] = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } };
int map[9][9], visit[9][9];
int N, K, ans;

void dfs(int y, int x, int cnt, int chk) {
	ans = max(ans, cnt);

	for (int i = 0; i < 4; i++) {
		int ny = y + dir[i][0], nx = x + dir[i][1];

		if (ny < 0 || nx < 0 || ny >= N || nx >= N || visit[ny][nx]) 		
			continue;

		if (map[y][x] > map[ny][nx]) {
			visit[ny][nx] = 1;
			dfs(ny, nx, cnt + 1, chk);
			visit[ny][nx] = 0;
		}

		else {
			for (int j = 1; j <= K; j++) {
				if (!chk && map[ny][nx] - j < map[y][x]) {
					visit[ny][nx] = 1;
					map[ny][nx] -= j;
					dfs(ny, nx, cnt + 1,1);
					map[ny][nx] += j;
					visit[ny][nx] = 0;
				}
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int max_val = 0;
		ans = 0;

		cin >> N >> K;

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				cin >> map[y][x];
				max_val = max(max_val, map[y][x]);
			}
		}

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (map[y][x] == max_val) {
					visit[y][x] = 1;
					dfs(y, x, 1, 0);
					visit[y][x] = 0;
				}
			}
		}

		cout << "#" << t_case << " " << ans << "\n";
	}

	return 0;
}
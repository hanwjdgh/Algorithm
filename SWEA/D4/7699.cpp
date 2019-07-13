#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

int T, ans, R, C;
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int alpha[26], visit[21][21];
char board[21][21];

void dfs(int y, int x, int cnt) {
	ans = max(ans, cnt);

	alpha[board[y][x] - 'A'] = 1;
	visit[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dir[i][0], nx = x + dir[i][1];
		if (ny < 0 || nx < 0 || ny >= R || nx >= C || visit[ny][nx] || alpha[board[ny][nx] - 'A'])
			continue;
		dfs(ny, nx, cnt + 1);
	}

	alpha[board[y][x] - 'A'] = 0;
	visit[y][x] = 0;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		ans = 0;

		cin >> R >> C;

		for (int y = 0; y < R; y++)
			for (int x = 0; x < C; x++)
				cin >> board[y][x];

		dfs(0, 0, 1);

		cout << "#" << t_case << " " << ans << "\n";

	}

	return 0;
}
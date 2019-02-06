#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

int visit[21][21], alpha[26];
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
char board[21][21];
int R, C, max_v;

void dfs(int x, int y, int cnt) {
	max_v = max(max_v, cnt);

	alpha[board[x][y] - 'A'] = 1;
	visit[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dir[i][0], ny = y + dir[i][1];
		if (nx < 0 || ny < 0 || nx >= R || ny >= C || visit[nx][ny] || alpha[board[nx][ny] - 'A'])
			continue;
		dfs(nx, ny, cnt + 1);
	}

	alpha[board[x][y] - 'A'] = 0;
	visit[x][y] = 0;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> R >> C;

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> board[i][j];

	dfs(0, 0, 1);

	cout << max_v << "\n";

	return 0;
}